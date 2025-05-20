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
    string calculation(string, string, string, char, long long);
    
    string get_num();
    string get_operator();
    string get_notation();
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

namespace addition
{
    string floating_point_addition(string, string);
    string integer_addition(string, string);
    string decimal_addition(string, string);
    string reverse_addition(string, string);
}

namespace subtraction
{
    string integer_subtraction(string, string);
    string floating_point_subtraction(string, string);
    string reverse_subtraction(string, string);
    string decimal_subtraction(string, string);
    string bigger_dec_minus_sml_dec(string, string);
} //namespace subtraction

namespace multiplication
{
    string integer_multiplication(string, string);
    string floating_point_multiplication(string, string);
    string reverse_multiplication(string, string);
    
} // namespace multiplication

namespace division
{
    string integer_division(string, string, long long);
    string floating_point_division(string, string, long long);
    string decide_divident(string, string, size_t&, string&);
    string divide(string, string, string&);
}; //namespace division

using namespace calculator;
using namespace addition;
using namespace subtraction;
using namespace multiplication;
using namespace division;

int main()
{
    cout << "a simple calculator" << endl;
    cout << "enter 'q' to quit" << endl;
    cout << "enter other characters to continue" << endl;
    cout << "WARNING: you could enter ONLY ONE CHARACTER or unexpected error will occur" << endl;
    
    int flag{};
    flag = cin.get();
    // flush the enter in buffer

    cin.ignore();
    while(flag != 'q')
    {
        // get the output method
        string method = get_notation();
        
        // get the first number
        string first_num = get_num();
        
        // get the operation symbol;
        string symbol = get_operator();
        
        // get the second number
        string second_num = get_num();

        // get the precision
        long long precision = get_prec();

        // check if the numbers are negative
        cout << endl;
        string ans;

        //classify addition and subtraction into a few categories
        ans = calculation(first_num, second_num, symbol, method[0], precision);

        cout << "The result is " << ans << endl;
        cout << endl;

        cout << "a simple calculator, enter q to quit, enter any other to continue" << endl;
        flag = cin.get();
        cin.ignore();
    }
}

