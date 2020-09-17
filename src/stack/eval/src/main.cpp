#include <getopt.h>

#include "Eval.h"
#include "Init.hpp"
using namespace std;

static struct option long_options[] = {
    {"help", no_argument, NULL, 'h'},
    {"eval", optional_argument, NULL, 'e'},
    {"rpneval", optional_argument, NULL, 'r'},
    {"convert", optional_argument, NULL, 'c'},
    {NULL, 0, NULL, 0}};

int main(int argc, char* argv[]) {
    if (argc < 2 || argc > 3) {
        PrintArgvErrorInfo();
        PrintHelpInfo();
        exit(-1);
    }
    int c = 0;
    int index = 0;
    while (EOF != (c = getopt_long(argc, argv, "herc", long_options, &index))) {
        if (c == 'h') {
            PrintHelpInfo();
            return 0;
        }
        char* exp;
        if (argc == 2) {
            GetExpression(exp);
        }else{
            exp = argv[2];
        }
        RemoveSpace(exp);
        switch (c) {
            case 'e': {
                string rpn;
                cout << "ANS :" << endl;
                cout << '\t' << Evaluate(exp, rpn) << endl;
            } break;
            case 'r': {
                cout << "ANS :" << endl;
                cout << '\t' << RpnEval(exp) << endl;
            } break;
            case 'c': {
                string rpn;
                cout << "The RPN expression is :" << endl;
                Evaluate(exp, rpn);
                 cout << '\t' << rpn << endl;
            } break;
            case '?': {
                PrintArgvErrorInfo();
                PrintHelpInfo();
                exit(-1);
            }
            default:
                break;
        }
    }
    return 0;
}
