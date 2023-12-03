#include <thread>
#include <game.h>

void run() {
    auto game = new Game();
    game->load_image();
    // 播放背景音乐。第一个参数的格式为 "open 文件路径 alias 别名"
    mciSendString(_T("open static/music.mp3 alias bg_music"), NULL, 0, NULL);
    mciSendString(_T("play bg_music repeat"), NULL, 0, NULL);
    initgraph(game->width, game->height);
    BeginBatchDraw();
    
    std::thread th1([game](){game->controller();});
    std::thread th2([game](){game->draw();});
    th1.detach();
    th2.detach();

    while (true)
    {
        while (game->is_running) {
            game->run();
            Sleep(1000 / game->frame);
        }
    }
}

int main(int argc, char* args[])
{
    run();
    return 0;
}
