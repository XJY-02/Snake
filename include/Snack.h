#ifndef SNACK_H
#define SNACK_H

// 蛇
class Snack {
   private:
    std::vector<std::vector<int>> current_position;  // 当前蛇的位置
    int head_x, head_y;                              // 蛇头位置
    int tail_x, tail_y;                              // 蛇尾位置
    int speed;                                       // 速度（步/s）
    char shape;                                      // 形状
    bool alive;                                      // 存活

    // 重新生成蛇坐标
    void update_XY(const GameBoard& gameboard);

    // 将食物添加到游戏版
    void merge_snack(GameBoard& gameboard);

    // 修改形状
    void change_speed(const int& new_speed) { speed = new_speed; }

    // 修改形状
    void change_shape(const char& new_shape) { shape = new_shape; }

    // 修改食物效用
    void die() { alive = false; }

    // 构造函数
    Snack(const GameBoard& gameboard) : shape('■'), speed(2), alive(true) {}

    friend class GameBoard;
    friend class Food;
    friend class Game;
};

#endif