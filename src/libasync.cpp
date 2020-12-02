#include <iostream>
#include <string>
#include "../include/lib.h"

using std::cout;
using std::endl;


void test(std::vector<std::string> & data_series)
{
    //    const std::string eof = "EOF";
//    uint batch_size = 3;
    // connect
    for (auto test_command : data_series)
    {
        cout << test_command << endl;
        //recieve
    }
    // disconnect
}


int main()
{
    std::vector<std::string> testSeries1 = {"cmd1", "cmd2", "cmd3", "cmd4", "cmd5"};
    std::vector<std::string> testSeries2 = {"cmd1", "cmd2", "{", "cmd3", "cmd4", "}",
                                      "{",  "cmd5", "cmd6", "{", "cmd7", "cmd8", "}", "cmd9", "}",
                                      "{",  "cmd10", "cmd11"};


//    Interpreter i(batch_size);

//    std::string line;
//    std::stringstream streamIn;

    // test1
    test(testSeries1);
    // test2
    test(testSeries2);

    return 0;
}