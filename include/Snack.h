#ifndef SNACK_H
#define SNACK_H


#include <queue>
#include <string>
#include <utility>

class GameBoard;
class Food;
class Game;

enum class Entity : int;
enum class Direction : int;  // 方向枚举

#define SNACK_SHAPE "▓▓"
#define SNACK_HEAD_SHAPE "██"
#define SNACK_TAIL_SHAPE "▒▒"

// 蛇
class Snack {
   private:
    int map_size;                                // 地图边界大小
    int speed;                                   // 速度
    bool allow_through_bound;                    // 是否运行穿墙
    bool allow_through_body;                     // 是否允许穿过身体
    std::string shape;                           // 形状
    std::deque<std::pair<int, int>> snack_body;  // 当前蛇的位置

    // 获得新头位置
    std::pair<int, int> get_new_head_position(const Direction& direction);

    // 移动
    void move_and_may_grow(std::pair<int, int> new_head_position, const bool& grow);


    // 构造函数
    Snack(int map_size, int snack_speed, bool allow_through_bound, bool allow_through_body, const std::string& shape)
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