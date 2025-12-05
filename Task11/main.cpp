#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Polymorphism {
public:

    void analyze(int number) {
        cout << "[INT] Це ціле число: " << number << endl;
        cout << "Його квадрат: " << number * number << endl;
    }

    void analyze(string text) {
        cout << "[STRING] Це рядок тексту: " << text << endl;
        cout << "Довжина рядка: " << text.length() << " символів" << endl;
    }

    void analyze(double number) {
        cout << "[DOUBLE] Це дробове число: " << number << endl;
    }

    int getArea(int side) {
        cout << "Рахуємо площу квадрата..." << endl;
        return side * side;
    }


    int getArea(int width, int height) {
        cout << "Рахуємо площу прямокутника..." << endl;
        return width * height;
    }


    int getArea(int width, int height, int depth) {
        cout << "Рахуємо об'єм фігури..." << endl;
        return width * height * depth;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Polymorphism demo;

    cout << "1. Перевантаження за ТИПОМ" << endl;
    demo.analyze(100);
    demo.analyze("Студент");
    demo.analyze(36.6);

    cout << "\n2. Перевантаження за КІЛЬКІСТЮ" << endl;

    int square = demo.getArea(5);
    cout << "Результат: " << square << endl << endl;

    int rect = demo.getArea(5, 10);
    cout << "Результат: " << rect << endl << endl;

    int box = demo.getArea(2, 3, 4);
    cout << "Результат: " << box << endl;

    cout << "\nНатисніть Enter...";
    cin.get();

    return 0;
}