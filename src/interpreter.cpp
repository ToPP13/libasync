//
// Created by kirill on 25.11.2020.
//

#include "../include/interpreter.h"
#include "iostream"

Interpreter::Interpreter(uint batch_size):_batch_size(batch_size), _bracket_counter(0)
{
    _mode = Mode::Static;
    _inner_interpreter = std::make_shared<StaticInterpreter>(_batch_size);
}


void Interpreter::process(const std::string & current_cmd) {
    Interpreter::Mode new_mode;
    if (current_cmd == open_bracket) {
        _bracket_counter += 1;
        new_mode = Mode::Dynamic;
    }
    else if (current_cmd == close_bracket) {
        _bracket_counter -= 1;
        if (_bracket_counter == 0)
            new_mode = Mode::Static;
        else
            new_mode = Mode::Dynamic;
    }
    else
    {
        _inner_interpreter->process(current_cmd);
        new_mode = _mode;
    }

    if (_mode == new_mode) {
        return;
    }
    _mode = new_mode;

    if (_mode == Mode::Static)
    {
        _inner_interpreter->stop_processing();
        _inner_interpreter = std::make_shared<StaticInterpreter>(_batch_size);
    }

    if (_mode == Mode::Dynamic)
    {
        _inner_interpreter->stop_processing();
        _inner_interpreter = std::make_shared<DynamicInterpreter>();
    }
}
