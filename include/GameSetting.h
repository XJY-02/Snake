#ifndef GAMESETTING_H
#define GAMESETTING_H


class Game;

// 游戏实例
class GameSetting {
   private:
    int map_size;              // 地图大小
    float snack_speed;         // 蛇速度，多少s走1步
    bool allow_through_bound;  // 是否运行穿墙
    bool allow_through_body;   // 是否允许穿过身体
    int food_utility;          // 吃一个食物长多少

    GameSetting()
        : map_size(10), snack_speed(1.0), allow_through_bound(false), allow_through_body(false), food_utility(1) {}

    // 修改设置
    void set_map_size();
    void set_snack_speed();
    void set_allow_through_bound();
    void set_allow_through_body();
    void set_food_utility();

    friend class Game;
};

#endif