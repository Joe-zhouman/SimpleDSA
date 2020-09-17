#include <iostream>
#include <string>

#include "../../../include/stack/StackL.h"
using namespace std;
using namespace simple_dsa;
void convert(StackL<char>& s, __int64_t n, int base) {
    static char digit[] = {'0', '1', '2', '3', '4', '5', '6', '7',
                           '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    while (0 < n) {
        auto remainder = static_cast<int>(n % base);
        s.Push(digit[remainder]);
        n /= base;
    }
}

int main(int argc, char const* argv[]) {
    if (argc != 3) {
        cout << "!FATAL : wrong number of parameters" << endl;
        exit(1);
    }
    auto n = atoi(argv[1]);
    auto base = atoi(argv[2]);
    StackL<char> s;
    convert(s, n, base);
    string output;
    while (!s.Empty()) {
        output += s.Pop();
    }
    cout << n << "[10] = " << output << '[' << base << ']' << endl;
    return 0;
}
