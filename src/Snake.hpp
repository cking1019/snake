#pragma once
#include <string>
#include <vector>
#include <windows.h>
#include <iostream>

#include "easyx/Graphics.hpp"
#include "Model.hpp"

class Snake
{
public:
    std::string m_name;
    Head m_head;
    std::vector<Node> m_body;
    char m_dir;
    int m_speed;

    Snake();
    ~Snake();
    void move();
    bool eat_food(Food*& food);
};