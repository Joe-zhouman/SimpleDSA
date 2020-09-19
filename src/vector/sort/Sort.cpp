#include <getopt.h>
#include <stdlib.h>
#include <vector/Vector.h>

#include <iostream>
using namespace simple_dsa;
using namespace std;

static struct option long_options[] = {
    {"help", no_argument, NULL, 'h'},
    {"bubble", required_argument, NULL, 'b'},
    {"merge", required_argument, NULL, 'm'},
    {"selection", required_argument, NULL, 's'},
    {NULL, 0, NULL, 0}};

void PrintHelpInfo() { cout << "!TODO" << endl; }

void PrintVector(Vector<int> vec) {
    cout << "vec[" << vec.Size() << "]={";

    for (size_t i = 0; i < vec.Size() - 1; i++) {
        cout << vec[i] << ", ";
    }
    cout << vec[vec.Size() - 1] << '}' << endl;
}

int main(int argc, char *argv[]) {
    int option_index = 0;
    int c;
    while (EOF != (c = getopt_long(argc, argv, "hb:m:s:", long_options,
                                   &option_index))) {
        SortMethod method;

        switch (c) {
            case 'h':
                PrintHelpInfo();
                return 0;
            case 'b':
                method = SortMethod::BUBBLE;
                break;
            case 's':
                method = SortMethod::SELECTION;
                break;
            case 'm':
                method = SortMethod::MERGE;
                break;
            case '?':
                PrintHelpInfo();
                exit(-1);
            default:
                PrintHelpInfo();
                exit(-1);
        }
        int n = atoi(argv[2]);
        Vector<int> vec;
        for (size_t i = 0; i < n; i++) {
            vec.Insert(rand() % 100);
        }

        PrintVector(vec);

        vec.Sort(method);
        PrintVector(vec);
        return 0;
    }
    return -1;
}
