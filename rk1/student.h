#ifndef STUDENT_H
#define STUDENT_H
#include <string>
#include <QString>


#include <exception>
#include <string>
#include <memory>


class StudentNotFoundException : public std::exception {
private:
    std::string message;
public:
    StudentNotFoundException(QString name) {
        message = "Студент с ФИО " + name.toStdString() + " не найден.";

    }
    virtual const char* what() const throw() {
        return message.c_str();
    }
};

class Student{
protected:
    QString fio;
    QString age;
    QString date;
public:
    Student(QString fio, QString age): fio(fio),age(age){}
    virtual QString get_by_fio();
    virtual QString getName(){return fio;}
    virtual QString getCourse(){return fio;}
    virtual QString getDefenseDate(){return QString("такого ученика нет");}
};



class Graduated_sudent:public Student{
private:
    QString date;
public:
    Graduated_sudent(QString fio, QString age, QString Grad):Student(fio,age), date(Grad){}
    QString get_by_fio() override;
    QString getDefenseDate(){return date;}
};


#include <vector>
using namespace std;
class Group {
private:
    vector<shared_ptr<Student>> students;

public:
    void addStudent(const std::shared_ptr<Student>& student) {
        students.push_back(student);
    }

    QString printStudentInfoByName(QString name);
};
#endif // STUDENT_H
