#include <iostream>
#include <string>
#include <windows.h> //

using namespace std;

int main() {

    SetConsoleOutputCP(65001);

    //  ЗАДАЧА 1
    cout << "--- Задача 1: Масив рядків ---" << endl;

    string words[5];

    words[0] = "Перший";
    words[1] = "Другий";
    words[2] = "Третій";
    words[3] = "Четвертий";
    words[4] = "П'ятий";

    cout << "Всі елементи масиву слів:" << endl;


    for (int i = 0; i < 5; i++) {
        cout << words[i] << endl;
    }
    cout << endl;


    int numbers[3];
    numbers[0] = 1;
    numbers[1] = 15;
    numbers[2] = 2;


    //  ЗАДАЧА 2
    cout << "--- Задача 2: Вивід усіх елементів ---" << endl;

    cout << "Числа у масиві:" << endl;
    for (int i = 0; i < 3; i++) {
        cout << numbers[i] << endl;
    }
    cout << endl;


    //  ЗАДАЧА 3
    cout << "--- Задача 3: Сума елементів ---" << endl;

    int sum = 0;
    for (int i = 0; i < 3; i++) {
        sum += numbers[i];
    }
    cout << "Сума всіх чисел: " << sum << endl << endl;


    //  ЗАДАЧА 4
    cout << "--- Задача 4: Кількість елементів ---" << endl;

    int count = sizeof(numbers) / sizeof(numbers[0]);
    cout << "Кількість елементів у масиві: " << count << endl;

    return 0;
}