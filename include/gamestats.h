#ifndef GAMESTATS_H
#define GAMESTATS_H

#include <string>
#include <vector>

#define RECORDS_LENTH 3

// 排行榜记录结构体
struct Record {
    std::string name;       // 玩家名字
    int score;              // 玩家分数
    float game_time;        // 游戏时间
    std::string date_time;  // 游戏日期

    // 重载==, 判断记录相等
    bool operator==(const Record& other_record);
};

class Game;
class GameBoard;

// 游戏统计信息
class GameStats {
   private:
    int current_score;            // 本局得分
    float current_game_time;      // 本局游戏耗时
    std::string game_start_time;  // 本局开始时间

    std::vector<Record> records;  // 排行榜对局记录数组

    // 构造初始统计信息
    GameStats() : records(0) {}

    // 初始化对局统计信息
    void ini_game_stats();


    // 判断对局是否上榜(是否需要记录)
    bool is_record_qualified(const Record& record);

    // 返回对局记录所在排名
    int get_record_rank(const Record& record_to_find);

    // 排行榜排序
    void sort_records();

    // 询问玩家名，将游戏对局记录加入对局排行榜
    void add_record(const Record& record);

    // 打印对局排行榜
    void print_record() const;

    friend class Game;
    friend class GameBoard;
};

#endif