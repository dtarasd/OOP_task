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

    cout << "¬‚Â‰≥Ú¸ ‰‡ÌÌ≥ ‰Îˇ " << SIZE << " ÔÓøÁ‰≥‚." << endl;
    cout << "”¬¿√¿: ¬‚Ó‰¸ÚÂ Ì‡Á‚Ë Ï≥ÒÚ ·ÂÁ ÔÓ·≥Î≥‚!" << endl;

    // ¬¬≈ƒ≈ÕÕﬂ
    for (int i = 0; i < SIZE; i++) {
        cout << "\nœÓøÁ‰ ÌÓÏÂ " << (i + 1) << endl;

        cout << "  œÛÌÍÚ ÔËÁÌ‡˜ÂÌÌˇ: ";
        cin >> mas[i].destination;

        cout << "  ÕÓÏÂ ÔÓøÁ‰‡: ";
        while (!(cin >> mas[i].number)) {
            cout << "  œÓÏËÎÍ‡! ¬‚Â‰≥Ú¸ ˜ËÒÎÓ: ";
            cin.clear();
            cin.ignore(10000, '\n');
        }

        cout << "  ◊‡Ò (√√:’’): ";
        cin >> mas[i].time;
    }

    // —Œ–“”¬¿ÕÕﬂ «¿ ÕŒÃ≈–¿Ã»
    for (int i = 0; i < SIZE - 1; i++) {
        for (int j = 0; j < SIZE - i - 1; j++) {
            if (mas[j].number > mas[j + 1].number) {
                temp = mas[j];
                mas[j] = mas[j + 1];
                mas[j + 1] = temp;
            }
        }
    }

    cout << "\n=== —ÔËÒÓÍ Á‡ ÌÓÏÂ‡ÏË ===" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << "π" << mas[i].number << "\t -> " << mas[i].destination << "\t (" << mas[i].time << ")" << endl;
    }

    // œŒÿ” 
    int searchNum;
    cout << "\n¬‚Â‰≥Ú¸ ÌÓÏÂ ‰Îˇ ÔÓ¯ÛÍÛ: ";
    cin >> searchNum;

    bool found = false;
    for (int i = 0; i < SIZE; i++) {
        if (mas[i].number == searchNum) {
            cout << "«Õ¿…ƒ≈ÕŒ: œÓøÁ‰ " << mas[i].number << " ø‰Â ‚ Ï≥ÒÚÓ "
                 << mas[i].destination << " Ó " << mas[i].time << endl;
            found = true;
        }
    }
    if (!found) cout << "ÕÂ ÁÌ‡È‰ÂÌÓ." << endl;

    // —Œ–“”¬¿ÕÕﬂ «¿ Ã≤—“¿Ã»
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

    cout << "\n=== —ÔËÒÓÍ Á‡ Ï≥ÒÚ‡ÏË ===" << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << mas[i].destination << "\t\t" << mas[i].time << "\t π" << mas[i].number << endl;
    }

    system("pause");
    return 0;
}