string calculator::calculation(string first_num, string second_num, string symbol, char method, long long precision)
{
    string ans{};
    bool is_first_num_neg = is_neg(first_num);
    bool is_sec_num_neg = is_neg(second_num);
    
    if(symbol[0] == '+' or symbol[0] == '-')
    {
        //first: both numbers are positive 
        if(!is_first_num_neg and !is_sec_num_neg)
        {
            switch(symbol[0])
            {
                case '+':
                {
                    if(is_a_floating_point(first_num) or is_a_floating_point(second_num))
                        ans = floating_point_addition(first_num, second_num);
        
                    else
                        ans = integer_addition(first_num, second_num);

                    break;
                }
                
                case '-':
                {
                    if(is_a_floating_point(first_num) or is_a_floating_point(second_num))
                        ans = floating_point_subtraction(first_num, second_num);

                    else
                    {
                        ans = integer_subtraction(first_num, second_num);
                        calculator::delete_leading_zero(ans);   
                    }
                    break;
                }
                default: ans = "Bug:the switch case fall into default";
            }
        }
        
        //second: the first number is negative, the second is positive
        else if(is_first_num_neg and !is_sec_num_neg)
        {
            to_absolute(first_num);
            switch(symbol[0])
            {
                // this case is equivalent to sec - abs(fir)
                case '+':
                {
                    if(is_a_floating_point(first_num) or is_a_floating_point(second_num))
                        ans = floating_point_subtraction(second_num, first_num);

                    else 
                    {
                        ans = integer_subtraction(second_num, first_num);
                        calculator::delete_leading_zero(ans);
                    }
                    break;
                }

                // this case is equivalent to -(abs(fir) + sec)
                case '-':
                {
                    if(is_a_floating_point(first_num) or is_a_floating_point(second_num))
                        ans = floating_point_addition(first_num, second_num);

                    else 
                        ans = integer_addition(first_num, second_num);
                    
                    // the final ans should be the return value's negative
                    if(ans.at(0) == '-')
                        ans.erase(0, 1);
                    else 
                        ans.insert(ans.begin(), '-');
                    break;

                }
                default: ans = "Bug:the switch case fall into default";break;
            }
        }

        //third: the first number is positive, the second is negative
        else if(!is_first_num_neg and is_sec_num_neg)
        {
            to_absolute(second_num);
            switch(symbol[0])
            {
                //this case is equivalent to fir - abs(sec)
                case '+':
                {
                    if(is_a_floating_point(first_num) or is_a_floating_point(second_num))
                        ans = floating_point_subtraction(first_num, second_num);
                
                    else
                    {
                        ans = integer_subtraction(first_num, second_num);
                        calculator::delete_leading_zero(ans);
                    }    
                    break;
                }

                //this case is equivalent to fir + abs(sec)
                case '-':
                {
                    if(is_a_floating_point(first_num) or is_a_floating_point(second_num))
                        ans = floating_point_addition(first_num, second_num);

                    else 
                        ans = integer_addition(first_num, second_num);
                    
                    break;
                }

                default: ans = "Bug:the switch case fall into default";break;
            }
        }
        
        //fourth: both numbers are negative
        else if(is_first_num_neg and is_sec_num_neg)
        {
            to_absolute(first_num);
            to_absolute(second_num);
            switch(symbol[0])
            {
                // this case is equivalent to -(abs(fir) + abs(sec))
                case '+':
                {
                    if(is_a_floating_point(first_num) or is_a_floating_point(second_num))
                        ans = floating_point_addition(first_num, second_num);
                    
                    else 
                        ans = integer_addition(first_num, second_num);
                        
                    // the final ans should be the return value's negative
                    if(ans.at(0) == '-')
                        ans.erase(0, 1);
                    else 
                        ans.insert(ans.begin(), '-');

                    break;
                }

                // this case is equivalent to abs(sec) - abs(fir)
                case '-':
                {
                    if(is_a_floating_point(first_num) or is_a_floating_point(second_num))
                        ans = floating_point_subtraction(second_num, first_num);
                    
                    else
                    {
                        ans = integer_subtraction(second_num, first_num);
                        calculator::delete_leading_zero(ans);
                    }
                    break;
                }

                default: ans = "Bug:the switch case fall into default";break;
            }
        }
    }
    
    //multiplication and division don't care about the signs when calculating
    else if(symbol[0] == '*' or symbol[0] == '/')
    {
        to_absolute(first_num);
        to_absolute(second_num);

        //the signs of two numbers are the same
        if(is_first_num_neg == is_sec_num_neg)
        {
            switch(symbol[0])
            {
                case '*':
                {
                    if(is_a_floating_point(first_num) or is_a_floating_point(second_num))
                        ans = floating_point_multiplication(first_num, second_num);
                    
                    else
                        ans = integer_multiplication(first_num, second_num);
                    break;
                }

                case '/':
                {
                    if(is_a_floating_point(first_num) or is_a_floating_point(second_num))
                        ans = floating_point_division(first_num, second_num, precision);
                    
                    else
                        ans = integer_division(first_num, second_num, precision);
                    
                    break;
                }

                default: ans = "Bug:the switch case fall into default";break;
            }
        }

        else
        {
            if(is_first_num_neg != is_sec_num_neg)
            {
                switch(symbol[0])
                {
                    case '*':
                    {
                        if(is_a_floating_point(first_num) or is_a_floating_point(second_num))
                            ans = floating_point_multiplication(first_num, second_num);
                        
                        else 
                            ans = integer_multiplication(first_num, second_num);
                        
                        break;
                        }
                        
                        case '/':
                        {
                            if(is_a_floating_point(first_num) or is_a_floating_point(second_num))
                                ans = floating_point_division(first_num, second_num, precision);
                            
                            else
                                ans = integer_division(first_num, second_num, precision);
                            
                            break;
                        }
                        default: ans = "Bug:the switch case fall into default";break;
                    }
                }
                if(ans != "0")
                     ans.insert(ans.begin(), '-');
            }
    }
    ans = formatted_output(ans, method);
    
    if(precision != -1 and symbol[0] != '/')
        ans = set_precision(ans, precision, method);
    return ans;
}

// get arithmetic number from user
string calculator::get_num()
{
    cout << endl;
    string num;
    cout << "Warning: invalid input will be identified as zero" << endl;
    cout << "Enter a number: " << endl;
    getline(cin,num);
    if(num.length() == 0 or (num.length() == 1 and !isdigit(num[0])))
        return "0";
    else
        return num;
}

string calculator::get_notation()
{
    cout << endl;
    string method;
    cout << "Choose a method to display result" << endl;
    cout << "'e' for e_method, 'r' for ordinary_method" << endl;
    getline(cin, method);
    return method;
}

// get arithmetic symbol from user
string calculator::get_operator()
{
    cout << endl;
    cout << "Valid symbols includes '+' '-' '*' '/' "<< endl;
    cout << "Enter a symbol: " << endl;
    string symbol;
    // while(1)
    // {
    //     cin >> symbol;
    //     if(symbol != '+' or symbol != '-')
    //     {
    //         cout << "Please enter a valid symbol" << endl;
    //         cin.clear();
    //         cin.ignore(1, EOF);
    //     }
    //     else
    //         break;
    // }
    // cin.ignore(1, EOF);
    getline(cin, symbol);
    return symbol;
}

// this function get the precision the user wants
long long calculator::get_prec()
{
    long long precision{};
    cout << endl;
    cout << "Enter an INTEGER to set the precision you want" << endl;
    cout << "if you are to operate two integers, the precision means";
    cout << "how many digits after the most significant bit you want to discard" << endl;
    cout << "if you are to operate two floating points, the precision means";
    cout << "how many digits after the decimal point you want to reserve" << endl;
    cout << "enter -1 means you don't want to lose precision" << endl;
    cin >> precision;
    cin.ignore(1, EOF);
    return precision;
}

// judge if the number is a floating point
bool calculator::is_a_floating_point(string num)
{
    if(num.find('.') == string::npos)
        return false;
    else 
        return true;
}

