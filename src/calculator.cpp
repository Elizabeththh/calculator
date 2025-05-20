#include "../lib/calculator.h"
#include "../lib/addition.h"
#include "../lib/subtraction.h"

// get arithmetic number from user
string calculator::get_num()
{
    cout << endl;
    string num;
    
    cout << "Enter a number: " << endl;
    
    while(true)
    {
        getline(cin, num);
        if(!is_a_valid_num(num))
        {
            cout << "please enter a valid number: " << endl;
            continue;
        }
        break;
    }
    return num;
}

char calculator::get_notation()
{
    cout << endl;
    char notation;
    cout << "Choose a notation to display result" << endl;
    cout << "'e' for Scientific Notation, 'p' for Plain Number" << endl;

    cin >> notation;

    while (!(notation == 'e' or notation == 'p')) cin >> notation;

    cin.ignore();

    return notation;
}

// get arithmetic symbol from user
string calculator::get_operator()
{
    cout << endl;
    cout << "Valid operators includes '+' '-' '*' '/' "<< endl;
    cout << "Enter a operator: " << endl;
    string op;
    while(true)
    {
        getline(cin, op);
        if(!(op == "+" or op == "-" or op == "*" or op == "/"))
        {
            cout << "Please enter a valid operator:" << endl;
            continue;
        }
        break;
    }
    return op;
}

// this function get the precision the user wants
long long calculator::get_prec()
{
    long long precision{};
    cout << endl;
    cout << "Enter an INTEGER to set the precision you want" << endl;
    cout << "If you are to operate two integers, the precision means";
    cout << "How many digits after the most significant bit you want to discard" << endl;
    cout << "If you are to operate two floating points, the precision means";
    cout << "How many digits after the decimal point you want to reserve" << endl;
    cout << "Enter -1 means you don't want to lose precision except division, and the division precision is 20 by default" << endl;
    cin >> precision;
    cin.ignore(1, EOF);
    return precision;
}

// this function judges if a number is valid
bool calculator::is_a_valid_num(string num)
{
    size_t len = num.length();
    if(len == 0) 
    {
        cout << "len == 0 !!" << endl;
        return false;
    }
    else if(len == 1)
    {
        if(!isdigit(num[0]))
            return false;
    }

    // len >= 2
    else
    {
        if(!(isdigit(num[0]) or num[0] == '-'))
            return false;
        
        for(size_t i{1}; i < len; i++)
        {
            if(!(isdigit(num[i]) or (num[i] == '.' and i != len - 1)))
                return false;
        }
    }
    return true;
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
string calculator::formatted_output(string ans, char notation)
{
    if(is_zero(ans))
        return "0";

    
    string modified_ans{ans};
    switch(notation)
    {
        case 'p':
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
string calculator::set_precision(string ans, long long precision, char notation)
{  
    if(precision == -1)
        return ans;
    
    if(notation == 'r')
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
                        splited_num.second.erase(precision,digits_after_dec - precision);
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
    else if(notation == 'e')
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

/*
* this function move a floating point's decimal point
* dec_offset = 0 indicates the decimal point is right in place
* dec_offset < 0 indicates to move the decimal point to its right
* dec_offset > 0 indicates to move the decimal point to its left
*/
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
        if((static_cast<size_t>(llabs((dec_offset))) < int_pt_len))
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