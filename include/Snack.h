#ifndef SNACK_H
#define SNACK_H


#include <queue>
#include <utility>
class GameBoard;


// 蛇
class Snack {
   private:
    int map_size;                                // 地图边界大小
    int speed;                                   // 速度（步/s）
    bool allow_through_bound;                    // 是否运行穿墙
    bool allow_through_body;                     // 是否允许穿过身体
    char shape;                                  // 形状
    std::deque<std::pair<int, int>> snack_body;  // 当前蛇的位置


    // 判断是否死亡
    bool is_dead();

    // 构造函数
    Snack(int map_size, int snack_speed, bool allow_through_bound, bool allow_through_body, char shape)
        : map_size(map_size),
          speed(snack_speed),
          allow_through_bound(allow_through_bound),
          allow_through_body(allow_through_body),
          shape(shape),
          snack_body{{map_size / 2, map_size / 2}, {map_size / 2, map_size / 2 - 1}, {map_size / 2, map_size / 2 - 2}} {
    }

    friend class GameBoard;
    friend class Food;
    friend class Game;
};

#endif