#ifndef HELPER_H
#define HELPER_H

#include <iostream>
#include <map>
#include <string>
#include <regex>
#include <cctype>
using namespace std;
using init_params = map<string, string>;

namespace helper
{
    init_params process_params(int argc, char* argv[]);
    init_params identify_flags(int argc, char* argv[]);
    void print_help_infos();
}

#endif