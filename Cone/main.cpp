#include <iostream>
#include <vector>
#include <string>
#include <windows.h>
#include <cmath>

class RevolutionSolid {
protected:
    std::string name;
    double radius;
public:
    RevolutionSolid(std::string n, double r) : name(n), radius(r) {}
    virtual ~RevolutionSolid() {}

    virtual void displayInfo() const {
        std::cout << "Фігура: " << name << " | Радіус основи: " << radius << std::endl;
    }
};

// Похідний клас: Конус
class Cone : public RevolutionSolid {
private:
    double height;
public:
    Cone(double r, double h)
        : RevolutionSolid("Конус", r), height(h) {}

    // Обчислення за теоремою Піфагора
    double getSlantHeight() const {
        return std::sqrt(radius * radius + height * height);
    }

    void displayInfo() const override {
        std::cout << "Фігура: " << name
                  << " | Радіус: " << radius
                  << " | Висота: " << height
                  << " | Твірна: " << getSlantHeight() << std::endl;
    }
};

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    std::vector<RevolutionSolid*> shapes;

    shapes.push_back(new RevolutionSolid("Циліндр (загальний)", 5.0));
    shapes.push_back(new Cone(3.0, 4.0)); // Конус з радіусом 3 і висотою 4
    shapes.push_back(new Cone(10.5, 12.0));

    std::cout << "Дані про фігури обертання" << std::endl;

    // Поліморфний вивід
    for (const auto& shape : shapes) {
        shape->displayInfo();
    }

    for (auto shape : shapes) {
        delete shape;
    }

    return 0;
}