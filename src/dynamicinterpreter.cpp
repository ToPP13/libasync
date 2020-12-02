//
// Created by kirill on 25.11.2020.
//

#include "../include/dynamicinterpreter.h"

void DynamicInterpreter::process(std::string current_cmd)
{
    _scb.add_command(current_cmd);
}

void DynamicInterpreter::stop_processing()
{
    if (!_scb.empty())
    {
        _scb.log_commands();
        _scb.clear();
    }
}