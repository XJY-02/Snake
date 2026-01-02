#ifndef GAMEBOARD_H
#define GAMEBOARD_H


#include <string>
#include <vector>

#include "Food.h"
#include "Snack.h"

#define WALL_SHAPE "░░"
#define GROUND_SHAPE "  "

class Game;

enum class Entity : int;

// 游戏版
class GameBoard {
   private:
    int map_size;                          // 地图边长
    std::string wall_shape;                // 墙的图案
    std::string ground_shape;              // 地面图案
    std::vector<std::vector<Entity>> map;  // 当前地图,使用二维vector智能数组

    // 构造函数
    GameBoard(const int& map_size, const std::string& wall_shape, const std::string& ground_shape);

    // 清空面板
    void clean_board();

    // 将蛇加入游戏版
    void merge_snack(const Snack& snack);

    // 将食物加入游戏版
    void merge_food(const Food& food);

    // 判断是否已经占满
    bool is_full(const Snack& snack);

    // 显示游戏版
    void print(const Snack& snack, const Food& food);

    friend class Game;
    friend class Snack;
    friend class Food;
};


#endif