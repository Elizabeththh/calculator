#ifndef CALCULATE_H
#define CALCULATE_H

#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <cstdio>
#include <iostream>
#include <utility>
#include <ctype.h>

using namespace std;

namespace calculator
{
    string calculation(string, string, string);
    
    string get_num();
    string get_symbol();
    bool is_a_floating_point(string);
    bool if_carry(string, string);
    pair<string,string> split_flot(string);
    void delete_leading_zero(string&);
    bool is_neg(string);
    void to_absolute(string&);
    int which_is_bigger(string, string);
    int which_dec_is_bigger(string, string);
    size_t get_significant_digits_of_dec(string);
}

#endif