// this function judge if a number is zero
bool calculator::is_zero(string num)
{
    if(num == "0" or num == "0.0")
        return true;
        
    for(auto i: num)
    {
        if(isdigit(i) and i > '0')
            return false;
    }
    return true;
}

// delete the leading zero of the correct result
void calculator::delete_leading_zero(string& ans)
{
    size_t length = ans.length();
    size_t i = 0;

    if(length == 1) // if there is only a zero, don't delete it
        return;
    else if(ans[0] == '-')
        i = 1;
        
    for(; i < length; i++)
    {
        if(ans[i] == '-')
            continue;
        if(ans[i] != '0')
            break;
        else
        {
            ans.erase(i,1);
            i--;
        }
    }
    return;
}

// judge if two integer's addition produce a carry
bool calculator::if_carry(string fir, string sec)
{
    size_t maxlength = fir.length() > sec.length() ? fir.length() : sec.length();

    string ans = addition::decimal_addition(fir, sec);
    if(ans.length() > maxlength)
        return true;
    else
        return false;
}

// reverse a floating point
// put the result in a pair, put the before-decimal part into the first
// the rest into the second
pair<string, string> calculator::split_flot(string num)
{
    pair<string, string> splited_num;

    if(!is_a_floating_point(num))
    {
        splited_num.first = num;
        splited_num.second = "0";
        return splited_num;
    }
    auto decimal_pos = num.find('.');
    splited_num.first = num.substr(0,decimal_pos);
    splited_num.second = num.substr(decimal_pos + 1);
    
    return splited_num;
}

// judge if a number is negative
bool calculator::is_neg(string num)
{
    if(num[0] == '-')
        return true;
    else
        return false;
}

// remove the leading '-' of the number string
void calculator::to_absolute(string& fir)
{
    if(fir[0] == '-')
        fir.erase(0, 1);
    return;
}

/*
* compare two integers
* return 1 for fir > sec
* return -1 for fir < sec
* return 0 for fir = sec
*/
int calculator::which_is_bigger(string fir, string sec)
{
    size_t fir_length = fir.length();
    size_t sec_length = sec.length();

    if(fir_length > sec_length)
        return 1;
    else if(fir_length < sec_length)
        return -1;
    else
    {
        for(size_t i{}; i < fir_length; i++)
        {
            if(fir[i] > sec[i])
                return 1;
            else if(fir[i] < sec[i])
                return -1;
        }
        return 0;
    }
}

// this function judge which decimal part is bigger
// return 1 for fir > sec
// return -1 for fir < sec
// return 0 for fir = sec
int calculator::which_dec_is_bigger(string fir, string sec)
{
    size_t fir_length = fir.length();
    size_t sec_length = sec.length();

    string longstr = fir_length >= sec_length ? fir : sec;
    string shortstr = fir_length < sec_length ? fir : sec;
    size_t maxlength = longstr.length();
    size_t minlength = shortstr.length();

    size_t i{};
    for(; i < minlength; i++)
    {
        if(fir[i] > sec[i])
            return 1;
        else if(fir[i] < sec[i])
            return -1;
    }
    while(i < maxlength)
    {
        if(longstr[i] != '0')
        {
            if(longstr == fir)
                return 1;
            else 
                return -1;
        }
        i++;
    }
    return 0;
}

// this function gets the significant digits of a decimal part
// in order to apply decimal part addition
// return 1 for all zero or only one siginificant digit
size_t calculator::get_significant_digits_of_dec(string num)
{
    size_t length = num.length();
    if(length == 1)
        return 1;

    int index = static_cast<int>(length) - 1;
    for(; index >= 0; index--)
    {
        if(num[index] != 0)
            break;
    }
    if(index == -1)
        return 1;
    else
        return index + 1;
}

//this function calculate how many numbers digits of the decimal places offset in string
// return a negative number indicates the decimal places offset to left
// return a positive number indicates the decimal places offset to right
// return zero when it doesn't offset
// the absolute value of the return value is the offset digits
long long calculator::numbers_of_dec_offset(string num)
{
    long long offset{};

    // integers
    if(!is_a_floating_point(num))
        offset = count_digits(num) - 1;

    // floating points
    else
    {
        to_absolute(num);

        auto splited_num = split_flot(num);

        // deciding offset_num based on the integer part
        size_t integer_digits = count_digits(splited_num.first);

        if(integer_digits != 1)
            offset = integer_digits - 1;
            
        else
        {
            if(splited_num.first[0] == '0')
                offset = -1;
            
            else
                offset = 0;
        }
    }

    return offset;
}

// this function count a number's digits excluding sign and decimal point
size_t calculator::count_digits(string num)
{
    to_absolute(num);

    size_t digits = num.length();
    
    if(is_a_floating_point(num))
        digits--;
    
    return digits;
}

// this function counts how many zeros are at the end of a number
// remember that the number passed in was reversed
size_t calculator::count_the_zero_at_the_end(string num)
{
    size_t zero_count{};
    for(auto i: num)
    {
        if(i != '0')
            return zero_count;
        else
            zero_count++;
    }
    return zero_count;
}

