#include <game.h>

Game::Game() {
    // 随机种子初始化
    srand(time(0));
    // 窗口宽、高和网格大小
    this->window = Window(500, 500, 20);
    // 得分
    this->grade = 0;
    // 游戏运行状态
    this->state = STOP;
    // 游戏帧率
    this->frame = 10;
    // 设置图片
    this->setImgs();
}

// 生成食物
void Game::produce_food() {
    while (true)
    {
        this->food->x = rand() % (24 + 1);
        this->food->y = rand() % (24 + 1);
        bool is_ok = true;
        for(auto &e: snake->getBody()) {
            // 如果食物与蛇身相撞，那么重新生成随机食物
            if(*this->food == e) {
                is_ok = false;
                break;
            }
        }
        if(is_ok) break;
    }
    std::cout << "The Food Position is: (" << this->food->x << ", " << this->food->y << ")\n";
}

// 主逻辑运行
void Game::run()
{
    this->snake->move();
    auto flag = this->snake->eat_food(this->food);
    if(flag) {
        produce_food();
        this->setGrade(this->getGrade() + 25);
    }
}

void Game::setState(State s) {
    this->state = s;
}

State Game::getState() {
    return this->state;
}

void Game::setGrade(int grade) {
    this->grade =grade;
}

int Game::getGrade() {
    return this->grade;
}

void Game::setWindow(struct Window w) {
    this->window = w;
}

Window Game::getWindow() {
    return this->window;
}

void Game::setFrame(int frame) {
    this->frame = frame;
}

int Game::getFrame() {
    return this->frame;
}

void Game::setImgs() {
    IMAGE up_img, dw_img, lf_img, rt_img, bd_img, fd_img, bg_img;
    loadimage(&bg_img, (LPCTSTR)"static/imgs/bg.png");
    loadimage(&bd_img, (LPCTSTR)"static/imgs/bd.png");
    loadimage(&lf_img, (LPCTSTR)"static/imgs/lf.png");
    loadimage(&rt_img, (LPCTSTR)"static/imgs/rt.png");
    loadimage(&up_img, (LPCTSTR)"static/imgs/up.png");
    loadimage(&dw_img, (LPCTSTR)"static/imgs/dw.png");
    loadimage(&fd_img, (LPCTSTR)"static/imgs/fd.png");
    this->imgs["bg_img"] = bg_img;
    this->imgs["bd_img"] = bd_img;
    this->imgs["lf_img"] = lf_img;
    this->imgs["rt_img"] = rt_img;
    this->imgs["up_img"] = up_img;
    this->imgs["dw_img"] = dw_img;
    this->imgs["fd_img"] = fd_img;
}

std::map<std::string, IMAGE> Game::getImgs() {
    return this->imgs;
}