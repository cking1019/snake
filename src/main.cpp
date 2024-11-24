#include "Snake.hpp"
#include "Game.hpp"

#include "easyx/Graphics.hpp"
#include <thread>

int main(int argc, char* args[])
{
    auto game = new Game();
    Snake snake;
    game->m_snake = &snake; 
    game->m_food = new Food();

    // 播放背景音乐。第一个参数的格式为 "open 文件路径 alias 别名"
    mciSendString(_T("open static/music.mp3 alias bg_music"), NULL, 0, NULL);
    mciSendString(_T("play bg_music repeat"), NULL, 0, NULL);
    initgraph(game->m_win.width, game->m_win.height);
    BeginBatchDraw();
    
    std::thread th1([game](){game->controller();});
    std::thread th2([game](){game->draw();});
    th1.detach();
    th2.detach();

    while (game->m_state != EXIT)
    {
        while (game->m_state == BEGIN) {
            game->run();
            Sleep(1000 / game->m_frame);
        }
    }
    delete game;
    return 0;
}
