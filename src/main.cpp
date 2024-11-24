#include "Snake.hpp"
#include "Game.hpp"

#include "easyx/Graphics.hpp"
#include <thread>

int main(int argc, char* args[])
{
    auto game = new Game();
    
    initgraph(game->m_win.width, game->m_win.height);
    BeginBatchDraw();
    
    std::thread th1([=](){game->controller();});
    std::thread th2([=](){game->draw();});
    th1.detach();
    th2.detach();

    while (true)
    {
        game->run();
        Sleep(100);
    }
    return 0;
}