// this function removes the zeros at the end of the number
void calculator::remove_end_zeros(string& num)
{
    while(num[0] == '0')
        num.erase(0, 1);
}

// this function format the answer based on the parameter
string calculator::formatted_output(string ans, char method)
{
    if(is_zero(ans))
        return "0";

    
    string modified_ans{ans};
    switch(method)
    {
        case 'r':
            return modified_ans;

        case 'e':
        {
            size_t offset = numbers_of_dec_offset(ans);
            
            modified_ans = e_method(ans, offset);
            return modified_ans;
        }

        default:return modified_ans;
    }
}

// this function format a number into e_method
string calculator::e_method(string ans, long long offset)
{
    string e_suffix = "E" + to_string(offset);
    bool is_nega = is_neg(ans);

    // transform all the number to positive to simplify logic
    if(is_nega)
        to_absolute(ans);
        
    if(!is_a_floating_point(ans))
    {
        if(ans.length() != 1)
            ans.insert(ans.begin() + 1, '.');
    }
    else 
    {
        auto splited_num = split_flot(ans);

        if(splited_num.first.length() == 1)
        {
            if(splited_num.first[0] == '0')
            {
                ans = splited_num.second;
                if(ans.length() != 1)
                    ans.insert(ans.begin() + 1, '.');
            }
            // else offset must be zero
        }
        else
        {
            ans = splited_num.first;
            ans.insert(ans.begin() + 1, '.');
            ans.append(splited_num.second);
        }
    }
    
    if(is_nega)
        ans.insert(ans.begin(), '-');

    ans.append(e_suffix);

    return ans;
}

// this function handles those annoying digits after the decimal points
// just kidding, this function set precision to the answer to specific decimal places
string calculator::set_precision(string ans, long long precision, char method)
{  
    if(precision == -1)
        return ans;
    
    if(method == 'r')
    {
        // r_method integers
        if(!is_a_floating_point(ans))
        {
            long long digits = ans.length();

            if(precision >= digits)
            {
                cout << "the precision you set outweights the digits of the result" << endl;
                return ans;
            }

            else
            {
                string rounded_ans = ans.substr(0, digits - precision);
                size_t filling_zero = precision;
                rounded_ans.append(filling_zero, '0');
                return rounded_ans;
            }
        }
        
        // r_method floating points
        else
        {
            auto splited_num = split_flot(ans);

            if(precision == 0)
                return splited_num.first;
            else
            {
                long long digits_after_dec = splited_num.second.length();
                if(precision >= digits_after_dec)
                    return ans;
                else
                {
                    size_t round_bit = splited_num.second[precision] - '0';
                    if(round_bit <= 4)
                    {
                        splited_num.second.erase(precision, digits_after_dec - precision);
                        ans = splited_num.first + "." + splited_num.second;
                        return ans;
                    }
                    else
                    {
                        splited_num.second = addition::integer_addition(splited_num.second, "1");
                        // if decimal part produces a carry
                        if(splited_num.second.length() > static_cast<size_t>(precision))
                        {
                            splited_num.first = addition::integer_addition(splited_num.first, "1");
                            ans = splited_num.first + ".0";
                            return ans;
                        }
                        else
                        {
                            ans = splited_num.first + "." + splited_num.second;
                            return ans;
                        }
                    }
                }
            }
        }
    }
    else if(method == 'e')
    {
        if(!is_a_floating_point(ans)) 
            return ans;

        size_t e_sym_pos = ans.find('E');
        string e_suffix = ans.substr(e_sym_pos);
        // now ans is suffix-free
        ans.erase(ans.begin() + e_sym_pos, ans.end());

        auto splited_num = split_flot(ans);

        // rounding the whole decimal part
        if(precision == 0)
        {
            if(splited_num.second[0] - '0' <= 4)
                return splited_num.first + e_suffix;
            else
            {
                ans = addition::integer_addition(splited_num.first, "1");
                return ans + e_suffix;
            }    
        }
        // precision not equal to zero
        else
        {
            size_t digits_after_dec = splited_num.second.length();
            if(static_cast<size_t>(precision)>= digits_after_dec)
                return ans + e_suffix;
            else
            {
                size_t round_bit = splited_num.second[precision] - '0';
                string rounded_decimal_part = splited_num.second.substr(0, precision);
                if(round_bit <= 4)
                {
                    ans = splited_num.first + "." + rounded_decimal_part + e_suffix;
                    return ans;
                }
                else
                {
                    rounded_decimal_part = addition::integer_addition(rounded_decimal_part, "1");
                    // the decimal part produce a carry
                    if(rounded_decimal_part.length() > static_cast<size_t>(precision))
                    {
                        splited_num.first = addition::integer_addition(splited_num.first, "1");
                        ans = formatted_output(splited_num.first, 'e');
                        return ans;
                    }
                    else
                    {
                        ans = splited_num.first + "." + rounded_decimal_part + e_suffix;
                        return ans;
                    }
                }
            }
        }
    }
    return ans;
}

