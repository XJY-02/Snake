#ifndef GAMESETTING_H
#define GAMESETTING_H

#include <string>
class Game;

// 游戏实例
class GameSetting {
   private:
    int map_size;              // 地图大小
    int snack_speed;           // 蛇速度
    bool allow_through_bound;  // 是否运行穿墙
    bool allow_through_body;   // 是否允许穿过身体
    int food_quantity;         // 食物数量
    bool use_random_seed;      // 使用随机种子
    int seed;                  // 固定种子

    GameSetting()
        : map_size(20),
          snack_speed(70),
          allow_through_bound(true),
          allow_through_body(false),
          food_quantity(1),
          use_random_seed(true),
          seed(0) {}

    // 修改设置
    void set_map_size();
    void set_snack_speed();
    void set_allow_through_bound();
    void set_allow_through_body();
    void set_food_quantity();
    void set_use_random_seed();
    void set_fixed_seed();


    // 修改设置
    void change_setting();

    friend class Game;
};

#endif