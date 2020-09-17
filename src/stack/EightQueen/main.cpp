#include "EightQueens.hpp"
using namespace std;
int main(int argc, char const *argv[]) {
    if (argc != 2) {
        cout << "!FATAL : must followed by a parameter" << endl;
        exit(-1);
    }
    auto n = atoi(argv[1]);
    EightQueens sln(n);
    sln.PlaceQueens();
    if (!sln.HasSolution()) {
        cout << "Problem has NO solution!" << endl;
    }

    return 0;
}
