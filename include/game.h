#pragma once

#include <snake.h>
#include <food.h>
#include <graphics.h>
#include <chrono>
#include <iostream>

class Game
{
public:
    int width, height;
    int unit;
    int grade;
    bool is_running;
    int frame;
    
    Snake snake;
    Food food;
    IMAGE up_img, dw_img, lf_img, rt_img, bd_img, fd_img, bg_img;

    Game();
    void produce_food();
    void run();
    void controller();
    void draw();
    void load_image();
};
