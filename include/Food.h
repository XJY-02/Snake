#ifndef FOOD_H
#define FOOD_H


#include <string>
#include <utility>
#include <vector>

#include "Snack.h"

#define FOOD_SHAPE "◎"

// 食物
class Food {
   private:
    int map_size;                            // 地图大小
    std::string shape;                       // 形状
    std::vector<std::pair<int, int>> foods;  // 食物坐标
    int seed;                                // 随机种子

    // 生成新食物的随机坐标
    std::pair<int, int> new_food_position(const Snack& snack);

    // 下标i的食物被蛇吃掉,重新生成
    void renew_food_i(const Snack& snack, const int& i) { foods[i] = new_food_position(snack); }

    // 构造函数
    Food(const Snack& snack, int map_size, const std::string& shape, int food_quantity, int seed)
        : map_size(map_size), shape(shape), foods(food_quantity, std::pair<int, int>()), seed(seed) {
        for (auto& food : foods) {
            food = new_food_position(snack);
        }
    }

    friend class GameBoard;
    friend class Snack;
    friend class Game;
};

#endif