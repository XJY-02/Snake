#ifndef GAME_H
#define GAME_H


#include "GameBoard.h"
#include "GameSetting.h"
#include "GameStats.h"

enum class Direction : int { up = 0, down, left, right };  // 方向枚举

// 游戏实例
class Game {
   private:
    bool is_running;      // 游戏中运行标志
    bool play_again;      // 再来一把标志
    GameStats stats;      // 游戏统计信息
    GameSetting setting;  // 游戏设置


    // 打印菜单
    void print_menu();

    // 游戏对局主逻辑
    bool game_start(GameBoard& gameboard, Snack& snack, Food& food);

    // 游戏对局结束
    void game_over();


   public:
    // 构造函数
    Game() : is_running(0), play_again(false), stats(), setting() {}

    // 进入游戏菜单
    void enter_menu();
};

#endif