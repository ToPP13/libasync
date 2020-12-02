//
// Created by kirill on 25.11.2020.
//

#include "../include/commandstorage.h"
#include "iostream"
#include "fstream"


#include <unistd.h>

using std::string;

std::string string_from_int(long num)
{
    std::ostringstream s;
    s << num;
    std::string num_as_string(s.str());
    return num_as_string;
}

bool file_exists (const std::string& name) {
    std::ifstream f(name.c_str());
    return f.good();
}



void CommandStorage::add_command(const string & command)
{
    if (empty())
        set_log_file();
    _commands.emplace_back(command);
}
bool CommandStorage::set_log_file() {
    bool exist = true;
    do
    {
        uint now = time(nullptr);
        _filename = "bulk" + string_from_int(now) + ".log";
        exist = file_exists(_filename);
        sleep(1);
    }
    while (exist);
    std::ofstream f;
    f.open(_filename,std::ios::out);
    if(!f)
        return false;

    f.close();
    return true;
}

bool CommandStorage::log_commands() {
    std::ofstream f;
    f.open(_filename, std::ios::out);
    if (!f) {
        return false;
    }
    f << get_bulk();
    f.close();
    print_bulk();
    return true;
}


std::string CommandStorage::get_bulk() const
{
    std::string result = "bulk: ";
    for (auto iter = _commands.begin(); iter != _commands.end(); iter++) {
        if (iter != _commands.begin())
            result += (", " + *iter);
        else
            result += *iter;
    }
    return result;
}


void CommandStorage::print_bulk() const
{
    std::cout << get_bulk() << std::endl;
}

