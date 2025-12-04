#include <iostream>
#include <string>
#include <Windows.h>

using namespace std;

class Train {
public:
    string destination;
    int number;
    string time;
};

typedef Train Ttrain;

int main() {
 
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int SIZE = 5;
    Ttrain mas[SIZE];
    Ttrain temp;

    cout << "Введіть данні для " << SIZE << " поїздів." << endl; 
    cout << "УВАГА: Вводьте назви міст без пробілів!" << endl;

    // ВВЕДЕННЯ 
    for (int i = 0; i < SIZE; i++) {
        cout << "\nПоїзд номер " << (i + 1) << endl;

        cout << "  Пункт призначення: ";
        cin >> mas[i].destination;

        cout << "  Номер поїзда: ";
        while (!(cin >> mas[i].number)) {
            cout << "  Помилка! Введіть число: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        cout << "  Час (ГГ:ХХ): ";
        cin >> mas[i].time;
    }

    // СОРТУВАННЯ ЗА НОМЕРАМИ
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (mas[j].number > mas[j + 1].number) {
                temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }

    cout << "\n=== Список за номерами ===" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "№" << mas[i].number << "\t -> " << mas[i].destination << "\t (" << mas[i].time << ")" << endl;
    }

    // ПОШУК
    int searchNum;
    cout << "\nВведіть номер для пошуку: ";
    cin >> searchNum;

    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        if (mas[i].number == searchNum) {
            cout << "ЗНАЙДЕНО: Поїзд " << mas[i].number << " їде в місто "
                 << mas[i].destination << " о " << mas[i].time << endl;
            found = true;
        }
    }
    if (!found) cout << "Не знайдено." << endl;

    // СОРТУВАННЯ ЗА МІСТАМИ
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            bool swap = false;
            if (mas[j].destination > mas[j + 1].destination) {
                swap = true;
            } else if (mas[j].destination == mas[j + 1].destination) {
                if (mas[j].time > mas[j + 1].time) {
                    swap = true;
                }
            }

            if (swap) {
                temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }

    cout << "\n=== Список за містами ===" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << mas[i].destination << "\t\t" << mas[i].time << "\t №" << mas[i].number << endl;
    }

    system("pause");
    return 0;
}
