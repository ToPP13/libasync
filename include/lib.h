#pragma once

#include "interpreter.h"
#include <map>
#include <queue>
#include <mutex>
#include <../include/logger.h>


extern Logger logger;

int version();


class LibData
{
public:
    static std::map<uint, Interpreter> global_interpreter_pool;
};



uint connect(uint batch_size);

void recieve(const char * buffer, uint buffer_size, uint context);

void disconnect(uint context);

