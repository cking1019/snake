#include "Game.hpp"

#include "easyx/Graphics.hpp"
#include <thread>

int main(int argc, char* args[])
{
    auto game = new Game();
    
    initgraph(game->m_win.width, game->m_win.height);
    BeginBatchDraw();
    
    std::thread th1([=]{game->controller();});
    std::thread th2([=]{game->draw();});
    std::thread th3([=]{game->run();});
    th1.join();
    th2.join();
    th3.join();
    
    return 0;
}
