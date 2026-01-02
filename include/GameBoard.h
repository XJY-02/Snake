#ifndef GAMEBOARD_H
#define GAMEBOARD_H


#include <vector>

#include "Food.h"
#include "Snack.h"

class Game;

// 游戏版
class GameBoard {
   private:
    std::vector<std::vector<int>> map;  // 当前地图,使用二维vector智能数组

    // 构造函数
    GameBoard(const int& map_size) : map(map_size, std::vector<int>(map_size, 0)) {}

    // 显示游戏版
    void print();

    friend class Game;
    friend class Snack;
    friend class Food;
};


#endif