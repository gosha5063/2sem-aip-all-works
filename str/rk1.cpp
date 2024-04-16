#include <iostream>
using namespace std;

void sum(int a, int b){
    a = a+b;
}

int main(){
    int * a;
    *a = 1;
    int b = 8;
    a = &b;
    cout << *a << " " << b;
    // sum(a,b);
    // cout << a;
}