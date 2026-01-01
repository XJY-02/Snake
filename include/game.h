#ifndef GAME_H
#define GAME_H

#include "gamestats.h"

class snack;
class map;

// 游戏实例
class game {
   private:
    bool is_running;  // 游戏中运行标志
    gamestats stats;  // 游戏排行榜

   public:
    // 默认构造函数
    game() : is_running(0), stats() {}

    // 输出排行榜
    void print_ranking_list() const { stats.print_record(); }

    // 游戏主逻辑
    void start();
};

#endif