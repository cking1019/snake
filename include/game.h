#pragma once

#include <iostream>
#include <map>
#include "snake/snake.h"
#include "snake/food.h"
#include "easyx/graphics.h"

enum State {
    BEGIN,
    STOP
};

struct Window {
    int width, height;
    int unit;
    Window(){};
    Window(int w, int h, int u):width(w), height(h), unit(u){}
};

class Game
{
private:
    Window window;
    State state;
    int grade;
    int frame;
    std::map<std::string, IMAGE> imgs;

    Snake* snake;
    Food* food;
public:
    Game();
    void produce_food();
    void run();
    void controller();
    void draw();

    void setState(State s);
    State getState();

    void setGrade(int grade);
    int getGrade();
    
    void setFrame(int frame);
    int getFrame();
    
    void setWindow(Window w);
    Window getWindow();

    void setImgs();
    std::map<std::string, IMAGE> getImgs();
};
