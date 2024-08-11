#include <thread>
#include <game.h>
#include <Windows.h>

int main(int argc, char* args[])
{
    auto game = new Game();
    // 播放背景音乐。第一个参数的格式为 "open 文件路径 alias 别名"
    mciSendString(_T("open static/music.mp3 alias bg_music"), NULL, 0, NULL);
    mciSendString(_T("play bg_music repeat"), NULL, 0, NULL);
    initgraph(game->getWindow().width, game->getWindow().height);
    
    BeginBatchDraw();
    
    std::thread th1([game](){game->controller();});
    std::thread th2([game](){game->draw();});
    th1.detach();
    th2.detach();

    while (true)
    {
        while (game->getState() == BEGIN) {
            game->run();
            Sleep(1000 / game->getFrame());
        }
    }
    mciSendString(_T("close bg_music"), NULL, 0, NULL);
    return 0;
}
