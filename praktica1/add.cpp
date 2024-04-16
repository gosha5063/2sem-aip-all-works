#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

class Employee {
    public: 
        Employee(std::string name, std::string country, int age)
        {
            this->name = name;
            this->age = age;
        }
        std::string getInfo()
        {
            return name + " " + country + " " + std::to_string(age);
        }
        std::string country;
        std::string name;
        int age;
};

int main()
{
    std::vector<Employee> employees = {
        Employee("Carl", "USA", 24), 
        Employee("Kirito", "Japan", 18), 
        Employee("Andrew", "Russia", 34), 
        Employee("Cheng", "China", 26), 
        Employee("Rengi", "Japan", 16)
    };
    std::cout << "Unsorted" << std::endl << std::endl;
    for (auto element : employees)
    {
        std::cout << element.getInfo() << std::endl;
    }

    //Sorting
    std::sort(employees.begin(), employees.end(), [](Employee &e1, Employee &e2){
         return e1.age < e2.age;
    });

    std::cout << std::endl;

    std::cout << "Sorted" << std::endl << std::endl;
    for (auto element : employees)
    {
        std::cout << element.getInfo() << std::endl;
    }
}