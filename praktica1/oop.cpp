// #include <iostream>
// using namespace std;
// class TPoint{
//    private:      float x,y;
//    public:
//           TPoint(float ax,float ay):x(ax),y(ay)
//       {cout<<"Constructor\n";}
//       TPoint(){cout<<"Constructor without parameters\n";}
//       TPoint(TPoint &p){ cout<<"Copy Constructor\n";
// 		  x=p.x; y=p.y;
//       }
//       ~TPoint(){cout<<"Destructor\n";}
//       void Out(void)	 { cout<<"\n{"<<x<<","<<y<<"}\n"; }
//       TPoint& operator+=(TPoint &p);  // a+=b;
//       TPoint operator+(TPoint &p);    // a+b;
//       TPoint& operator=(TPoint const &p);   // a=b;
// }; 
// TPoint& TPoint::operator+=(TPoint &p)
// { 
//       x+=p.x; y+=p.y;     cout<<"operator+=\n";
//       return *this;
// }
//  TPoint TPoint::operator+(TPoint &p)
//  { 
//       TPoint pp(x,y);     cout<<"operator+\n";
//       return pp+=p;
//  }
//  TPoint& TPoint::operator=(TPoint const &p)
//  {    
//       x=p.x; y=p.y;       cout<<"operator=\n";
//       return *this;
//  }

//  int main(){   
//     TPoint p(2,3),q(4,5),r(7,8);
//     p+=r; 
//     p.Out();
//     q=p+r;
//     q.Out();
//     return 0;
// }




#include <iostream>
using namespace std;
class integer {
    int value;
public :
    integer( ) { 
        value = 0; 
        cout << "Constructor\n";
    }
    integer(integer &obj){
        value = obj.value;
        cout << "Copy constructor\n";
    }
    integer(int p){
        value = p;
        cout << "Constructor\n" ;
    }
    ~integer(){ cout << "Destructor\n";  }
    integer& operator++();     // префиксный оператор
    integer operator++(int);   // постфиксный оператор
    integer& operator=(const int & );
    integer& operator=(const integer & p);
    integer operator+(const integer & p);
};
integer& integer::operator++() {
    cout << "Prefix\n";
    value++;
    cout << "Prefix\n";
    return *this;
}
integer integer::operator++(int){
    cout << "Postfix\n";
    integer temp = *this;
    ++(*this);
    cout << "Postfix\n";
    return ++temp;
}
integer& integer::operator=(const int& val ){
    cout << "Assignment\n";
    value = val;
    cout << "Assignment\n";
    return *this;
}
integer& integer::operator=(const integer &p){
    this->value = p.value;
    cout << "operator= ineger&\n";
    return *this;
}
integer integer::operator+(const integer &p){
    integer temp = *this;
    temp.value += p.value;
    return temp;
}
int main ( ) {
    integer i;
    integer p = 90;
    ++i;   // префиксный оператор
    integer k = i++;   // постфиксный оператор

    i = 10;
    i = p;
    integer l = i + p + i;
    return 0;
}