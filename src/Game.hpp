#pragma once

#include "easyx/Graphics.hpp"
#include <map>
#include <ctime>
#include <iostream>
#include <vector>
#include <thread>
#include "Model.hpp"

class Snake
{
public:
    std::string m_name;
    Head m_head;
    std::vector<Node> m_body;
    char m_dir;
    int m_speed;
};

class Game
{
public:
    Window m_win;
    State m_gameState;

    Snake* m_snake;
    Food* m_food;
    int m_grade;
    int m_frame;
    std::map<std::string, IMAGE> m_imgs;

    Game();
    void run();
    void controller();
    void draw();
};
