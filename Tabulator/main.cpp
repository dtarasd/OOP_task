#include <iostream>
#include <cmath>
#include <iomanip>
#include <windows.h>

using namespace std;

class FunctionTabulator {
public:
    void buildTable(int choice, double start, double end, double step) {
        cout << "\n-----------------------------" << endl;
        cout << "   X      |      Y           " << endl;
        cout << "-----------------------------" << endl;

        for (double x = start; x <= end; x += step) {
            double y = 0;
            switch (choice) {
                case 1:
                    y = sin(x);
                    break;
                case 2:
                    y = cos(x);
                    break;
                case 3:
                    y = pow(x, 2);
                    break;
                case 4:
                    y = sqrt(x);
                    if (x < 0) {
                        cout << setw(10) << x << " |   Error" << endl;
                        continue;
                    }
                    break;
                default:
                    return;
            }
            cout << fixed << setprecision(4)
                 << setw(10) << x << " | "
                 << setw(10) << y << endl;
        }
        cout << "-----------------------------" << endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    FunctionTabulator lab;
    int menuChoice;
    double a, b, h;

    do {
        cout << "\n=== MENU ===" << endl;
        cout << "1. y = sin(x)" << endl;
        cout << "2. y = cos(x)" << endl;
        cout << "3. y = x^2" << endl;
        cout << "4. y = sqrt(x)" << endl;
        cout << "0. Exit" << endl;
        cout << "Choice: ";
        cin >> menuChoice;

        if (menuChoice == 0) break;

        if (menuChoice >= 1 && menuChoice <= 4) {
            cout << "Start (a): "; cin >> a;
            cout << "End (b): "; cin >> b;
            cout << "Step (h): "; cin >> h;

            if (h <= 0) {
                cout << "Step must be > 0" << endl;
            } else {
                lab.buildTable(menuChoice, a, b, h);
            }
        } else {
            cout << "Invalid choice" << endl;
        }

    } while (menuChoice != 0);

    return 0;
}