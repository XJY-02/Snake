#ifndef GAMESTATS_H
#define GAMESTATS_H

#include <string>
#include <vector>


// 记录结构体
struct Record {
    std::string name;  // 玩家名字
    int score;         // 玩家分数
    float game_time;   // 游戏时间
    std::string day;   // 游戏日期
};

class Game;

// 游戏排行榜
class GameStats {
   private:
    std::vector<Record> records;  // 记录智能数组
    int count;                    // 记录实际人数

    // 构造初始统计信息
    GameStats() : records(0), count(0) {}

    // records数组排序
    void sort_records();

    // 增加记录
    void add_record(const std::string& name, const int& score,
                    const float& time, const std::string& day);

    // 输出记录
    void print_record() const;

    friend class Game;  // 声明Game类为友元
};
#endif