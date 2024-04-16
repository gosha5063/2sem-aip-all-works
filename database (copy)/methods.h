#pragma once
#ifndef METHODS_H
#define METHODS_H
#include <vector>
#include <QString>
#include <QTextEdit>
#include <string>
QString main1();
using namespace std;
class MottoBikeObj{
protected:
    string mark;
    string year;
    string gos_number;
    string last_name;
public:

    std::string get_mark();
    std::string get_year();
    std::string get_gos_number();
    std::string get_last_name();
    MottoBikeObj(string mark, string year, string gos_number, string last_name);
    MottoBikeObj();
    void show();
    void delete_();
};

class Translator{
public:
    QString add(std::string mark,string year, std::string gos_number, std::string last_name);
    vector<MottoBikeObj*> show();
    vector<MottoBikeObj*> show_last_name(string marka);
    vector<MottoBikeObj*> show_mark(string last_name);
    QString delete_gos(string gos_num);
};

#endif // METHODS_H
