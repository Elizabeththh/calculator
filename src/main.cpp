/*
         |-----------------------|
         |                       |
         |   simple calculator   |
         |    Release v0.1 :-)   |
         |                       |
         |-----------------------|
*/

// a simple calculator based on command line
// the calculation logic of this calculator is based on
// both the operation numbers are positive
// if not the case, perform equivalent conversion to other case
// so the functions can be used repeatedly

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

int main()
{
    cout <<"Calculator that supports four arithmetic operations(for now). Developed by Elizabeththh (v0.1)" << endl;
    cout << endl;

    cout << "Enter 'q' to quit" << endl;
    cout << "Enter any other character to continue" << endl;
    cout << "WARNING: you could enter ONLY ONE CHARACTER or unexpected error will occur" << endl;
    
    int flag{};
    flag = cin.get();
    // flush the enter in buffer

    cin.ignore();
    while(flag != 'q')
    {
        // get the output method
        char method = get_notation();
        
        // get the first number
        string first_num = get_num();
        
        // get the operation symbol;
        string op = get_operator();
        
        // get the second number
        string second_num = get_num();

        // get the precision
        long long precision = -1;
        if (method == 'e')  precision = get_prec(); 

        // check if the numbers are negative
        cout << endl;
        string ans;

        //classify addition and subtraction into a few categories
        ans = calculation(first_num, second_num, op, method, precision);

        cout << "The result is " << ans << endl;
        cout << endl;

        cout << "Enter q to quit, enter any other to continue" << endl;
        flag = cin.get();
        cin.ignore();
    }
}
