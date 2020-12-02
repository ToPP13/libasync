//
// Created by kirill on 25.11.2020.
//

#pragma once

#include <vector>
#include <string>
#include "../include/pretty.h"
#include <sstream>
#include <fstream>


std::string string_from_int(long num);
bool file_exists (const std::string& name);



class CommandStorage {
public:
    CommandStorage() = default;

    virtual void add_command(const std::string & command);
    bool set_log_file();
    bool log_commands();

    bool empty() const{return _commands.empty();};
    void clear(){_commands.clear();};
    uint size() const{return _commands.size();};
    std::string get_bulk() const;
    void print_bulk() const;

    std::string _filename;
    std::vector<std::string> _commands;
};