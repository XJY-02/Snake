#ifndef GAMEBOARD_H
#define GAMEBOARD_H


#include <vector>

#include "Food.h"
#include "Snack.h"

class Game;

// 游戏版
class GameBoard {
   private:
    int map_size;
    char wall_shape;
    char ground_shape;
    std::vector<std::vector<int>> map;  // 当前地图,使用二维vector智能数组

    // 构造函数
    GameBoard(const int& map_size, char wall_shape, char ground_shape)
        : map_size(map_size),
          wall_shape(wall_shape),
          ground_shape(ground_shape),
          map(map_size, std::vector<int>(map_size)) {}

    // 将蛇加入游戏版
    void merge_snack(const Snack& snack);

    // 将食物加入游戏版
    void merge_food(const Food& food);

    // 判断是否已经占满
    bool is_full(const Snack& snack);

    // 显示游戏版
    void print();

    friend class Game;
    friend class Snack;
    friend class Food;
};


#endif