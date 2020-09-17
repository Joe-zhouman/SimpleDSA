#include <iostream>
#include <string>

#include "../../../include/stack/StackL.h"
using namespace std;
using namespace simple_dsa;

bool Match(const char exp[]) {
    StackL<char> paren;
    for (size_t i = 0; exp[i] != '\0'; i++) {
        switch (exp[i]) {
            case '(':
            case '[':
            case '{':
                paren.Push(exp[i]);
                break;
            case ')':
                if (paren.Empty() || paren.Pop() != '(') return false;
                break;
            case ']':
                if (paren.Empty() || paren.Pop() != '[') return false;
                break;
            case '}':
                if (paren.Empty() || paren.Pop() != '{') return false;
                break;
            default:
                break;
        }
    }
    return paren.Empty();
}
int main(int argc, char const *argv[]) {
    if (argc != 2) {
        cout << "!FATAL : wrong number of parameters" << endl;
        exit(1);
    }
    cout << argv[1] << endl;
    if (Match(argv[1])) {
        cout << "matched expression !" << endl;
    } else {
        cout << "not matched expression !" << endl;
    }

    return 0;
}
