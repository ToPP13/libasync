//
// Created by kirill on 05.12.2020.
//

#pragma once

#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <queue>
#include <atomic>


class LogEvent
{
public:
    LogEvent(std::string msg):message(msg){};
    void print() {
        std::cout << message << std::endl;
    }
    std::string message;
};



class Logger
{
public:
    Logger()
    {
        thread_num = 2;
        for (uint i = 0;i<thread_num;i++)
            log_queue.push_back({});
        turn_print_on();
        turn_log_on();
    }
    ~Logger()
    {
        turn_print_off();
        turn_log_off();
    }


    void log(std::string log_data)
    {
        static uint log_count = 0;

        LogEvent le(log_data);
        {
            std::lock_guard<std::mutex> lockGuard{mutex_log};
            log_queue[thread_num%2].emplace(le);
            log_count = (log_count+1)%2;
        }

        LogEvent pe(log_data);
        {
            std::lock_guard<std::mutex> lockGuard{mutex_print};
            print_queue.emplace(pe);
        }
    }



    void _real_print();
    void _real_log(uint num);


    bool is_print_on(){return printOn;};

    void turn_print_on()
    {
        printOn.store(true);
        m_printThread = std::thread(&Logger::_real_print, this);
    }

    bool is_log_on(){return logOn;};

    void turn_log_on()
    {
        logOn.store(true);
        for (uint i=0;i<thread_num;i++)
            m_log_threads.push_back(std::thread(&Logger::_real_log, this, i));
    }

    void turn_print_off()
    {
        printOn.store(false);
        if (m_printThread.joinable())
            m_printThread.join();
    }


    void turn_log_off()
    {
        logOn.store(false);
        for (uint i=0;i<m_log_threads.size();i++)
        {
            if (m_log_threads[i].joinable())
                m_log_threads[i].join();
        }
        for (uint i=0;i<m_log_threads.size();i++)
            m_log_threads.pop_back();
    }

private:
    std::thread m_printThread;
    std::vector<std::thread> m_log_threads;

    std::atomic<bool> printOn = {};
    std::atomic<bool> logOn = {};

    std::mutex mutex_print;
    std::mutex mutex_log;

    std::queue<LogEvent> print_queue = {};
    std::vector<std::queue<LogEvent>> log_queue;

    uint thread_num;
};

