#include <game.h>

Game::Game() {
    // 随机种子初始化
    srand(time(0));
    // 窗口宽和高
    width = 500;
    height = 500;

    // 网格大小
    unit = 20;
    
    // 得分
    grade = 0;
    
    // 游戏运行状态
    is_running = false;
    
    // 游戏帧率
    frame = 10;

    //初始化贪吃蛇
    snake = Snake();
    // 初始化食物位置
    food = Food();
}

// 加载图片
void Game::load_image()
{
    loadimage(&bg_img, (LPCTSTR)"static/imgs/bg.png");
    loadimage(&bd_img, (LPCTSTR)"static/imgs/bd.png");
    loadimage(&lf_img, (LPCTSTR)"static/imgs/lf.png");
    loadimage(&rt_img, (LPCTSTR)"static/imgs/rt.png");
    loadimage(&up_img, (LPCTSTR)"static/imgs/up.png");
    loadimage(&dw_img, (LPCTSTR)"static/imgs/dw.png");
    loadimage(&fd_img, (LPCTSTR)"static/imgs/fd.png");
}

// 生成食物
void Game::produce_food() {
    // 将食物设置到正确的位置
    while (true)
    {
        food.x = rand() % (24 + 1);
        food.y = rand() % (24 + 1);
        bool is_ok = true;
        for(auto &e: snake.body) {
            if(food == e) {
                is_ok = false;
                break;
            }
        }
        if(is_ok) break;
    }
    std::cout << "The Food Position is: (" << food.x << ", " << food.y << ")\n";
}

// 主逻辑运行
void Game::run()
{
    snake.move();
    auto flag = snake.eat_food(food);
    if(flag) {
        produce_food();
        grade += 25;
    }
}
