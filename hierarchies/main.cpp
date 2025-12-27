#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

class University {
protected:
    std::string uniName;
public:
    University(std::string name) : uniName(name) {}
    virtual ~University() {}

    virtual void displayInfo() const {
        std::cout << "Університет: " << uniName << std::endl;
    }
};

// Факультет
class Faculty : public University {
protected:
    std::string facultyName;
public:
    Faculty(std::string uName, std::string fName)
        : University(uName), facultyName(fName) {}

    void displayInfo() const override {
        std::cout << "Університет: " << uniName
                  << " | Факультет: " << facultyName << std::endl;
    }
};

// Кафедра
class Department : public Faculty {
private:
    std::string deptName;
public:
    Department(std::string uName, std::string fName, std::string dName)
        : Faculty(uName, fName), deptName(dName) {}

    void displayInfo() const override {
        std::cout << "Університет: " << uniName
                  << " | Факультет: " << facultyName
                  << " | Кафедра: " << deptName << std::endl;
    }
};

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    std::vector<University*> structures;

    structures.push_back(new University("Київський політехнічний інститут"));
    structures.push_back(new Faculty("КНУ ім. Шевченка", "Юридичний факультет"));
    structures.push_back(new Department("НаУКМА", "Факультет інформатики", "Кафедра мультимедійних систем"));

    std::cout << "Дані про об'єкти" << std::endl;

    for (const auto& item : structures) {
        item->displayInfo();
    }

    for (auto item : structures) {
        delete item;
    }

    return 0;
}