// this function move a floating point's decimal point
string calculator::move_dec_point(string ans, long long dec_offset)
{
    auto[int_pt, dec_pt] = split_flot(ans);
    size_t int_pt_len = int_pt.length();
    size_t dec_pt_len = dec_pt.length();
    if(dec_offset == 0)
    {
        ans = int_pt + "." + dec_pt;
        return ans;
    }
    else if(dec_offset > 0)
    {
        if(static_cast<size_t>(dec_offset) < dec_pt_len)
            dec_pt.insert(dec_pt.begin() + dec_offset, '.');
        else if(static_cast<size_t>(dec_offset) > dec_pt_len)
            dec_pt.append(dec_offset - dec_pt_len, '0');
    }
    else
    {
        if(static_cast<size_t>(llabs((dec_offset)) < int_pt_len))
            int_pt.insert(int_pt.begin() + int_pt_len - static_cast<size_t>(llabs(dec_offset)), '.');
        else
        {
            for(size_t i{}; i < static_cast<size_t>(llabs(dec_offset)) - int_pt_len + 1; i++)
                int_pt.insert(int_pt.begin(), '0');
            int_pt.insert(int_pt.begin() + 1, '.');
        }
    }
    ans = int_pt + dec_pt;

    if(!is_a_floating_point(ans))
        delete_leading_zero(ans);
    else
    {
        auto[ans_int_pt, ans_dec_pt] = split_flot(ans);
        delete_leading_zero(ans_int_pt);
        if(ans_int_pt == "")
            ans_int_pt = "0";
        ans = ans_int_pt + "." + ans_dec_pt;
    }
    return ans;
}

// apply addition to two reversed integer
string addition::reverse_addition(string fir, string sec)
{
    string ans;
    
    int carry{};  //the carry produced by every two digit'sum
    int result{}; //the number minus carry from the sum
    size_t length_fir = fir.length();
    size_t length_sec = sec.length();
    auto min_length = min(length_fir, length_sec);

    size_t index{};
    for(;index < min_length; index++)
    {
        int sum = (fir[index] - '0') + (sec[index] - '0') + carry;
        carry = sum / 10;
        result = sum % 10;
        
        ans.append(to_string(result));
    }

    if(index != length_fir)
    {
        for( ;index < length_fir; index++)
        {
            int sum = (fir[index] - '0') + carry;
            carry = sum / 10;
            result = sum % 10;

            ans.append(to_string(result));
        }
    }

    else if(index != length_sec)
    {
        for( ;index < length_sec; index++)
        {
            int sum = sec[index] - '0' + carry;
            carry = sum / 10;
            result = sum % 10;

            ans.append(to_string(result));
        }
    }

    if(carry != 0)
        ans.append(to_string(carry));
    
    reverse(ans.begin(),ans.end());
    // delete_leading_zero(ans);
    return ans;
}

// add two integers
string addition::integer_addition(string fir, string sec)
{
    string ans;
    reverse(fir.begin(), fir.end());
    reverse(sec.begin(), sec.end());
    
    ans = reverse_addition(fir, sec);
    return ans;
}

// handle the decimal part addition of the two numbers
string addition::decimal_addition(string fir, string sec)
{
    string ans;
    size_t fir_length = fir.length();
    size_t sec_length = sec.length();

    if(fir_length == sec_length)
        ans = integer_addition(fir,sec);
    else
    {
        string biggerNum = fir_length > sec_length ? fir : sec;
        string smallerNum = fir_length < sec_length ? fir : sec;

        size_t maxlength = biggerNum.length();
        size_t minlength = smallerNum.length();

        string truncted_left_Num = biggerNum.substr(0,minlength);
        string trunctedNum = biggerNum.substr(minlength, maxlength - minlength);
        ans = integer_addition(truncted_left_Num, smallerNum);
        ans.append(trunctedNum);
    }
    return ans;
}

// add two floating points
string addition::floating_point_addition(string fir, string sec)
{
    string ans;
    auto fir_splited = calculator::split_flot(fir);
    auto sec_splited = calculator::split_flot(sec);
    
    string sum_after_decimal;
    string sum_before_decimal;
    sum_before_decimal = integer_addition(fir_splited.first, sec_splited.first);

    if(calculator::if_carry(fir_splited.second, sec_splited.second))
    {
        sum_after_decimal = decimal_addition(fir_splited.second, sec_splited.second);
        sum_after_decimal.erase(0, 1);

        // add the carry to the sum
        sum_before_decimal = integer_addition(sum_before_decimal, "1");

        //combine two sums
        ans = sum_before_decimal + "." + sum_after_decimal;
    }

    else
    {
        sum_after_decimal = decimal_addition(fir_splited.second, sec_splited.second);

        //combine two sums
        ans = sum_before_decimal + "." + sum_after_decimal;
    }

    return ans; 
}

