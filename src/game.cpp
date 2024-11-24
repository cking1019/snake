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
    loadimage(&m_imgs["bg_img"], (LPCTSTR)"static/imgs/bg.png");
    loadimage(&m_imgs["bd_img"], (LPCTSTR)"static/imgs/bd.png");
    loadimage(&m_imgs["lf_img"], (LPCTSTR)"static/imgs/lf.png");
    loadimage(&m_imgs["rt_img"], (LPCTSTR)"static/imgs/rt.png");
    loadimage(&m_imgs["up_img"], (LPCTSTR)"static/imgs/up.png");
    loadimage(&m_imgs["dw_img"], (LPCTSTR)"static/imgs/dw.png");
    loadimage(&m_imgs["fd_img"], (LPCTSTR)"static/imgs/fd.png");
    // 播放背景音乐。第一个参数的格式为 "open 文件路径 alias 别名"
    mciSendString(_T("open static/music.mp3 alias bg_music"), NULL, 0, NULL);
    mciSendString(_T("play bg_music repeat"), NULL, 0, NULL);

    m_snake = new Snake(); 
    m_food = new Food();
}

// 逻辑处理
void Game::controller() {
    while (true) {
        ExMessage msg;
        while(peekmessage(&msg, EM_KEY)) {
            if(msg.message != WM_KEYDOWN) continue;

            auto key = msg.vkcode;
            // 如果游戏状态停止，并且按键不为空格，那么继续等待下一个按键
            if(m_state == STOP && key != VK_SPACE) continue;
            
            switch(key) {
            case VK_UP:
                if(m_snake->m_dir != 'D') {
                    m_snake->m_dir = 'U'; break;
                };
            case VK_DOWN:
                if(m_snake->m_dir != 'U') {
                    m_snake->m_dir = 'D'; break;
                }
            case VK_LEFT:
                if(m_snake->m_dir != 'R') {
                    m_snake->m_dir = 'L'; break;
                }
            case VK_RIGHT:
                if(m_snake->m_dir != 'L') {
                    m_snake->m_dir = 'R'; break;
                }
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
                m_state = EXIT; exit(0);
            default: break;
            }
        }
        flushmessage();
        Sleep(10);
    }
}

// 界面渲染
void Game::draw()
{
    while (true) {
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

        std::string s1 = "grade: " + std::to_string(m_grade);
        outtextxy(m_win.width - 80, 0, (LPTSTR)s1.c_str());

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
        bool isOK = false;
        for(auto &e: m_snake->m_body) {
            // 如果食物与蛇身相撞，那么重新生成随机食物
            if(m_food->nd == e) continue;
            isOK = true;
            break;
        }
        if(isOK) break;
    }
    std::cout << "The Food Position is: (" << m_food->nd.x << ", " << m_food->nd.y << ")\n";
}

// 主逻辑运行
void Game::run() {
    while(m_state == BEGIN) {
        m_snake->move();
        bool flag = m_snake->eat_food(m_food);
        if(flag) {
            produce_food();
            m_grade += 25;
        }
        Sleep(1000 / m_frame);
    }
}
