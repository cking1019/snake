#include <food.h>

Food::Food() {
    this->x = rand() % (24 + 1);
    this->x = rand() % (24 + 1);
}

Food::Food(int x, int y) {
    this->x = x;
    this->y = y;
}