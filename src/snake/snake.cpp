#include <snake.h>
#include <game.h>

Snake::Snake() {
    head = Head(7, 3);
    body = {Body(5, 3), Body(6, 3)};
    speed = 1;
    dir = 'R';
}

bool Snake::eat_food(Food& food) {
    if(head == food) {
        mciSendString(_T("close food_music"), NULL, 0, NULL); // 关闭音乐
        mciSendString(_T("open static/music-food.mp3 alias food_music"), NULL, 0, NULL);
        mciSendString(_T("play food_music"), NULL, 0, NULL);
        int x = food.x;
        int y = food.y;
        body.insert(body.begin(), Body(x, y));
        return true;
    }
    return false;
}


void Snake::move() {
    for(int i = body.size() - 1; i > 0; i--) {
        body[i] = body[i - 1];
    }
    body[0].x = head.x;
    body[0].y = head.y;
    switch(dir) {
        case 'U': 
            head.y -= speed;
            break;
        case 'D': 
            head.y += speed;
            break;
        case 'L':
            head.x -= speed; 
            break;
        case 'R':
            head.x += speed;
            break;
    }
    if(head.x < 0) head.x = 24;
    if(head.x > 24) head.x = 0;
    if(head.y < 0) head.y = 24;
    if(head.y > 24) head.y = 0;
}
