#include "../lib/helper.h"
#include "../lib/calculator.h"

init_params helper::process_params(int argc, char* argv[])  
{
    int cnt{};
    bool help_flag{false};

    while(cnt < argc)
    {
        if(string(argv[cnt]) == "--help" or string(argv[cnt]) == "-h")
        {
            print_help_infos();
            help_flag = true;
        }
        cnt++;
    }
    if(!help_flag)
        return identify_flags(argc, argv);
    else
        return init_params();
}

init_params helper::identify_flags(int argc, char* argv[])
{
    init_params params;
    regex re(R"(^\s*(-?(?:\d+(?:\.\d+)?|\.\d+))\s*([+\-*/])\s*(-?(?:\d+(?:\.\d+)?|\.\d+))\s*$)");
    cmatch match;

    if(argc == 1)
    {
        cout << "Please provides necessary parameters!\nFor help, use ./calculator --help";
        return params;
    }
    else
    {
        int cnt{1};
        while(cnt < argc)
        {
            if(string(argv[cnt]) == "-e")
                params["not"] = "e";
            else if(string(argv[cnt]) == "-s")
                params["not"] = "p";
            else if(string(argv[cnt]) == "-p")
                params["prec"] = "TBD";
            else if(calculator::is_a_valid_num(string(argv[cnt])))
                params["prec"] = string(argv[cnt]);
            else if(regex_match(argv[cnt], match, re))
            {
                params["fir"] = match[1];
                params["op"] = match[2];
                params["sec"] = match[3];
            }
            cnt++;
        }
        
        if(params.count("prec") && params["prec"] == "TBD")
        {
            cout << "please specify the precision with integer.\n";
            return init_params();
        }
        return params;
    }
        
}

void helper::print_help_infos()
{
    cout << "A command-line calculator for real numbers by Elizabeththh\n\n";
    cout << "Usage:\n  ./calculator <your formula>  The formula must be enclosed in double quotes\n\n";

    cout << "Flags:\n";
    cout << "-h, --help         help for calculator\n";
    cout << "-e                 result will be expressed in scienticfic notation\n";
    cout << "-s                 result will be expressed in plain number\n";
    cout << R"(-p <precision>     result will be expressed with the precision you specify";
                   The precision here means how many digits after decimal point you want this program to display;
                   If you enter -1, this program will display all the bits it calculates except division.
                   Division display 20 bits at most after decimal points by default.
                   You can enter your prefered precision for division of course.)";
}