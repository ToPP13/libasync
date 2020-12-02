//
// Created by kirill on 25.11.2020.
//

#pragma once

#include <string>
#include "commandstorage.h"

class IBasicInterpreter
{
public:

    IBasicInterpreter() = default;
    virtual void process(std::string current_cmd) = 0;
    virtual void stop_processing() =0;

public:
    CommandStorage _scb;
};
