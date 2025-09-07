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
#include "../lib/helper.h"

using namespace std;
using namespace calculator;
using namespace addition;
using namespace subtraction;
using namespace multiplication;
using namespace division;
using namespace helper;

int main(int argc, char* argv[])
{
    init_params params = process_params(argc, argv);
    string ans{""};
    if(params.empty())
        return 0;
    else
    {
        if(params.count("prec") && is_a_valid_num(params["prec"]))
            ans = calculation(params["fir"], params["sec"], params["op"], params["not"][0], stoll(params["prec"]));
        else
            ans = calculation(params["fir"], params["sec"], params["op"], params["not"][0], -1);

        cout << "The result is " << ans;
        return 0;
    }
}
