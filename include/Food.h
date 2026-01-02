#ifndef FOOD_H
#define FOOD_H

class GameBoard;

// 食物
class Food {
   private:
    int X, Y;          // 食物坐标
    char shape;        // 形状
    int food_utility;  // 食物效用

    // 重新生成食物坐标
    void update_XY(const GameBoard& gameboard);

    // 将食物添加到游戏版
    void merge_food(GameBoard& gameboard);

    // 修改形状
    void change_shape(const char& new_shape) { shape = new_shape; }

    // 修改食物效用
    void change_food_utility(const int& new_food_utility) { food_utility = new_food_utility; }

    // 构造函数
    Food(const GameBoard& gameboard) : shape('O'), food_utility(1) { update_XY(gameboard); }

    friend class GameBoard;
    friend class Snack;
    friend class Game;
};

#endif