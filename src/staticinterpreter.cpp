//
// Created by kirill on 25.11.2020.
//

#include "../include/staticinterpreter.h"


StaticInterpreter::~StaticInterpreter()
{
    if (!_scb.empty())
    {
        _scb.log_commands();
        _scb.clear();
    }
}

void StaticInterpreter::process(std::string current_cmd)
{
    _scb.add_command(current_cmd);
    if (_scb.empty())
    {
        _scb.set_log_file();
    }
    if (_scb.size() == _batch_size)
    {
        _scb.log_commands();
        _scb.clear();
    }
}

void StaticInterpreter::stop_processing()
{
    if (!_scb.empty())
    {
        _scb.log_commands();
        _scb.clear();
    }
}
