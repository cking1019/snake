#pragma once

#include <iostream>
#include <chrono>
#include "node.h"

class Food: public Node 
{
public:
    Food();
    Food(int x, int y);
};