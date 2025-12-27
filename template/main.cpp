#include <iostream>
#include <windows.h>

template <typename T1, typename T2>

class Pair {
private:
    T1 first;
    T2 second;

public:
    // Конструктор ініціалізації
    Pair(T1 f, T2 s) : first(f), second(s) {}

    // Геттери для отримання значень
    T1 getFirst() const { return first; }
    T2 getSecond() const { return second; }

    // Сеттери для зміни значень
    void setFirst(T1 f) { first = f; }
    void setSecond(T2 s) { second = s; }

    // Метод для виводу пари на екран
    void display() const {
        std::cout << "(" << first << ", " << second << ")" << std::endl;
    }
};

int main() {
    SetConsoleOutputCP(65001);

    // 1. Пара типів int та double
    Pair<int, double> p1(10, 20.5);
    std::cout << "Pair 1: ";
    p1.display();

    // 2. Пара типів string та int
    Pair<std::string, int> p2("Вік", 21);
    std::cout << "Pair 2: ";
    p2.display();

    // Зміна значень через сеттер
    p2.setSecond(22);
    std::cout << "Оновлена Pair 2: ";
    p2.display();

    return 0;
}