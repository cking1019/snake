#include <game.h>


// 指令处理，使用一个独立的线程操作
void Game::controller()
{
    while (true)
    {
        ExMessage msg;
        while(peekmessage(&msg, EM_KEY)) {
            if(msg.message == WM_KEYDOWN) {
                auto key = msg.vkcode;
                auto dir = snake.dir;
                auto speed = snake.speed;
                if(dir == 'L' && key == VK_RIGHT) continue;
                if(dir == 'U' && key == VK_DOWN)  continue;
                if(dir == 'R' && key == VK_LEFT)  continue;
                if(dir == 'D' && key == VK_UP)    continue;
                if(!is_running) {
                    if(key == VK_RIGHT || key == VK_DOWN|| key == VK_LEFT|| key == VK_UP)
                        continue;
                }
                switch(key) {
                    case VK_UP:
                        snake.dir ='U';
                        break;
                    case VK_DOWN:
                        snake.dir ='D';
                        break;
                    case VK_LEFT:
                        snake.dir ='L';
                        break;
                    case VK_RIGHT:
                        snake.dir ='R';
                        break;
                    case VK_F1:
                        if(frame < 100) {
                            frame++;
                            std::cout << "speed up\n";
                        }
                        break;
                    case VK_F2:
                        if(frame > 1) {
                            frame--;
                            std::cout << "speed dw\n";
                        }
                        break;
                    case VK_SPACE: 
                        is_running = !is_running;
                        if(!is_running) {
                            std::cout << "pause\n";
                        } else{
                            std::cout << "begin\n";
                        }
                        break;
                    case VK_ESCAPE:
                        exit(0);
                    default:
                        break;
                }
            }
        }
        flushmessage();
        Sleep(30);
    }
}
