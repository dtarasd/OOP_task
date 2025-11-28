#include <iostream>
#include "root.h"
#include <windows.h>

using namespace std;
int main() {
    SetConsoleOutputCP(65001);
    uint32_t slovo = 0x12345678;

    uint32_t zsuvi_1bait = zsuvi_vpravo_1bait(slovo);
    uint32_t zsuvi_2baiti = zsuvi_vpravo_2baiti(slovo);

    std::cout << "Вихідне слово: 0x" << std::hex << slovo << std::endl;
    std::cout << "Циклічний зсув на 1 байт вправо: 0x" << std::hex << zsuvi_1bait << std::endl;
    std::cout << "Циклічний зсув на 2 байти вправо: 0x" << std::hex << zsuvi_2baiti << std::endl;

    return 0;
}
