//
// Created by kirill on 06.12.2020.
//

#pragma once

#include "interpreter.h"
#include <map>
#include <queue>
#include <mutex>
#include <../include/logger.h>



class LibData
{
public:
    static std::map<uint, Interpreter> global_interpreter_pool;
    static Logger logger;
};
