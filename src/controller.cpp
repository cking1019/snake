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
                auto dir = this->snake->getDir();
                if(dir == 'L' && key == VK_RIGHT) continue;
                if(dir == 'U' && key == VK_DOWN)  continue;
                if(dir == 'R' && key == VK_LEFT)  continue;
                if(dir == 'D' && key == VK_UP)    continue;
                switch(key) {
                    case VK_UP:
                        this->snake->setDir('U');
                        break;
                    case VK_DOWN:
                        this->snake->setDir('D');
                        break;
                    case VK_LEFT:
                        this->snake->setDir('L');
                        break;
                    case VK_RIGHT:
                        this->snake->setDir('R');
                        break;
                    case VK_F1:
                        if(this->frame < 100) {
                            this->frame += 1;
                            std::cout << "speed up\n";
                        }
                        break;
                    case VK_F2:
                        if(this->frame > 1) {
                            this->frame -= 1;
                            std::cout << "speed dw\n";
                        }
                        break;
                    case VK_SPACE: 
                        if(this->state == STOP) {
                            this->state = BEGIN;
                            mciSendString(_T("resume bg_music"), NULL, 0, NULL);
                            std::cout << "BEGIN\n";
                        } else if(this->state == BEGIN) {
                            this->state = STOP;
                            mciSendString(_T("pause bg_music"), NULL, 0, NULL);
                            std::cout << "STOP\n";
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
