#include <iostream>
#include <vector>
using namespace std;
#include <math.h>
template <typename T>
class Vector{
private:
    size_t size;
    size_t capacity;
    T* arr;
public:
    Vector(T & Arr,size_t n){ 
        capacity = pow(2,floor(log2(n)+1));
        arr = reinterpret_cast<T*>(new byte[n*sizeof(T)]);
        size = n;
        for (int i = 0; i < n; i++)
        {
            arr[i] = *(&Arr+i);
        }
    }
    void resize(size_t n, const T& value = T()){
        if(n > capacity)reserve(n);
        for(int i = size; i < n;++i)new (arr+i)T(value);
        if (n < size)size = n;
    }
    void reserve(size_t n){
        if (n < capacity)return;
        T* newarr = reinterpret_cast<T*>(new byte[n*sizeof(T)]);//создание n массивов длины байт и преобразование в n объектов T
        for (size_t i = 0; i < size; i++) new (newarr + i)T(arr[i]);//вызов конструктора T(arr[i]) из каждой ячейки памяти
        for (size_t i = 0; i < size;i++) (arr+i)->~T();
        delete[] reinterpret_cast<byte*>(arr);
        arr = newarr;
        capacity = n;
    }
    void push_back(const T& value){
        if(size == capacity)reserve(2*size);
        new (arr+size)T(value);
        ++size;
    }
    void print(){
    for (int i = 0; i < size; i++)
        {
            cout << *(arr + i) << endl;
        }
    }
};

int main(){
    // size_t size = 5;
    // int *dop = new int[size] {1, 2, 3, 4, 5};
    // int Arr[5] = {1,2,3,4,4};
    // Vector vect2(*Arr,size);
    // vect2.print();
    // Vector vect(*dop,size); 
    // vect.push_back(5);
    // vect.print();
    // return 0;

    vector<int> g[100];
}