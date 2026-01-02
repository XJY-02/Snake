#include "GameBoard.h"

#include <chrono>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "Gamestats.h"

using namespace std;


// 构造函数
GameBoard::GameBoard(const int& map_size, const string& wall_shape, const string& ground_shape)
    : map_size(map_size),
      wall_shape(wall_shape),
      ground_shape(ground_shape),
      map(map_size, std::vector<Entity>(map_size, Entity::empty)) {}

// 清空面板
void GameBoard::clean_board() {
    for (auto& row : map) {       // row 是一维数组的引用
        for (auto& cell : row) {  // cell 是 Entity 的引用
            cell = Entity::empty;
        }
    }
}

// 将蛇加入游戏版
void GameBoard::merge_snack(const Snack& snack) {
    for (auto body : snack.snack_body) {
        map[body.first][body.second] = Entity::snack;
    }
    auto head = snack.snack_body[0];
    auto tail = snack.snack_body[snack.snack_body.size() - 1];
    map[head.first][head.second] = Entity::snack_head;
    map[tail.first][tail.second] = Entity::snack_tail;
}

// 将食物加入游戏版
void GameBoard::merge_food(const Food& food) {
    for (auto food_pos : food.foods) {
        map[food_pos.first][food_pos.second] = Entity::food;
    }
}


// 显示游戏画面
void GameBoard::print(const Snack& snack, const Food& food, const GameStats& gamestats) {
    clean_board();  // 清空面板

    merge_snack(snack);  // 将蛇放入

    merge_food(food);  // 将食物放入

    // 上边界
    for (int i = 0; i < map_size + 2; i++) cout << WALL_SHAPE;
    cout << endl;
    // 中间
    for (int row = 0; row < map_size; row++) {
        for (int col = -1; col < map_size + 1; col++) {
            if (col == -1 || col == map_size)
                cout << WALL_SHAPE;
            else {
                switch (map[row][col]) {
                    case Entity::empty:
                        cout << GROUND_SHAPE;
                        break;
                    case Entity::snack:
                        cout << SNACK_SHAPE;
                        break;
                    case Entity::snack_head:
                        cout << SNACK_HEAD_SHAPE;
                        break;
                    case Entity::snack_tail:
                        cout << SNACK_TAIL_SHAPE;
                        break;
                    case Entity::food:
                        cout << FOOD_SHAPE;
                        break;
                    default:
                        break;
                }
            }
        }
        if (row == map_size / 2) {
            cout << "   当前得分: " << gamestats.current_score;
        }
        if (row == map_size / 2 + 1) {
            cout << "   当前时长: " << fixed << setprecision(1) << gamestats.current_game_time;
        }
        cout << endl;
    }
    // 下边界
    for (int i = 0; i < map_size + 2; i++) cout << WALL_SHAPE;
};