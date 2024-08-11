#include <game.h>

// 界面渲染，使用一个独立的线程操作
void Game::draw()
{
    while (true)
    {
        cleardevice();
        
        // 描绘背景
        putimage(0, 0, &this->imgs["bg_img"]);
        // 描绘蛇身
        auto bd = this->snake->getBody();
        for(int i = 0; i < bd.size(); i++) {
            int x = bd[i].x * this->window.unit;
            int y = bd[i].y * this->window.unit;
            putimage(x, y, &this->imgs["bd_img"]);
        }

        // 描绘蛇头
        auto hd = this->snake->getHead();
        int hd_x = hd.x * this->window.unit;
        int hd_y = hd.y * this->window.unit;
        switch (this->snake->getDir())
        {
            case 'U':
                putimage(hd_x, hd_y, &this->imgs["up_img"]);
                break;
            case 'D':
                putimage(hd_x, hd_y, &this->imgs["dw_img"]);
                break;
            case 'L':
                putimage(hd_x, hd_y, &this->imgs["lf_img"]);
                break;
            case 'R':
                putimage(hd_x, hd_y, &this->imgs["rt_img"]);
                break;
            default:
                break;
        }

        // 描绘食物
        int fd_x = this->food->x * this->window.unit;
        int fd_y = this->food->y * this->window.unit;
        putimage(fd_x, fd_y, &this->imgs["fd_img"]);

        setbkmode(TRANSPARENT);
        settextstyle(20, 0, (LPCTSTR)"times new roman");

        std::string s = "grade: " + std::to_string(this->getGrade());
        outtextxy(this->getWindow().width - 80, 0, (LPTSTR)s.c_str());

        std::string s2 = "speed: " + std::to_string(this->getFrame());
        outtextxy(this->getWindow().width - 80 , 20, (LPTSTR)s2.c_str());

        FlushBatchDraw();
        Sleep(10);
    }
}