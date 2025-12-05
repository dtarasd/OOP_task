#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

class RingCalc {
public:
    double getRingArea(double outerRadius, double innerRadius) {
        if (outerRadius <= 0 || innerRadius <= 0) {
            cout << "Помилка: Радіуси повинні бути більше нуля!" << endl;
            return -1;
        }
        if (outerRadius <= innerRadius) {
            cout << "Помилка: R має бути більшим за r!" << endl;
            return -1;
        }
        return M_PI * (pow(outerRadius, 2) - pow(innerRadius, 2));
    }
};

int main() {

    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);


    RingCalc myRing;
    double R, r;

    cout << "Обчислення площі кільця" << endl;

    cout << "Введіть зовнішній радіус (R): ";
    if (!(cin >> R)) return 0;

    cout << "Введіть внутрішній радіус (r): ";
    if (!(cin >> r)) return 0;

    double result = myRing.getRingArea(R, r);

    if (result != -1) {
        cout << "Площа кільця: " << result << endl;
    }

    cout << "\nНатисніть Enter, щоб вийти...";
    cin.ignore(); cin.get();

    return 0;
}