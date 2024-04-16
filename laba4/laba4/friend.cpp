#include <iostream>
using namespace std;
class Float;
class num{
private:
    int n;

public:
    num(int n):n(n){}


    void print(){cout << n << endl;}
    friend num operator+(num,num);
    friend class Float;
    num& operator++(){
        n += 1;
        return *this;
    }
    num operator++(int){
        num copy{*this};
        ++n;
        return copy;
    }
    num operator+(float k){
        return num(n++);
    }
};
num operator+(num n1, num n2){
    return num(n1.n + n2.n);
}
class Float{
    private:float f;
    public:
    Float(float f):f(f){}
    void print(num n){
        cout << n.n + f;
    }
};

int main(){
    num n = 10;
    n = 11 + n;
    n.print();
}