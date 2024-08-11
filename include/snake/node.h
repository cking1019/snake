#pragma once

class Node
{
public:
    int x, y;
    Node(){}
    Node(int xx, int yy):x(xx), y(yy){}
    const Node operator=(const Node& p) {
        x = p.x;
        y = p.y;
        return *this;
    }
    const bool operator==(const Node& p) {
        return x == p.x && y == p.y;
    }
};