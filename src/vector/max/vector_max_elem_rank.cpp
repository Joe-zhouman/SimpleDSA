#include"../../include/SimpleDsa.h"
#include<iostream>
using namespace simple_dsa;
using namespace std;
int main(){
    int init[] = {1, 4, 3, 6, 2};
    Vector<int> v(init,5);
    for (size_t i = 0; i < 5; i++)
    {
        cout<<v[i]<<endl;
    }
    
}