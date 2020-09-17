#include <iostream>

#include "../../../include/list/List.h"
using namespace simple_dsa;
using namespace std;
class Visit {
public:
    void operator()(int a) { cout << a << endl; }
};
int main() {
    List<int> test_list;
    test_list.InsertAsLast(1);
    test_list.InsertAsLast(2);
    Visit printer;
    test_list.Traverse(printer);
}