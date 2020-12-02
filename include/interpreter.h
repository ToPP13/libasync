//
// Created by kirill on 25.11.2020.
//

#pragma once

#include "string"
#include "memory"
#include "dynamicinterpreter.h"
#include "staticinterpreter.h"
#include "commandstorage.h"



class Interpreter {
public:
    const std::string open_bracket = "{";
    const std::string close_bracket = "}";

    enum Mode {
        Static,
        Dynamic
    };

    Interpreter(uint batch_size);
    void process(const std::string & current_cmd);


private:
    uint _batch_size;
    uint _bracket_counter;
    Interpreter::Mode _mode;
    std::shared_ptr<IBasicInterpreter> _inner_interpreter;

};