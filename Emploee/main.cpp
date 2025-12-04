#include <iostream>
#include <windows.h>

using namespace std;


class Employee {
private:
    int empId;       // Номер працівника
    double salary;   // Заробітна плата

public:

    Employee() {
        empId = 0;
        salary = 0.0;
    }

    // Метод для встановлення даних
    void setData(int id, double sal) {
        empId = id;
        salary = sal;
    }

    // Метод для виведення інформації про одного працівника
    void display() {
        cout << "ID: " << empId << " | Зарплата: " << salary << " грн" << endl;
    }
};


class Department {
private:
    Employee* staff;
    int count;       // Кількість працівників

public:
    Department() {
        staff = nullptr;
        count = 0;
    }


    ~Department() {
        if (staff != nullptr) {
            delete[] staff;
        }
    }


    void inputData() {
        cout << "Введіть кількість працівників: ";
        cin >> count;

        if (count <= 0) {
            cout << "Помилка: кількість має бути більше 0!" << endl;
            return;
        }


        staff = new Employee[count];

        for (int i = 0; i < count; i++) {
            int id;
            double sal;

            cout << "\n--- Працівник #" << (i + 1) << " ---" << endl;
            cout << "Введіть номер (ID): ";
            cin >> id;
            cout << "Введіть зарплату: ";
            cin >> sal;


            staff[i].setData(id, sal);
        }
    }


    void showAll() {
        if (count <= 0) return;

        cout << "\n==========================" << endl;
        cout << "   ВІДОМІСТЬ ПРАЦІВНИКІВ   " << endl;
        cout << "==========================" << endl;

        for (int i = 0; i < count; i++) {
            staff[i].display();
        }
        cout << "==========================" << endl;
    }
};


class ProgramRunner {
public:
    void run() {
        Department hrSystem;

        hrSystem.inputData();
        hrSystem.showAll();
    }
};

// --- MAIN ---
int main() {
    // Налаштування UTF-8 для CLion
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    // Створюємо демонстратор і запускаємо його
    ProgramRunner app;
    app.run();

    // Пауза перед виходом
    cout << "\nНатисніть Enter, щоб вийти...";
    cin.ignore();
    cin.get();

    return 0;
}