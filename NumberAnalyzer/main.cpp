#include <iostream>
#include <windows.h>

using namespace std;

class NumberAnalyzer {
public:
    void processNumber(int number) {

        if (number < 10 || number > 99) {
            cout << "Помилка: Число має бути двоцифровим (від 10 до 99)!" << endl;
            return;
        }

        int tens = number / 10;
        int units = number % 10;

        int sum = tens + units;
        int product = tens * units;

        cout << "-----------------------------" << endl;
        cout << "Кількість десятків: " << tens << endl;
        cout << "Кількість одиниць:  " << units << endl;
        cout << "Сума цифр:          " << sum << endl;
        cout << "Добуток цифр:       " << product << endl;
        cout << "-----------------------------" << endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    NumberAnalyzer solver;
    int num;

    cout << "Аналіз двоцифрового числа\n";
    cout << "Введіть двоцифрове число: ";

    if (cin >> num) {
        solver.processNumber(num);
    } else {
        cout << "Помилка: Ви ввели не число!" << endl;
    }

    cout << "\nНатисніть Enter, щоб вийти...";
    cin.ignore(); cin.get();

    return 0;
}