#include "GameStats.h"

#include <algorithm>
#include <iostream>

using namespace std;

// records数组排序，第一条件为score降序，第二条件为time升序
void GameStats::sort_records() {
    std::sort(records.begin(), records.end(),
              [](const Record& a, const Record& b) {
                  if (a.score != b.score) {
                      return a.score > b.score;
                  }
                  return a.game_time < b.game_time;
              });
};

// 增加记录
void GameStats::add_record(const std::string& name, const int& score,
                           const float& game_time, const std::string& day) {
    records.push_back({name, score, game_time, day});
    count++;
    sort_records();
}


// 输出记录
void GameStats::print_record() const {
    cout << "------------------------排行榜------------------------" << endl;
    cout << "名字\t\t得分\t\t时间\t\t日期" << endl;
    for (Record record : records) {
        cout << record.name << "\t\t" << record.score << "\t\t"
             << record.game_time << "s\t\t" << record.day << endl;
    }
}