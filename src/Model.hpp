#pragma once

enum State {
    BEGIN,
    STOP,
    IS_RUNNING,
    EXIT
};

struct Window {
    int width, height;
    int unit;
    Window(){};
    Window(int w, int h, int u):width(w), height(h), unit(u){}
};

struct Node
{
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
    
    const bool operator!=(const Node& p) {
        return x != p.x || y != p.y;
    }
};

struct Head {
    Node nd;
    Head(){}
    Head(Node &node) {
        nd = node;
    }
};

struct Food {
    Node nd;
    Food() {
        nd.x = rand() % 25;
        nd.y = rand() % 25;
    }
    Food(Node &node) {
        nd = node;
    } 
};