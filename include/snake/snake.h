#pragma once

#include <food.h>
#include <vector>
#include <graphics.h>
#include <body.h>
#include <head.h>

class Snake
{
public:
    Head head;
    std::vector<Body> body;

    char dir;
    int speed;
    
    Snake();
    void move();
    bool eat_food(Food& food);
};