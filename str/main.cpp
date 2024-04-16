#include <iostream>
using namespace std;
#include <cstring>
#include <vector>
class String{
private:
    int len;
    char*str;
public:
    String(const char*st){
        len = strlen(st);
        str = new char[len+1];
        strcpy(str,st);
    }
    String(){
        len = 0;
        str = nullptr;
    }
    void print(){
        cout << str << " " << len << "\n";
    }
    String operator+(const String&s){
        String st;
        int z = len + s.len;
        st.str = new char[z+1];
        strcpy(st.str,str);
        strcat(st.str,s.str);
        st.len = z+1;
        return st;
    }
    String& operator=(const String&s){
        if (str)delete[]str;
        len = s.len;
        str = new char[len+1];
        strcpy(str,s.str);
        return *this;
    }
};
int nod(int a, int b){
    while (b != 0)
    {
        int tmp = a%b;
        a = b;
        b = tmp;
    }
    return a;   
}
unsigned long int step(unsigned long int a, int k){
    vector<unsigned long int> arr;
    arr.push_back(a);
    int m = 2;
    while (m <= k)
    {
        arr.push_back(arr[arr.size()-1]*arr[arr.size()-1]);
        m *= 2;
    }
    if (m == k)return arr[arr.size()-1];
    
    unsigned long int res = 1;
    int pos = 0;
    while (k != 0)
    {
        if (k%2)
        {
            res *= arr[pos];
        }
        k/=2;
        pos++;
    }
    return res;
}
#include <cmath>
vector<unsigned long int> del(unsigned long int a){
    vector<unsigned long int> res;
    while (a%2 == 0)
    {
        res.push_back(2);
        a/=2;
    }
    unsigned long int tmp = pow(a,0.5);
    int i = 3;
    while (a <= tmp)
    {
        while (a%i==0)
        {
            res.push_back(i);
            a/=i;
            tmp = pow(a,0.5);
        }
        i += 2;
    }
    if(a)res.push_back(a);
    return res;
    
}
void erat(){
    int left = 2, right = 1000;
    bool* comp = new bool[right];
    for (int i = left; i < right; i+=2)
    {
        comp[i] = true;
    }
    int prime = 3;
    while(prime<=right){
        for (int i = (prime)*2 - left; i < right; i+=prime)
        {
            comp[i] = true;
        }
        prime += 2;
        for (int i = prime; i < right; i++)
        {
            if (!comp[i])
            {
                prime = i;
                break;
            }
            i+=2;
            
        }
    }
    for(int i = 0; i<right; i++){
        if (!comp[i])
        {
            cout<<i+left<<endl;
        }
        
    }
     
}

int main(){
    erat();
    // vector<unsigned long int> vec = del(10203922);
    // for (int i = 0; i < vec.size(); i++)
    // {
    //     cout << v[i] << " ";
    // }
    
    // cout << step(2,15);
    // String s("Gosha"), st(" great");
    // s.print();
    // (s + st).print();
    // String S = s + st;
    // S.print();
}