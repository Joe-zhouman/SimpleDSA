#include<iostream>
using namespace std;
int fib(int n, int& prev){
    if(0 == n){
        prev = 1;
        return 0;
    }else{
        int prev_prev;
        prev = fib(n-1,prev_prev);
        return prev + prev_prev;
    }
}

int main(int argc, char const *argv[])
{
    int n = atoi(argv[1]);
    int prev;
    cout<<fib(n,prev)<<endl;
    return 0;
}
