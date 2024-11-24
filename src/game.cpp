#include "Game.hpp"

Game::Game() {
    // 随机种子初始化
    srand(time(0));
    // 窗口宽、高和网格大小
    m_win = Window(500, 500, 20);
    // 得分
    m_grade = 0;
    // 游戏运行状态
    m_state = STOP;
    // 游戏帧率
    m_frame = 10;
    // 设置图片
    IMAGE up_img, dw_img, lf_img, rt_img, bd_img, fd_img, bg_img;
    loadimage(&bg_img, (LPCTSTR)"static/imgs/bg.png");
    loadimage(&bd_img, (LPCTSTR)"static/imgs/bd.png");
    loadimage(&lf_img, (LPCTSTR)"static/imgs/lf.png");
    loadimage(&rt_img, (LPCTSTR)"static/imgs/rt.png");
    loadimage(&up_img, (LPCTSTR)"static/imgs/up.png");
    loadimage(&dw_img, (LPCTSTR)"static/imgs/dw.png");
    loadimage(&fd_img, (LPCTSTR)"static/imgs/fd.png");
    m_imgs["bg_img"] = bg_img;
    m_imgs["bd_img"] = bd_img;
    m_imgs["lf_img"] = lf_img;
    m_imgs["rt_img"] = rt_img;
    m_imgs["up_img"] = up_img;
    m_imgs["dw_img"] = dw_img;
    m_imgs["fd_img"] = fd_img;
}

// 逻辑处理
void Game::controller() {
    while (true) {
        ExMessage msg;
        while(peekmessage(&msg, EM_KEY)) {
            if(msg.message == WM_KEYDOWN) {
                auto key = msg.vkcode;
                auto dir = m_snake->m_dir;
                if(dir == 'L' && key == VK_RIGHT) continue;
                if(dir == 'U' && key == VK_DOWN)  continue;
                if(dir == 'R' && key == VK_LEFT)  continue;
                if(dir == 'D' && key == VK_UP)    continue;
                switch(key) {
                case VK_UP:
                    m_snake->m_dir = 'U'; break;
                case VK_DOWN:
                    m_snake->m_dir = 'D'; break;
                case VK_LEFT:
                    m_snake->m_dir = 'L'; break;
                case VK_RIGHT:
                    m_snake->m_dir = 'R'; break;
                case VK_F1:
                    if(m_frame < 100) {
                        m_frame += 1;
                        std::cout << "speed up\n";
                    }
                    break;
                case VK_F2:
                    if(m_frame > 1) {
                        m_frame -= 1;
                        std::cout << "speed dw\n";
                    }
                    break;
                case VK_SPACE: 
                    if(m_state == STOP) {
                        m_state = BEGIN;
                        mciSendString(_T("resume bg_music"), NULL, 0, NULL);
                        std::cout << "BEGIN\n";
                    } else if(m_state == BEGIN) {
                        m_state = STOP;
                        mciSendString(_T("pause bg_music"), NULL, 0, NULL);
                        std::cout << "STOP\n";
                    }
                    break;
                case VK_ESCAPE:
                    m_state = EXIT; break;
                default: break;
                }
            }
        }
        flushmessage();
        Sleep(30);
    }
}

// 界面渲染
void Game::draw()
{
    while (true)
    {
        cleardevice();
        // 描绘背景
        putimage(0, 0, &m_imgs["bg_img"]);
        // 描绘蛇身
        auto bd = m_snake->m_body;
        auto numNode = bd.size();
        for(int i = 0; i < numNode; i++) {
            int x = bd[i].x * m_win.unit;
            int y = bd[i].y * m_win.unit;
            putimage(x, y, &m_imgs["bd_img"]);
        }

        // 描绘蛇头
        auto hd = m_snake->m_head;
        int hd_x = hd.nd.x * m_win.unit;
        int hd_y = hd.nd.y * m_win.unit;
        switch (m_snake->m_dir) {
        case 'U':
            putimage(hd_x, hd_y, &m_imgs["up_img"]); break;
        case 'D':
            putimage(hd_x, hd_y, &m_imgs["dw_img"]); break;
        case 'L':
            putimage(hd_x, hd_y, &m_imgs["lf_img"]); break;
        case 'R':
            putimage(hd_x, hd_y, &m_imgs["rt_img"]); break;
        default: break;
        }

        // 描绘食物
        int fd_x = m_food->nd.x * m_win.unit;
        int fd_y = m_food->nd.y * m_win.unit;
        putimage(fd_x, fd_y, &m_imgs["fd_img"]);

        setbkmode(TRANSPARENT);
        settextstyle(20, 0, (LPCTSTR)"times new roman");

        std::string s = "grade: " + std::to_string(m_grade);
        outtextxy(m_win.width - 80, 0, (LPTSTR)s.c_str());

        std::string s2 = "speed: " + std::to_string(m_frame);
        outtextxy(m_win.width - 80 , 20, (LPTSTR)s2.c_str());

        FlushBatchDraw();
        Sleep(10);
    }
}

// 生成食物
void Game::produce_food() {
    while (true) {
        m_food->nd.x = rand() % (24 + 1);
        m_food->nd.y = rand() % (24 + 1);
        bool is_ok = true;
        for(auto &e: m_snake->m_body) {
            // 如果食物与蛇身相撞，那么重新生成随机食物
            if(m_food->nd == e) {
                is_ok = false;
                break;
            }
        }
        if(is_ok) break;
    }
    std::cout << "The Food Position is: (" << m_food->nd.x << ", " << m_food->nd.y << ")\n";
}

// 主逻辑运行
void Game::run() {
    m_snake->move();
    bool flag = m_snake->eat_food(m_food);
    if(flag) {
        produce_food();
        m_grade += 25;
    }
}
