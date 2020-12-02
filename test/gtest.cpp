#include <string>
#include <vector>
#include <list>
#include <gtest/gtest.h>
#include "../include/lib.h"

TEST(gtest_version, gtest_version_basic)
{
    ASSERT_GT(version(), 0);
}

TEST(gtest_static_interpreter, gtest_static_interpreter_basic)
{
//    std::vector<std::string> test1 = {"cmd1", "cmd2", "cmd3", "cmd4", "cmd5"};
    std::vector<std::string> test2 = {"cmd1", "cmd2", "{", "cmd3", "cmd4", "}",
                                      "{",  "cmd5", "cmd6", "{", "cmd7", "cmd8", "}", "cmd9", "}",
                                      "{",  "cmd10", "cmd11"};


    int batch_size = 3;
    Interpreter i(batch_size);
    for (const auto & v: test2)
    {
        i.process(v);
    }
}