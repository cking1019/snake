#include <snake.h>

Snake::Snake() {
    this->head = Head(7, 3);
    this->body = {Node(5, 3), Node(6, 3)};
    this->speed = 1;
    this->dir = 'R';
}

Snake::Snake(std::string name) : Snake() {
    this->name = name;
    std::cout << "set the name of snake is " << name << std::endl;
}

Snake::~Snake() {

}

void Snake::setHead(Head h) {
    this->head = h;
}

Head Snake::getHead() {
    return this->head;
}

void Snake::setBody(std::vector<Node>& body) {
    this->body = body;
}

std::vector<Node> Snake::getBody() {
    return this->body;
}

void Snake::setDir(char dir) {
    this->dir = dir;
}

char Snake::getDir() {
    return this->dir;
}

void Snake::setSpeed(int s) {
    this->speed = s;
}

int Snake::getSpeed() {
    return this->speed;
}

bool Snake::eat_food(Food*& food) {
    if(head.x == food->x && head.y == food->y) {
        mciSendString(_T("close food_music"), NULL, 0, NULL); // 关闭音乐
        mciSendString(_T("open static/music-food.mp3 alias food_music"), NULL, 0, NULL);
        mciSendString(_T("play food_music"), NULL, 0, NULL);
        int x = food->x;
        int y = food->y;
        this->body.insert(this->body.begin(), Node(x, y));
        return true;
    }
    return false;
}


void Snake::move() {
    for(int i = body.size() - 1; i > 0; i--) {
        this->body[i] = this->body[i - 1];
    }
    this->body[0].x = this->head.x;
    this->body[0].y = this->head.y;
    switch(dir) {
        case 'U': 
            this->head.y -= this->speed;
            break;
        case 'D': 
            this->head.y += this->speed;
            break;
        case 'L':
            this->head.x -= this->speed; 
            break;
        case 'R':
            this->head.x += this->speed;
            break;
    }
    if(this->head.x < 0) this->head.x = 24;
    if(this->head.x > 24) this->head.x = 0;
    if(this->head.y < 0) this->head.y = 24;
    if(this->head.y > 24) this->head.y = 0;
}
