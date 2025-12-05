#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;

class SimpsonIntegral {
public:
    double func(int type, double x) {
        switch (type) {
            case 1: return sin(x);
            case 2: return cos(x);
            case 3: return x * x;
            case 4: return exp(x);
            case 5: return 1.0 / x;
            default: return 0;
        }
    }

    double calculate(int type, double a, double b, int n) {
        if (n % 2 != 0) n++;
        double h = (b - a) / n;
        double sum = func(type, a) + func(type, b);

        for (int i = 1; i < n; i++) {
            double x = a + i * h;
            if (i % 2 == 0) {
                sum += 2 * func(type, x);
            } else {
                sum += 4 * func(type, x);
            }
        }
        return sum * (h / 3.0);
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    SimpsonIntegral simpson;
    int choice, n;
    double a, b;

    do {
        cout << "\n1. y = sin(x)" << endl;
        cout << "2. y = cos(x)" << endl;
        cout << "3. y = x^2" << endl;
        cout << "4. y = e^x" << endl;
        cout << "5. y = 1/x" << endl;
        cout << "0. Вихід" << endl;
        cout << "Ваш вибір: ";
        cin >> choice;

        if (choice == 0) break;

        if (choice >= 1 && choice <= 5) {
            cout << "a: "; cin >> a;
            cout << "b: "; cin >> b;
            cout << "n: "; cin >> n;

            if (n > 0) {
                if (choice == 5 && (a * b <= 0 && a != b)) {
                    cout << "Error: 0 v intervali" << endl;
                } else {
                    cout << "Result: " << simpson.calculate(choice, a, b, n) << endl;
                }
            } else {
                cout << "n maye buty > 0" << endl;
            }
        }

    } while (choice != 0);

    return 0;
}