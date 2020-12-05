#include "../include/lib.h"
#include "../include/logger.h"
#include "version.h"

int version()
{
    return PROJECT_VERSION_PATCH;
}

Logger logger{};

std::map<uint, Interpreter> LibData::global_interpreter_pool = {};

uint connect(uint batch_size)
{

    if (!logger.is_log_on())
        logger.turn_log_on();

    if (!logger.is_print_on())
        logger.turn_print_on();


    static uint context = 0;
    context += 1;

    Interpreter newInterpreter(batch_size);

    if (LibData::global_interpreter_pool.find(context) != LibData::global_interpreter_pool.end())
        LibData::global_interpreter_pool.erase(context);
    LibData::global_interpreter_pool.insert({context, newInterpreter});

    return context;
}

void recieve(const char * buffer, uint buffer_size, uint context)
{
    std::string command = std::string(buffer, buffer_size);

    std::string res = LibData::global_interpreter_pool[context].process(command);
    if (!res.empty())
        logger.log(res);
}

void disconnect(uint context)
{
    auto int_it = LibData::global_interpreter_pool.find(context);
    if (int_it != LibData::global_interpreter_pool.end())
    {
        std::string res = int_it->second.stop_processing();
        if (!res.empty())
            logger.log(res);

        LibData::global_interpreter_pool.erase(context);
    }
}
