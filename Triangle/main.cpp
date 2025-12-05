#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

class TriangleTask {
public:

    void analyzeAndCalculate(double a, double b) {

        if (a <= 0 || b <= 0) {
            cout << "Помилка: Такого трикутника не існує!" << endl;
            cout << "(Катети мають бути додатніми числами)" << endl;
            return;
        }

        double c = sqrt(pow(a, 2) + pow(b, 2));

        double p = a + b + c;

        cout << "------------------------------" << endl;
        cout << "Гіпотенуза (c): " << c << endl;
        cout << "Периметр (P):   " << p << endl;
        cout << "------------------------------" << endl;
    }
};

int main() {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    TriangleTask labWork;
    double leg1, leg2;

    cout << "Питання для самостійного опрацювання: Прямокутний трикутник\n";

    cout << "Введіть перший катет (a): ";
    cin >> leg1;

    cout << "Введіть другий катет (b): ";
    cin >> leg2;

    labWork.analyzeAndCalculate(leg1, leg2);

    cout << "\nНатисніть Enter для виходу...";
    cin.ignore(); cin.get();

    return 0;
}