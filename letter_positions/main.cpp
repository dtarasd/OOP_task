#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    string s;
    char c;

    cout << "Введіть рядок: ";
    getline(cin, s);

    cout << "Введіть літеру для пошуку: ";
    cin >> c;

    cout << "Позиції літери '" << c << "': ";

    bool found = false;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == c) {
            cout << i << " ";
            found = true;
        }
    }

    if (!found) {
        cout << "літера не знайдена.";
    }

    return 0;
}