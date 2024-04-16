#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <cstring>
#include <algorithm>
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
class MottoBikeObj{
protected:
    string mark;
    int year;
    string gos_number;
    string last_name;
public:

    string get_mark() { return mark; }
    int get_year() { return year; }
    string get_gos_number() { return gos_number; }
    string get_last_name() { return last_name; }
    MottoBikeObj(string mark, int year, string gos_number, string last_name){
        this->mark = mark;
        this->year = year;
        this->gos_number = gos_number;
        this->last_name  = last_name;
    }
    MottoBikeObj(){};
    void show(){
        cout << "mark: " << mark << endl;
        cout << "year: " << year << endl;
        cout << "gos_number: " << gos_number << endl;
        cout << "last_name: " << last_name << endl;
        cout << endl;
    }
    void delete_(){
        delete this;
    }
};
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
            year = obj.loadInt(file1);
            gos_number = obj.loadString(file1);
            last_name = obj.loadString(file1);
            MottoBikeObj* motto = new MottoBikeObj(mark, year, gos_number, last_name);
            motto_array.push_back(motto);
        }
    }
    //в начале файла записывается int size для понинмания сколько записей в файле
    void save(int size_new){
        if (size_new == 0) return;

        
        Encoder obj;
        obj.delete_file();

        ofstream file("file.bin", ios::binary | ios::app);
        quick_sort();
        obj.saveint(file, size_new);
        MottoBikeObj *motto;
        for (int i = 0; i < size_new; i++)
        {
            motto = motto_array[i];
            obj.saveString(file,motto->get_mark());
            obj.saveint(file,motto->get_year());
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
            obj.saveint(file,motto->get_year());
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

    void mark_alfabet(){
        string marka;
        cout << "Введите марку мотоцикла" << endl;
        cin >> marka;
        for(MottoBikeObj*a: motto_array)
                {
                    if (marka == a->get_mark())
                    {
                        string element_a = (*a).get_last_name();
                        cout << element_a << endl;   
                    }  
                }
    }
    void gosnum_bolong_to_last_name(){
        string last_name_a;
        cout << "Введите фамилию владельцаа" << endl;
        cin >> last_name_a;
        for(MottoBikeObj*a: motto_array)
                {
                    if (last_name_a == (*a).get_last_name())
                    {
                        a->show();   
                    }  
                }
    }
    void not_older (){
        printf("%s", "Введите год не старше которго вывести запсиси\n");
        int year_a; cin >> year_a;
        for(MottoBikeObj*a: motto_array){
            if (year_a > a->get_year())
            {
                a->show();
            }
        }
    }
    void graf(){

    }
    void delete_gosnum(){
        string gos_number_a;
        cout << "Введите госномер мотоцикла" << endl;
        cin >> gos_number_a;
        vector<MottoBikeObj*> motto_array_dop;
        for(int i = 0; i < motto_array.size();i++)
            {
                MottoBikeObj*a = motto_array[i];
                if (gos_number_a == a->get_gos_number())
                {
                    a->delete_();
                }   
                else{
                    motto_array_dop.push_back(a);
                }
            }
            motto_array = motto_array_dop;
            save(motto_array.size());
    }
    MottoBikeObj* add_moto(){
        printf("%s", "Введите марку мотоцикла");
        cin >> mark;
        printf("%s", "Введите год выпуска мотоцикла");
        cin >> year;
        printf("%s","Введите ГосНомер мотоцикла");
        cin >> gos_number;
        printf("%s","Введите фамилию владельца");
        cin >> last_name;
        return new MottoBikeObj(mark, year, gos_number, last_name);
    }
};


bool dvizok(int num_oper, DataBase *obj){
    bool end = true;
    switch (num_oper)
    {
    case 1:
        obj->mark_alfabet();
        break;
    case 2:
        obj->gosnum_bolong_to_last_name();
        break;
    case 3:
        obj->not_older();
        break;
    case 4: 
        obj->graf();
        break;
    case 5:
        obj->add(obj->add_moto());
        break;
    case 6:
        obj->delete_gosnum();
        break;
    case 7:
        obj->show();
        break;
    case 8:
        end = false;
        break;
    default:
        printf("%s","Вы ввели некорректные данные" );
        break;
    }
    return end;
}
int main(){
    DataBase s;
    bool end=  true;
    while (end)
    {
        int num_oper = 0;
        printf("%s","Здравстуйте, вы в окне управления базой данных.\nВведите номер команды\n\
        1 - Показать алфавитный перечень владельцев, имеющих мотоциклы данной марки.\n\
        2 - Определить марки и госномера мотоциклов, принадлежащих данному владельцу.\n\
        3 - Определить фамилии владельцев, марки и госномера мотоциклов не старше данного года выпуска.\n\
        4 - Построить график зависимости количества зарегистрированных мотоциклов от года выпуска.\n\
        5 - Ввести новое значение\n\
        6 - удалить запись по ГосНомеру\n\
        7 - Вывести все записи\n\
        8 - Выйти из программы\n\
        "); 
        cin >> num_oper;
        end = dvizok(num_oper, &s);
    }
}
