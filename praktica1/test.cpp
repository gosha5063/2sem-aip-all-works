
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;


class foo
{
public:
    void saveString(ostream& ost, const string& str) {
        size_t n = str.size();
        char* raw_str = new char[n+1];
        strcpy(raw_str, str.c_str());
        // raw_str[n-1] = '\0';
        ost.write((const char*)&n, sizeof(size_t));
        ost.write((const char*)raw_str, n);
        delete[] raw_str;
    }
    void saveint(ostream& ost, const int year){
        ost.write((const char*)&year, sizeof(int));
    }
    string loadString(istream& ist) {
        size_t n;
        string str;
        ist.read((char*)&n, sizeof(size_t));
        char* raw_str = new char[n];
        ist.read((char*)raw_str, n);
        str = raw_str;
        delete[] raw_str;
        return str;
    }
    int loadInt(istream& ist){
        int year;
        ist.read((char*)&year, sizeof(int));
        return year;
    }
};




int main(){
    ofstream file("file.bin", ios::binary | ios::app);
    foo obj;
    obj.saveint(file, 1);
    obj.saveString(file,"bmw");
    obj.saveint(file,1985);
    obj.saveString(file,"123esd12");
    obj.saveString(file,"brainstorm");
    file.close();
    ifstream file1("file.bin", ios::binary);
    string* str = new string;
    int n = obj.loadInt(file1);
    while (n)
    {
        cout << obj.loadString(file1) << endl;
        cout << obj.loadInt(file1) << endl;
        cout << obj.loadString(file1) << endl;
        cout << obj.loadString(file1) << endl;
        n--;
    } 
}