#include "Food.h"

#include <iostream>
#include <random>
#include <utility>

using namespace std;

// 生成新食物的随机坐标
pair<int, int> Food::new_food_position(const Snack& snack) {
    mt19937 gen(seed);                                    // 设置种子
    uniform_int_distribution<int> dist(0, map_size - 1);  // 设置随机范围
    while (true) {
        pair<int, int> new_position = {dist(gen), dist(gen)};  // 随机生成一个位置
        bool valid = true;
        // 检查是否与蛇身体重合
        for (auto snack_body : snack.snack_body) {
            if (snack_body == new_position) {
                valid = false;
                break;
            }
        }
        // 检查是否与食物重合
        for (auto food : foods) {
            if (food == new_position) {
                valid = false;
                break;
            }
        }
        if (valid) {
            return new_position;
        }
    }
};
