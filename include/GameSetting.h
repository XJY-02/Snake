#ifndef GAMESETTING_H
#define GAMESETTING_H

#include <string>
class Game;
#define INI_MAP_SIZE 20
#define INI_SPEED 50
#define INI_THROUGH_WALL true
#define INI_THROUGH_BODY false
#define INI_FOOD_QUANTITY 3
#define INI_USE_RANDOM_SEED false
#define INI_SEED 114514


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
        : map_size(INI_MAP_SIZE),
          snack_speed(INI_SPEED),
          allow_through_bound(INI_THROUGH_WALL),
          allow_through_body(INI_THROUGH_BODY),
          food_quantity(INI_FOOD_QUANTITY),
          use_random_seed(INI_USE_RANDOM_SEED),
          seed(INI_SEED) {}

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