#pragma once

#include "easyx/Graphics.hpp"
#include "Snake.hpp"
#include <map>
#include <ctime>
#include <iostream>
#include "Model.hpp"

class Game
{
public:
    Window m_win;
    State m_state;

    Snake* m_snake;
    Food* m_food;
    int m_grade;
    int m_frame;
    std::map<std::string, IMAGE> m_imgs;

    Game();
    void produce_food();
    void run();
    void controller();
    void draw();
};
