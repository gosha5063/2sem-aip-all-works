#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
#include "methods.h"
using namespace std;
#define AMOUNT_MAX 3000

class Encoder{
public:
    Encoder(){}
    void delete_file(){
        ofstream file("file.bin", ios::binary | ios::trunc);
        if (file.is_open())
        {
           file.close();
        }

    }
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
        if (ist.fail())
            return "";

        char* raw_str = new char[n];
        ist.read((char*)raw_str, n);
        str = raw_str;
        delete[] raw_str;
        return str;
    }
    int loadInt(istream& ist){
        int year;
        ist.read((char*)&year, sizeof(int));
        if (year > AMOUNT_MAX)
        {
            return 0;
        }

        return year;
    }
};



string MottoBikeObj::get_mark() { return mark; }
string MottoBikeObj::get_year() { return year; }
string MottoBikeObj::get_gos_number() { return gos_number; }
string MottoBikeObj::get_last_name() { return last_name; }
MottoBikeObj::MottoBikeObj(string mark, string year, string gos_number, string last_name){
        this->mark = mark;
        this->year = year;
        this->gos_number = gos_number;
        this->last_name  = last_name;
    }
MottoBikeObj::MottoBikeObj(){};

void MottoBikeObj::delete_(){
        delete this;
    }

class DataBase :public MottoBikeObj{
private:
    vector<MottoBikeObj*> motto_array;
    string filename = "database.dat";
    int size;
public:
    DataBase():MottoBikeObj(){
        init();
    }
    //считывание данных ииз файла
    void init(){
        Encoder obj;
        ifstream file1("file.bin", ios::binary);
        size = obj.loadInt(file1);
        for (int i = 0; i < size; i++)
        {
            //считывание марки, года(int) госномера и фамилии
            mark = obj.loadString(file1);
            year = obj.loadString(file1);
            gos_number = obj.loadString(file1);
            last_name = obj.loadString(file1);
            MottoBikeObj* motto = new MottoBikeObj(mark, year, gos_number, last_name);
            motto_array.push_back(motto);
        }
    }
    vector<MottoBikeObj*> get_vec(){
        return motto_array;
    }
    //в начале файла записывается int size для понинмания сколько записей в файле
    void save(int size_new){
        Encoder obj;
        obj.delete_file();
        if (size_new == 0)
            return;
        ofstream file("file.bin", ios::binary | ios::app);
        quick_sort();
        obj.saveint(file, size_new);
        MottoBikeObj *motto;
        for (int i = 0; i < size_new; i++)
        {
            motto = motto_array[i];
            obj.saveString(file,motto->get_mark());
            obj.saveString(file,motto->get_year());
            obj.saveString(file,motto->get_gos_number());
            obj.saveString(file,motto->get_last_name());
        }
        file.close();
    }
    void add(MottoBikeObj* motto)
    {
        //добавление нового элемента 1 очистка файла 2 запись новых данных из отсортированных по алфавиту объектов
        //в начале файла идет информация о количетве записей не больше чем AMOUNT_MAX
        Encoder obj;
        obj.delete_file();
        ofstream file("file.bin", ios::binary | ios::app);

        size++;

        motto_array.push_back(motto);
        quick_sort();
        obj.saveint(file, size);
        for (int i = 0; i < size; i++)
        {
            motto = motto_array[i];
            obj.saveString(file,motto->get_mark());
            obj.saveString(file,motto->get_year());
            obj.saveString(file,motto->get_gos_number());
            obj.saveString(file,motto->get_last_name());
        }
        file.close();
    }
    void show(){
        for (int i = 0; i < size; i++)
        {
            motto_array[i]->show();
        }
    }
    void quick_sort(){
        std::sort(motto_array.begin(),motto_array.end(),
            [](MottoBikeObj* a, MottoBikeObj* b){return a->get_last_name() < b->get_last_name();});
    }

    vector<MottoBikeObj*> mark_alfabet(string marka){
        vector<MottoBikeObj*> dop;
        for(MottoBikeObj*a: motto_array)
                {
                    if (marka == a->get_mark())
                    {
                        dop.push_back(a);
                    }
                }
        return dop;
    }
    vector<MottoBikeObj*> gosnum_belong_to_last_name(string last_name_a){
        vector<MottoBikeObj*> dop;
        for(MottoBikeObj*a: motto_array)
                {
                    if (last_name_a == (*a).get_last_name())
                    {
                        dop.push_back(a);
                    }
                }
        return dop;
    }
    void not_older (){
        // int year_a; cin >> year_a;
        // for(MottoBikeObj*a: motto_array){
        //     if (year_a > a->get_year())
        //     {
        //         a->show();
        //     }
        // }
    }
    void graf(){

    }
    bool delete_gosnum(string gos_number_a){
        size = motto_array.size();
        vector<MottoBikeObj*> motto_array_dop;
        for(int i = 0; i < motto_array.size();i++)
            {
                MottoBikeObj*a = motto_array[i];
                if (gos_number_a == a->get_last_name())
                {
                    a->delete_();
                }
                else{
                    motto_array_dop.push_back(a);
                }
            }
        motto_array = motto_array_dop;
        save(motto_array.size());
        if(motto_array.size() == size){
            return false;
        }
        return true;
    }
    MottoBikeObj* add_moto(){
        // printf("%s", "Введите марку мотоцикла");
        // cin >> mark;
        // printf("%s", "Введите год выпуска мотоцикла");
        // cin >> year;
        // printf("%s","Введите ГосНомер мотоцикла");
        // cin >> gos_number;
        // printf("%s","Введите фамилию владельца");
        // cin >> last_name;
        return new MottoBikeObj(mark, year, gos_number, last_name);
    }
};

DataBase db;
QString Translator::add(string mark,string year, string gos_number, string last_name){

    db.add(new MottoBikeObj(mark,year, gos_number,last_name));
    return QString::fromStdString("Запись успешно добавлена");
}
vector<MottoBikeObj*> Translator::show(){
    return db.get_vec();
}
vector<MottoBikeObj*> Translator::show_last_name(string last_name){
    return db.gosnum_belong_to_last_name( last_name);
}
vector<MottoBikeObj*> Translator::show_mark(string marka){
    return db.mark_alfabet(marka);
}
// ans 0 усли ничего не было удалено 1 - если удалили
QString Translator::delete_gos(string gos_num){
    bool ans = db.delete_gosnum(gos_num);
    if(ans) return QString::fromStdString("Успешно удалена");
    return QString::fromStdString("Такой записи не было");
}
#include <QString>
QString main1(){
    // DataBase s;
    bool end=  true;
    int num_oper = 0;
    string s = "Здравстуйте, вы в окне управления базой данных.";
    return QString::fromStdString(s);

}