/*
* inside main, where this function is called, both numbers are preserved to be positive
* whereever this function is called, make sure that the numbers passed in are positive
* besides, this function can decide which number is bigger
* so don't worry the order of the two parameters
* this function can also make sure larger one minus smaller one
* and call delete_leading_zero() to erase the leading zero
* after calling this function to handle INTEGER SUBTRACTION
*/
string subtraction::integer_subtraction(string fir, string sec)
{
    string ans;

    int flag =  calculator::which_is_bigger(fir, sec);

    reverse(fir.begin(), fir.end());
    reverse(sec.begin(), sec.end());

    if(flag == 1)
        ans = reverse_subtraction(fir, sec);
    else if(flag == -1)
    {
        ans = reverse_subtraction(sec, fir);
        // take the opposite of the answer
        ans.insert(ans.begin(), '-');
    }

    else if(flag == 0)
        ans = "0";
    return ans;
}

// return the remainder
// fir is absolutely bigger than sec
// so the difference must be positive
// remember that both string are REVERSED
string subtraction::reverse_subtraction(string fir, string sec)
{
    string ans;

    size_t minlength = sec.length();
    size_t maxlength = fir.length();

    //always non-negative here
    int borrow{};
    int result{};
    size_t i{};
    for(; i < minlength; i++)
    {
        result = (fir[i] - '0' - borrow) - (sec[i] - '0');

        if(result < 0)
        {
            result += 10;
            borrow = 1;
        }
        else
            borrow = 0;
        ans.append(to_string(result));
    }

    while(i < maxlength)
    {
        result = fir[i] - '0' - borrow;
        if(result < 0)
        {
            result += 10;
            borrow = 1;
        }
        else
            borrow = 0;
        ans.append(to_string(result));
        i++;
    }
    reverse(ans.begin(), ans.end());
    // calculator::delete_leading_zero(ans);

    return ans;
}

// apply subtraction to two floating points numbers
// both of the numbers are guarded to be positive
string subtraction::floating_point_subtraction(string fir, string sec)
{
    string ans{};

    auto splited_fir = calculator::split_flot(fir);
    auto splited_sec = calculator::split_flot(sec);

    
    auto diff_before_decimal = integer_subtraction(splited_fir.first, splited_sec.first);
    calculator::delete_leading_zero(diff_before_decimal);

    auto diff_after_decimal = decimal_subtraction(splited_fir.second, splited_sec.second);

    bool int_pt_neg = calculator::is_neg(diff_before_decimal);
    bool dec_pt_neg = calculator::is_neg(diff_after_decimal);

    // both are negative
    if(int_pt_neg and dec_pt_neg)
    {
        diff_after_decimal.erase(0, 1);
        ans = diff_before_decimal + "." + diff_after_decimal;
    }

    // both are positive
    else if(!int_pt_neg and !dec_pt_neg)
        ans = diff_before_decimal + "." + diff_after_decimal;

    // integer part is positive while decimal part is not
    else if(!int_pt_neg and dec_pt_neg)
    {
        if(diff_before_decimal != "0")
        {
            // borrow 1 from the integer part
            diff_before_decimal = integer_subtraction(diff_before_decimal, "1");
            calculator::delete_leading_zero(diff_before_decimal);

            // remove the sign before the string    
            diff_after_decimal.erase(0, 1);

            
            string borrow = "1";
            // to know how many zero should be appended to borrow to complete the subtraction
            size_t size = calculator::get_significant_digits_of_dec(diff_after_decimal);
            borrow.append(size, '0');

            diff_after_decimal = integer_subtraction(borrow, diff_after_decimal);
            // the leading zero should be deleted
            diff_after_decimal.erase(0, 1);

            ans = diff_before_decimal + "." + diff_after_decimal;
        }
        else
        {
            diff_after_decimal.erase(0, 1);
            ans = diff_before_decimal + "." + diff_after_decimal;
            ans.insert(ans.begin(), '-');
        }
    }
    
    // integer part is negative and decimal part is positive
    else if(int_pt_neg and !dec_pt_neg)
    {
        // the absolute value of integer part should minus one
        diff_before_decimal.erase(0, 1);
        diff_before_decimal = integer_subtraction(diff_before_decimal, "1");
        calculator::delete_leading_zero(diff_before_decimal);

        string borrow = "1";
        // to know how many zero should be appended to borrow to complete the subtraction
        size_t size = calculator::get_significant_digits_of_dec(diff_after_decimal);
        borrow.append(size, '0');
        
        diff_after_decimal = integer_subtraction(borrow, diff_after_decimal);
        // the leading zero should be deleted
        diff_after_decimal.erase(0, 1);

        diff_before_decimal.insert(diff_before_decimal.begin(), '-');
        ans = diff_before_decimal + "." + diff_after_decimal;
    }
    return ans;
}

// the return value of this function is the difference of fir and sec
// remember that fir and sec are both positive
string subtraction::decimal_subtraction(string fir, string sec)
{
    string ans{};
    
    size_t fir_length = fir.length();
    size_t sec_length = sec.length();
    if(fir_length == sec_length)
    {
        ans = integer_subtraction(fir, sec);
        return ans;
    }

    int flag = calculator::which_dec_is_bigger(fir, sec);
    // among this case, the length of fir and sec must be different
    if(flag == 0)
        ans = "0";

    else if(flag > 0)
       ans = bigger_dec_minus_sml_dec(fir, sec); 

    else if(flag < 0)
    {
        ans = bigger_dec_minus_sml_dec(sec, fir);
        ans.insert(ans.begin(), '-');    
    }
    return ans;
}

