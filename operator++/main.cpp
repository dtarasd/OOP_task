#include <iostream>
#include <Windows.h>
class coord {
    int x, y;
public:
    coord() { x = 0; y = 0; }
    coord(int i, int j) { x = i; y = j; }
    void get_xy(int &i, int &j) { i = x; j = y; }
    void show_coord() { std::cout << "(" << x << ", " << y << ")"; }

    // 1. Оголошення префіксного оператора-функції (++obj)
    coord operator++();

    // 2. Оголошення постфіксного оператора-функції (obj++)
    coord operator++(int);
};

coord coord::operator++() {
    x++;
    y++;
    return *this;
}


coord coord::operator++(int) {
    coord temp = *this;
    x++;
    y++;
    return temp;
}


int main() {

    SetConsoleOutputCP(65001);

    std::cout << "Початкове a: (10, 10)\n";
    std::cout << "Виклик префіксного (++a): a = (11, 11), c = (11, 11)\n";
    coord a(10, 10);
    coord b(20, 20);

    std::cout << "Початкове a: ";
    a.show_coord();
    std::cout << std::endl;


    
    std::cout << "Виклик префіксного (++a): ";
    coord c = ++a;
    std::cout << "a = "; a.show_coord();
    std::cout << ", c = "; c.show_coord();
    std::cout << std::endl;

    std::cout << "Початкове b: ";
    b.show_coord();
    std::cout << std::endl;

   
    std::cout << "Виклик постфіксного (b++): ";
    coord d = b++;
    std::cout << "b = "; b.show_coord();
    std::cout << ", d = "; d.show_coord();
    std::cout << std::endl;

    return 0;
}
