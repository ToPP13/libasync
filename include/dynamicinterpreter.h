//
// Created by kirill on 25.11.2020.
//

#pragma once

#include "ibasicinterpreter.h"


class DynamicInterpreter: public IBasicInterpreter
{
public:
    void process(std::string current_cmd) override;
    void stop_processing() override;

};
