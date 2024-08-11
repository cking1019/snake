#pragma once

#include <vector>
#include "easyx/graphics.h"
#include "food.h"
#include "head.h"

class Snake
{
private:
    std::string name;
    Head head;
    std::vector<Node> body;
    char dir;
    int speed;
public:
    Snake();
    Snake(std::string name);
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

    void setName(std::string name) {
        this->name = name;
    }
    std::string getName() {
        return this->name;
    }

};