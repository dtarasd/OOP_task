#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <typeinfo>
#include <locale>

class House {
protected:
    int floors;
    std::string address;
public:
    House(int f, const std::string& a) : floors(f), address(a) {}

    virtual void displayData() const {
        std::cout << "Тип: Будинок" << std::endl;
        std::cout << "  Адреса: " << address << std::endl;
        std::cout << "  Поверхів: " << floors << std::endl;
    }
    virtual ~House() = default;
};

class AcademicBuilding : public House {
private:
    int classrooms;
    std::string faculty;
public:
    AcademicBuilding(int f, const std::string& a, int c, const std::string& fac)
        : House(f, a), classrooms(c), faculty(fac) {}

    void displayData() const override {
        std::cout << "Тип: Навчальний корпус" << std::endl;
        std::cout << "  Адреса: " << address << std::endl;
        std::cout << "  Поверхів: " << floors << std::endl;
        std::cout << "  Аудиторій: " << classrooms << std::endl;
        std::cout << "  Факультет: " << faculty << std::endl;
    }
};

void task1_demo() {
    std::cout << "Демонстрація ієрархії Будинок/Корпус" << std::endl;

    std::vector<House*> buildings;

    buildings.push_back(new House(16, "вул. Лесі Українки, 12"));
    buildings.push_back(new AcademicBuilding(5, "Херсонський провулок, 3", 45, "інженерія програмного забеспечення"));

    for (const auto& building : buildings) {
        building->displayData();
        std::cout << "--------------------" << std::endl;
    }

    for (const auto& building : buildings) {
        delete building;
    }
}

class DigitalDevice {
protected:
    std::string brand;
    int year;
public:
    DigitalDevice(const std::string& b, int y) : brand(b), year(y) {}

    virtual void showInfo() const {
        std::cout << "Тип: Цифровий пристрій" << std::endl;
        std::cout << "  Бренд: " << brand << std::endl;
        std::cout << "  Рік випуску: " << year << std::endl;
    }
    virtual ~DigitalDevice() = default;
};

class MobilePhone : public DigitalDevice {
private:
    std::string os; // Operating System
    int batteryCapacity;
public:
    MobilePhone(const std::string& b, int y, const std::string& o, int bc)
        : DigitalDevice(b, y), os(o), batteryCapacity(bc) {}

    void showInfo() const override {
        std::cout << "Тип: Мобільний телефон" << std::endl;
        std::cout << "  Бренд: " << brand << std::endl;
        std::cout << "  Рік випуску: " << year << std::endl;
        std::cout << "  ОС: " << os << std::endl;
        std::cout << "  Батарея (мАг): " << batteryCapacity << std::endl;
    }
};

void task2_demo() {
    std::cout << "\nДемонстрація ієрархії Пристрій/Телефон" << std::endl;

    std::vector<DigitalDevice*> devices;

    devices.push_back(new DigitalDevice("AppleWatch", 2023));
    devices.push_back(new MobilePhone("iPhone 17", 2025, "IOS", 5000));

    for (const auto& device : devices) {
        device->showInfo();
        std::cout << "--------------------" << std::endl;
    }

    for (const auto& device : devices) {
        delete device;
    }
}

template <typename T>
std::vector<T> findInRange(const std::vector<T>& arr, const T& min_val, const T& max_val) {
    std::vector<T> results;
    for (const T& item : arr) {
        if (item >= min_val && item <= max_val) {
            results.push_back(item);
        }
    }
    return results;
}

void task3_demo() {
    std::cout << "\nДемонстрація шаблонної функції findInRange" << std::endl;

    std::vector<int> nums = {10, 25, 4, 33, 15, 8, 40};
    int min_int = 15;
    int max_int = 35;
    auto res_int = findInRange(nums, min_int, max_int);

    std::cout << "Діапазон [" << min_int << ", " << max_int << "]. Знайдено (int): ";
    for (int n : res_int) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    std::vector<std::string> words = {"apple", "banana", "kiwi", "grape", "orange"};
    std::string min_str = "b";
    std::string max_str = "o";
    auto res_str = findInRange(words, min_str, max_str);

    std::cout << "Діапазон [b, o]. Знайдено (string): ";
    for (const auto& w : res_str) {
        std::cout << w << " ";
    }
    std::cout << std::endl;
}

template <typename T1, typename T2>
class Pair {
private:
    T1 first;
    T2 second;
public:
    Pair(const T1& f, const T2& s) : first(f), second(s) {}

    void printPair() const {
        std::cout << "(" << first << ", " << second << ") "
                  << " [Типи: " << typeid(first).name() << ", "
                  << typeid(second).name() << "]" << std::endl;
    }
};

void task4_demo() {
    std::cout << "\nДемонстрація шаблонного класу Pair" << std::endl;

    Pair<int, double> p1(10, 3.14);
    std::cout << "Пара 1: ";
    p1.printPair();
    Pair<std::string, int> p2("Вік студента:", 20);
    std::cout << "Пара 2: ";
    p2.printPair();
}

int main() {
    std::setlocale(LC_ALL, "uk_UA.UTF-8");

    system("chcp 65001");
    task1_demo();
    task2_demo();
    task3_demo();
    task4_demo();

    return 0;
}