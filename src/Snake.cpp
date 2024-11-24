#include "Snake.hpp"

Snake::Snake() {
    m_name = "Demo";
    m_head = Head();
    m_head.nd = Node(7, 3);
    m_body = {Node(5, 3), Node(6, 3)};
    m_speed = 1;
    m_dir = 'R';

    std::cout << "set the name of snake is " << m_name << std::endl;
}

Snake::~Snake() {
}

void Snake::move() {
    int numNd = m_body.size() - 1;
    for(int i = numNd; i > 0; i--) m_body[i] = m_body[i - 1];
    m_body[0] = m_head.nd;
    switch(m_dir) {
    case 'U': 
        m_head.nd.y -= m_speed; break;
    case 'D': 
        m_head.nd.y += m_speed; break;
    case 'L':
        m_head.nd.x -= m_speed; break;
    case 'R':
        m_head.nd.x += m_speed; break;
    }
    if(m_head.nd.x < 0)  m_head.nd.x = 24;
    if(m_head.nd.x > 24) m_head.nd.x = 0;
    if(m_head.nd.y < 0)  m_head.nd.y = 24;
    if(m_head.nd.y > 24) m_head.nd.y = 0;
}

bool Snake::eat_food(Food*& food) {
    if(m_head.nd == food->nd) {
        mciSendString(_T("close food_music"), NULL, 0, NULL); // 关闭音乐
        mciSendString(_T("open static/music-food.mp3 alias food_music"), NULL, 0, NULL);
        mciSendString(_T("play food_music"), NULL, 0, NULL);
        m_body.insert(m_body.begin(), food->nd);
        return true;
    }
    return false;
}