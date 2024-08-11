#pragma once

#include <vector>
#include "easyx/graphics.h"
#include "food.h"
#include "head.h"

class Snake
{
private:
    Head head;
    std::vector<Node> body;
    char dir;
    int speed;
public:
    Snake();
    ~Snake();
    void move();
    bool eat_food(Food*& food);

    void setHead(Head head);
    Head getHead();

    void setBody(std::vector<Node>& body);
    std::vector<Node> getBody();

    void setDir(char dir);
    char getDir();

    void setSpeed(int s);
    int getSpeed();

};