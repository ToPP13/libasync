//
// Created by kirill on 06.12.2020.
//

#pragma once

#include <queue>
#include <map>
#include <mutex>

#include "interpreter.h"
#include "logger.h"



class LibData
{
public:
    static std::map<uint, Interpreter> global_interpreter_pool;
    static Logger logger;
};
