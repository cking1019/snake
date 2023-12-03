#include <game.h>

// 界面渲染，使用一个独立的线程操作
void Game::draw()
{
    while (true)
    {
        cleardevice();
        
        // 描绘背景
        putimage(0, 0, &bg_img);
        // 描绘蛇身
        for(int i = 0; i < snake.body.size(); i++) {
            int x = snake.body[i].x * unit;
            int y = snake.body[i].y * unit;
            putimage(x, y, &bd_img);
        }

        // 描绘蛇头
        int hd_x = snake.head.x * unit;
        int hd_y = snake.head.y * unit;
        switch (snake.dir)
        {
            case 'U':
                putimage(hd_x, hd_y, &up_img);
                break;
            case 'D':
                putimage(hd_x, hd_y, &dw_img);
                break;
            case 'L':
                putimage(hd_x, hd_y, &lf_img);
                break;
            case 'R':
                putimage(hd_x, hd_y, &rt_img);
                break;
            default:
                break;
        }

        // 描绘食物
        int fd_x = food.x * unit;
        int fd_y = food.y * unit;
        putimage(fd_x, fd_y, &fd_img);

        setbkmode(TRANSPARENT);
        settextstyle(20, 0, (LPCTSTR)"times new roman");

        std::string s = "grade: " + std::to_string(grade);
        outtextxy(width - 80, 0, (LPTSTR)s.c_str());

        std::string s2 = "speed: " + std::to_string(frame);
        outtextxy(width - 80 , 20, (LPTSTR)s2.c_str());

        FlushBatchDraw();
        Sleep(10);
    }
}