// this function handles a bigger decimal fir minus smaller decimal sec
// and the number of digits of fir is bigger too
// make sure the parameters passed in  always satisfy fir > sec 
string subtraction::bigger_dec_minus_sml_dec(string fir, string sec)
{
    string ans{};

    size_t fir_length = fir.length();
    size_t sec_length = sec.length();

    if(fir_length > sec_length)
        sec.append(fir_length - sec_length, '0');
    else
        fir.append(sec_length - fir_length, '0');

    ans = subtraction::integer_subtraction(fir, sec);
    return ans;
}

/*
* this function handles two positive integers's multiplication
* the positiveness is guarantee by the calculation()'s preprosession
*/
string multiplication::integer_multiplication(string fir, string sec)
{
    string ans{};
    if(calculator::is_zero(fir) or calculator::is_zero(sec))
        return "0";

    string longnum = fir.length() >= sec.length() ? fir : sec;
    string shortnum = fir.length() < sec.length() ? fir : sec;

    reverse(longnum.begin(), longnum.end());
    reverse(shortnum.begin(), shortnum.end());


    ans = reverse_multiplication(longnum, shortnum);
    return ans;
}

// this function handles two reversed integer's multiplication
string multiplication::reverse_multiplication(string longnum, string shortnum)
{
    string ans{};

    char result{}; 
    char carry{};
    size_t cur_pos{};
    char product{};
    size_t end_zero_count{};

   /*
    * end_zero_count is the sum of the zero at the end of this two numbers
    * this zero will be appended to the answer
    * attention here, the string that is passed in was reversed
    */
    end_zero_count += calculator::count_the_zero_at_the_end(longnum);
    end_zero_count += calculator::count_the_zero_at_the_end(shortnum);

    // remove the zeros at the end to simplify multiplication
    calculator::remove_end_zeros(longnum);
    calculator::remove_end_zeros(shortnum);

    size_t shortlen = shortnum.length();    
    size_t longlen = longnum.length();
    for(size_t i{}; i < shortlen; i++)
    {
        cur_pos = i;
        for(size_t j{}; j < longlen; j++)
        {
            // ture if the ans is empty or current position doesn't exist
            if(ans.length() == 0 or (ans.length() != 0 and cur_pos > ans.length() - 1))
            {
                product = static_cast<char>((shortnum[i] - '0') * (longnum[j] - '0') + carry);
                result = product % 10;
                carry = product / 10;
                ans.append(to_string(result));
            }
            
            // the current pos exist
            else
            {  
                product = static_cast<char>((shortnum[i] - '0') * (longnum[j] - '0') + carry);
                product += static_cast<char>(ans[cur_pos] - '0');
                result = product % 10;
                carry = product / 10;
                ans[cur_pos] = result + '0';
            }
            cur_pos++;
        }
        ans.append(to_string(carry));
        carry = 0;
    }
    reverse(ans.begin(), ans.end());
    calculator::delete_leading_zero(ans);

    ans.append(end_zero_count, '0');
    return ans;
}

string multiplication::floating_point_multiplication(string fir, string sec)
{
    string ans{};
    size_t dec_offset{};

    auto splited_fir = calculator::split_flot(fir);
    auto splited_sec = calculator::split_flot(sec);
    
    // count the sum of digits after the decimal point of the two number
    if(!calculator::is_zero(splited_fir.second))
        dec_offset += splited_fir.second.length();
    if(!calculator::is_zero(splited_sec.second))
        dec_offset += splited_sec.second.length();

    // set two numbers to integer to simplify calculation
    string new_fir{};
    string new_sec{};
    if(calculator::is_zero(splited_fir.second))
        new_fir = splited_fir.first;
    else
    {
        size_t fir_dec_pos = fir.find('.');
        fir.erase(fir_dec_pos, 1);
        new_fir = fir;
    }
    if(calculator::is_zero(splited_sec.second))
        new_sec = splited_sec.first;
    else
    {
        size_t sec_dec_pos = sec.find('.');
        sec.erase(sec_dec_pos, 1);
        new_sec = sec;
    }

    ans = integer_multiplication(new_fir, new_sec);

    // moving the decimal point of the answer
    size_t ans_length = ans.length();
    if(ans_length > dec_offset)
        ans.insert(ans.begin() + (ans_length - dec_offset), '.');
    
    else
    {
        for(size_t i{}; i < (dec_offset - ans_length + 1); i++)
            ans.insert(ans.begin(), '0');
        ans.insert(ans.begin() + 1, '.');
    }   

    return ans;
}

