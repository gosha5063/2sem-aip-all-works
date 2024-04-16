#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <stdexcept>
#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
using namespace std;


class Telem{
public:
    virtual string toString() const = 0;
    virtual ~Telem() = default;
};
class Tnum: public Telem{
private:
    int num;
public:
    Tnum(int n):num(n){}
    string toString() const override{
        return to_string(num);
    }
};
class Tstr: public Telem{
private:
    string val;
public:
    Tstr(string val): val(val){}
    string toString() const{
        return val;
    }
};

class QueueExeption: public exception{
private:string message;
public:
    QueueExeption(string msg):message(msg){};
    const char* what() const noexcept override{
        return message.c_str();
    }
};
template <typename T>
class Queue{
protected:
    vector<shared_ptr<T>>elements;
public:
    void add(shared_ptr<T> elem){
        elements.push_back(elem);
    }
    shared_ptr<T> popfront(){
        if (elements.size() == 0)throw QueueExeption("Can't delete unexisting var");
        auto e = *elements.begin();
        elements.erase(elements.begin());
        return e;
    }
    vector<shared_ptr<T>> print() const{
        return elements;
    }
};


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Queue<Telem> q;
    void clear();

public slots:
    void del();
    void cout();
    void add();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
