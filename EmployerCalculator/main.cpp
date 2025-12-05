#include <iostream>
#include <locale>
#include <vector>
#include <string>
#include <cstdlib>
#include <io.h>
#include <fcntl.h>

class Employee {
public:
    std::wstring name;
    Employee(const std::wstring& n) : name(n) {}
};

class Employer {
private:
    std::vector<Employee*> employees;
    size_t max_capacity;

public:
    Employer(size_t capacity) : max_capacity(capacity) {}

    ~Employer() {
        for (Employee* emp : employees) {
            delete emp;
        }
    }
    void hire(Employee* new_employee) {
        if (employees.size() < max_capacity) {
            employees.push_back(new_employee);
            std::wcout << L"НАЙМ: " << new_employee->name << L" прийнято на роботу." << std::endl;
        } else {
            std::wcout << L"ПОМИЛКА: Немає вакантних місць. Максимальна місткість: "
                      << max_capacity << L" співробітників." << std::endl;
            delete new_employee;
        }
    }

    void fire(const size_t i) {
        if (i < employees.size()) {
            std::wstring fired_name = employees[i]->name; // ЗМІНЕНО на wstring
            delete employees[i];
            employees.erase(employees.begin() + i);
            std::wcout << L"\nЗВІЛЬНЕННЯ: Працівника " << fired_name << L" (індекс " << i
          << L") звільнено." << std::endl;
        } else {
            std::wcout << L"\nПОМИЛКА: Недійсний індекс " << i
                      << L" для звільнення. Кількість співробітників: "
                      << employees.size() << std::endl;
        }
    }

    void listEmployees() const {
        std::wcout << L"\nСписок співробітників (" << employees.size()
                  << L"/" << max_capacity << L") " << std::endl;
        for (size_t i = 0; i < employees.size(); ++i) {
            std::wcout << L"Індекс " << i << L": " << employees[i]->name << std::endl;
        }
    }
};

namespace Calculator {
    double accumulator = 0.0;

    enum Operation { ADD, SUB, MUL, DIV, CLR };
}

void exe(Calculator::Operation op, double operand = 0.0) {
    using namespace Calculator;
    std::wcout << L"\n> КОМАНДА: ";

    switch (op) {
        case ADD:
            std::wcout << L"ADD (" << operand << L")";
            accumulator += operand;
            break;
        case SUB:
            std::wcout << L"SUB (" << operand << L")";
            accumulator -= operand;
            break;
        case MUL:
            std::wcout << L"MUL (" << operand << L")";
            accumulator *= operand;
            break;
        case DIV:
            std::wcout << L"DIV (" << operand << L")";
            if (operand != 0.0) {
                accumulator /= operand;
            } else {
                std::wcout << L"\nПОМИЛКА: Ділення на нуль!" << std::endl;
                return;
            }
            break;
        case CLR:
            std::wcout << L"CLR";
            accumulator = 0.0;
            std::wcout << L"\nАкумулятор очищено." << std::endl;
            return;
    }

    std::wcout << L"\nПоточний акумулятор: " << accumulator << std::endl;
}

int main() {
    #ifdef _WIN32
        _setmode(_fileno(stdout), _O_U16TEXT);
    #endif
    std::wcout.imbue(std::locale(""));

    std::wcout << L"---------------------------------------" << std::endl;
    std::wcout << L"(Компанія 'ПрогресЮА')" << std::endl;
    std::wcout << L"---------------------------------------" << std::endl;

    Employer company(2); // Максимальна місткість 2

    // 1. Найм
    company.hire(new Employee(L"Олена"));
    company.hire(new Employee(L"Микола"));
    company.listEmployees();

    // 2. Відсутність вакантних місць
    std::wcout << L"\nСПРОБА ПЕРЕПОВНЕННЯ" << std::endl;
    company.hire(new Employee(L"Тарас"));

    // 3. Звільнення
    company.fire(0); // Звільняємо Олену (індекс 0)
    company.listEmployees();

    // 4. Новий найм на звільнене місце
    company.hire(new Employee(L"Віктор"));
    company.listEmployees();

    std::wcout << L"\n\n---------------------------------------" << std::endl;
    std::wcout << L"ТЕСТУВАННЯ Калькулятора (exe)" << std::endl;
    std::wcout << L"---------------------------------------" << std::endl;

    exe(Calculator::ADD, 10.0);
    exe(Calculator::MUL, 5.0);
    exe(Calculator::SUB, 8.0);
    exe(Calculator::DIV, 2.0);

    exe(Calculator::CLR, 0.0);

    exe(Calculator::ADD, 100.0);
    exe(Calculator::DIV, 0.0);

    std::wcout << L"\n---------------------------------------" << std::endl;
    std::wcout << L"Кінець програми." << std::endl;

    return 0;
}