#include "root.h"


uint32_t zsuvi_vpravo_1bait(uint32_t slovo) {
    return (slovo >> 8) | (slovo << 24);
}


uint32_t zsuvi_vpravo_2baiti(uint32_t slovo) {
    return (slovo >> 16) | (slovo << 16);
}