// this function calculate the quotient of two integers
string division::integer_division(string fir, string sec, long long prec)
{
    
    // handles special cases
    if(calculator::is_zero(sec))
    {
        cout << "You can't divide a number by 0" << endl;
        return "N/A";
    }
    if(calculator::is_zero(fir))
        return "0";

    if (sec == "1")
        return fir;

    // setting the default precision
    if(prec == -1)
        prec = 20;
    size_t after_dec_digits{};
        
    string ans{};
    string remainder{};
    size_t cur_pos{};
    bool is_added_dec_point{false};
    string divident{};
    string quotient{};
    long long dec_offset{};

    // remove the zero at the end to simplify calculation
    reverse(fir.begin(), fir.end());
    reverse(sec.begin(), sec.end());
    dec_offset += calculator::count_the_zero_at_the_end(fir);
    dec_offset -= calculator::count_the_zero_at_the_end(sec);
    calculator::delete_leading_zero(fir);
    calculator::delete_leading_zero(sec);
    reverse(fir.begin(), fir.end());
    reverse(sec.begin(), sec.end());


    // the main loop for division, one bit of digit per loop
    // calculate one more bit to round
    while(after_dec_digits < static_cast<size_t>(prec + 1))
    {
        divident = decide_divident(fir, sec, cur_pos, remainder);

        quotient = divide(divident, sec, remainder);

        if(remainder == "" and cur_pos != fir.length())
        {
            ans.append(quotient);
            ans.append(fir.length() - cur_pos, '0');
            break;
        }
        else if(remainder == "" and cur_pos == fir.length())
        {
            ans.append(quotient);
            break;
        }
        else
        {
            // if there is a decimal point added, count the digits after decimal point
            if(is_added_dec_point)
                after_dec_digits++;
            ans.append(quotient);
        }

        if(!is_added_dec_point and cur_pos == fir.length())
        {
            ans.append(".");
            is_added_dec_point = true;
        }
    }

    if(!calculator::is_a_floating_point(ans))
        ans = ans + ".0";
    auto[int_pt, dec_pt] = calculator::split_flot(ans);
    calculator::delete_leading_zero(int_pt);
    if(int_pt == "")
        int_pt = "0";
    ans = int_pt + "." + dec_pt;
    
    ans = calculator::move_dec_point(ans, dec_offset);
    return ans;
}

// this function calculates the quocient of two floating points
string division::floating_point_division(string fir, string sec, long long prec)
{
    string ans{};

    auto[fir_int_pt, fir_dec_pt] = calculator::split_flot(fir);
    auto[sec_int_pt, sec_dec_pt] = calculator::split_flot(sec);

    long long dec_offset{};
    
    // moving the meaningless zero in decimal part
    reverse(fir_dec_pt.begin(), fir_dec_pt.end());
    reverse(sec_dec_pt.begin(), sec_dec_pt.end());
    calculator::delete_leading_zero(fir_dec_pt);
    calculator::delete_leading_zero(sec_dec_pt);
    reverse(fir_dec_pt.begin(), fir_dec_pt.end());
    reverse(sec_dec_pt.begin(), sec_dec_pt.end());

    if(!calculator::is_zero(fir_dec_pt))
    {
        dec_offset -= fir_dec_pt.length();
        if(!calculator::is_zero(fir_int_pt))
            fir = fir_int_pt + fir_dec_pt;
        else
        {
            fir = fir_dec_pt;
            calculator::delete_leading_zero(fir);
        }
    }
    else
        fir = fir_int_pt;
    
    if(!calculator::is_zero(sec_dec_pt))
    {
        dec_offset += sec_dec_pt.length();
        if(!calculator::is_zero(sec_int_pt))
            sec = sec_int_pt + sec_dec_pt;
        else
        {
            sec = sec_dec_pt;
            calculator::delete_leading_zero(sec);
        }
    }
    else
        sec = sec_int_pt;

    ans = integer_division(fir, sec, prec);
    ans = calculator::move_dec_point(ans, dec_offset);

    return ans;
}

// this function decide the divident for each division
string division::decide_divident(string fir, string sec, size_t& cur_pos, string& remainder)
{
    string divident{};
    size_t fir_len = fir.length();

    if(cur_pos < fir_len)
    {
        divident = remainder + fir.substr(cur_pos, 1);
        cur_pos++;
    }   

    else
        divident = remainder + "0";
    
    return divident;
}

// this function calculate the quotient of each division
string division::divide(string divident, string sec, string& remainder)
{
    // divident is less than sec
    if(calculator::which_is_bigger(divident, sec) < 0)
    {
        remainder = divident;
        return "0";
    }

    size_t coeff{2};
    string product{};
    // maintain a copy of the previou product
    string prev_product{sec};
    // divident must be greater than sec
    for(; coeff <= 10; coeff++)
    {
        product = multiplication::integer_multiplication(sec, to_string(coeff));
        if(calculator::which_is_bigger(divident, product) == 0)
        {
            remainder = "";
            return to_string(coeff);
        }

        else if(calculator::which_is_bigger(divident, product) < 0)
        {
            remainder = subtraction::integer_subtraction(divident, prev_product);
            if(remainder == "0")
                remainder = "";
            calculator::delete_leading_zero(remainder);
            return to_string(coeff - 1);
        }
        prev_product = product;
    }
    return "something went wrong";
}