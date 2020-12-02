//
// Created by kirill on 25.11.2020.
//

#pragma once

#include "ibasicinterpreter.h"

class StaticInterpreter: public IBasicInterpreter
{
public:
    explicit StaticInterpreter(uint batch_size): _batch_size(batch_size){};
    ~StaticInterpreter();

    void process(std::string current_cmd) override;
    void stop_processing() override;

private:
    uint _batch_size;
};

