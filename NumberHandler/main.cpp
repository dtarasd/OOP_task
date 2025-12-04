#include <iostream>
#include <windows.h> //

using namespace std;

class NumberProcessor {
private:
    double val1;
    double val2;

public:
    NumberProcessor() {
        val1 = 0;
        val2 = 0;
    }

    void setValues(double a, double b) {
        val1 = a;
        val2 = b;
    }

    void printValues() {
        cout << "Поточні значення: " << val1 << " та " << val2 << endl;
    }

    double calculateSum() {
        return val1 + val2;
    }

    double findMax() {
        if (val1 > val2) {
            return val1;
        } else {
            return val2;
        }
    }
};

int main() {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    NumberProcessor myObj;
    double in1, in2;

    cout << "Функція, яка знаходить суму\n";

    cout << "Введіть перше число: ";
    cin >> in1;
    cout << "Введіть друге число: ";
    cin >> in2;

    myObj.setValues(in1, in2);
    cout << "----------------------------\n";

    myObj.printValues();
    cout << "Сума чисел: " << myObj.calculateSum() << endl;
    cout << "Найбільше число: " << myObj.findMax() << endl;

    // Пауза
    cout << "\nНатисніть Enter, щоб вийти...";
    cin.ignore();
    cin.get();

    return 0;
}