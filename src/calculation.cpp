#include "../lib/calculator.h"
#include "../lib/addition.h"
#include "../lib/subtraction.h"
#include "../lib/multiplication.h"
#include "../lib/division.h"

using namespace std;
using namespace calculator;
using namespace addition;
using namespace subtraction;
using namespace multiplication;
using namespace division;

string calculator::calculation(string first_num, string second_num, string op, char notation, long long precision)
{
    string ans{};
    bool is_first_num_neg = is_neg(first_num);
    bool is_sec_num_neg = is_neg(second_num);
    
    if(op[0] == '+' or op[0] == '-')
    {
        //first: both numbers are positive 
        if(!is_first_num_neg and !is_sec_num_neg)
        {
            switch(op[0])
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
            switch(op[0])
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
            switch(op[0])
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
            switch(op[0])
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
    else if(op[0] == '*' or op[0] == '/')
    {
        to_absolute(first_num);
        to_absolute(second_num);

        //the signs of two numbers are the same
        if(is_first_num_neg == is_sec_num_neg)
        {
            switch(op[0])
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
                switch(op[0])
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
    ans = formatted_output(ans, notation);
    
    if(precision != -1 and op[0] != '/')
        ans = set_precision(ans, precision, notation);
    return ans;
}
