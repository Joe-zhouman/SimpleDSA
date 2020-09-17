#include "/home/joe/local/MyDsa/include/SimpleDsa.h"
#include <iostream>
using namespace simple_dsa;
using namespace std;
int main()
{
    int t[] = {1, 4, 3, 6, 2};
    Vector<int> v(t, 5);
    v.Sort(SortMethod::BUBBLE);
    for (size_t i = 0; i < 5; i++)
    {
        cout << v[i] << endl;
    }
}