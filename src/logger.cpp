//
// Created by kirill on 05.12.2020.
//

#include "../include/logger.h"




void Logger::_real_print()
{
    std::cout << "start print!" << std::endl;
    while(printOn)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "printing is active!" << std::endl;
        {
            std::lock_guard<std::mutex> guard{mutex_print};
            if (print_queue.empty())
                continue;

            auto& print_event = print_queue.front();
            print_queue.pop();
            print_event.print();
        }


    }
}

void Logger::_real_log(uint num)
{
    std::cout << "start " << num << " log!" << std::endl;
    while(logOn)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "logging " << num << " is active!" << std::endl;
        {
            std::lock_guard<std::mutex> guard{mutex_log};
            if (log_queue[num].empty())
                continue;

            auto& print_event = log_queue[num].front();
            log_queue[num].pop();
            print_event.print();
        }
    }
}



