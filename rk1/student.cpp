#include "student.h"
using namespace std;

QString Student::get_by_fio(){
    return fio;
}

QString Graduated_sudent::get_by_fio(){
    return fio;
}




QString Group:: printStudentInfoByName(QString name){
    for (const auto& student : students) {
        QString s;
        if (student->getName() == name) {
            s = "ФИО: " + student->getName() + ", Курс: " + student->getCourse();
            s+= ", Дата защиты: " + student->getDefenseDate();
            return s;
        }
    }

    throw StudentNotFoundException(name);
    return "Записей пока нет";

}

