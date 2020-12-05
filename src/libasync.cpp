#include <iostream>
#include <string>
#include "../include/lib.h"

using std::cout;
using std::endl;



void test(std::vector<std::string> & data_series)
{
    uint batch_size = 3;

    uint new_context = connect(batch_size);

    for (auto test_command : data_series)
    {
        auto buffer = test_command.c_str();
        uint buffer_size = test_command.size();
        recieve(buffer, buffer_size, new_context);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    disconnect(new_context);
}


int main()
{
    std::vector<std::string> testSeries1 = {"cmd1", "cmd2", "cmd3", "cmd4", "cmd5"};
    std::vector<std::string> testSeries2 = {"cmd1", "cmd2", "{", "cmd3", "cmd4", "}",
                                      "{",  "cmd5", "cmd6", "{", "cmd7", "cmd8", "}", "cmd9", "}",
                                      "{",  "cmd10", "cmd11"};

    // test1
    test(testSeries1);
    // test2
    test(testSeries2);

    return 0;
}