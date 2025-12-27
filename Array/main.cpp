#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

// Шаблонна функція для пошуку елементів у діапазоні [min, max]
template <typename T>
void findInRange(const T arr[], int size, T minVal, T maxVal) {
    bool found = false;
    std::cout << "Елементи в діапазоні [" << minVal << ", " << maxVal << "]: ";

    for (int i = 0; i < size; ++i) {
        if (arr[i] >= minVal && arr[i] <= maxVal) {
            std::cout << arr[i] << " ";
            found = true;
        }
    }

    if (!found) {
        std::cout << "не знайдено";
    }
    std::cout << std::endl;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    // 1. Перевірка цілих чисел (int)
    int intArr[] = {10, 25, 5, 40, 18, 30};
    int intSize = sizeof(intArr) / sizeof(intArr[0]);
    std::cout << "Цілі числа (int)" << std::endl;
    findInRange(intArr, intSize, 15, 35);

    // 2. Перевірка чисел з плаваючою точкою (double)
    double doubleArr[] = {1.5, 4.8, 2.3, 9.1, 0.5, 3.3};
    int doubleSize = sizeof(doubleArr) / sizeof(doubleArr[0]);
    std::cout << "\nДійсні числа (double)" << std::endl;
    findInRange(doubleArr, doubleSize, 2.0, 5.0);

    // 3. Перевірка символів (char)
    char charArr[] = {'a', 'z', 'm', 'c', 'f', 'r'};
    int charSize = sizeof(charArr) / sizeof(charArr[0]);
    std::cout << "\nСимволи (char)" << std::endl;
    findInRange(charArr, charSize, 'd', 'p');

    return 0;
}