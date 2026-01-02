#ifndef GAME_H
#define GAME_H


#include "GameBoard.h"
#include "GameSetting.h"
#include "GameStats.h"

// 游戏实例
class Game {
   private:
    bool is_running;      // 游戏中运行标志
    GameStats stats;      // 游戏排行榜
    GameSetting setting;  // 之后实现Gamesetting类

    // 清屏
    void clearScreen();

    // 打印菜单
    void print_menu();

    // 修改设置
    void change_setting();

    // 开始游戏
    void game_start(GameBoard& gameboard, Snack& snack, Food& food);

   public:
    // 构造函数
    Game() : is_running(0), stats(), setting() {}

    // 进入游戏菜单
    void enter_menu();
};

#endif