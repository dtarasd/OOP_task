#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    string s;

    cout << "Введіть рядок: ";
    getline(cin, s);

    bool isPalindrome = true;
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (s[left] != s[right]) {
            isPalindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (isPalindrome)
        cout << "Рядок є паліндромом." << endl;
    else
        cout << "Рядок НЕ є паліндромом." << endl;

    return 0;
}