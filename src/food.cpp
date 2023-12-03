#include <food.h>
#include <game.h>

Food::Food() {
    x = rand() % (24 + 1);
    x = rand() % (24 + 1);
}

Food::Food(int x, int y) {
    x = x;
    y = y;
}