#ifndef CALCULATE_H
#define CALCULATE_H

#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <utility>
#include <ctype.h>

using namespace std;

namespace calculator
{
    string calculation(string, string, string, char, long long);
    
    string get_num();
    string get_operator();
    char get_notation();
    bool is_a_valid_num(string);
    long long get_prec();
    bool is_a_floating_point(string);
    bool if_carry(string, string);
    bool is_zero(string);
    pair<string,string> split_flot(string);
    void delete_leading_zero(string&);
    bool is_neg(string);
    void to_absolute(string&);
    int which_is_bigger(string, string);
    int which_dec_is_bigger(string, string);
    size_t get_significant_digits_of_dec(string);
    size_t count_digits(string);
    long long numbers_of_dec_offset(string);
    size_t count_the_zero_at_the_end(string);
    void remove_end_zeros(string&);
    string formatted_output(string, char = 'r');

    string e_method(string, long long);
    string set_precision(string, long long, char);
    void rounding(string&, size_t);
    string move_dec_point(string, long long);
}

#endif
