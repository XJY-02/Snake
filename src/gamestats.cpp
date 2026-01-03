#include "GameStats.h"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>

#include "Input.h"

using namespace std;

// 重载==, 判断记录相等
bool Record::operator==(const Record& other_record) {
    if (this->date_time != other_record.date_time || this->game_time != other_record.game_time ||
        this->name != other_record.name || this->score != other_record.score) {
        return false;
    }
    return true;
}

// 初始化对局统计信息
void GameStats::ini_game_stats() {
    current_score = 0;
    current_game_time = 0.0;
    game_start_time = get_current_time();
}

// records数组排序，第一条件为score降序，第二条件为time升序
void GameStats::sort_records() {
    std::sort(records.begin(), records.end(), [](const Record& a, const Record& b) {
        if (a.score != b.score) {
            return a.score > b.score;
        }
        return a.game_time < b.game_time;
    });
};

// 返回对局记录所在排名
int GameStats::get_record_rank(const Record& record_to_find) {
    int rank = 0;
    for (Record record : records) {
        rank++;
        if (record == record_to_find) {
            return rank;
        }
    }
    return rank;
}

// 判断对局是否上榜(是否需要记录)
bool GameStats::is_record_qualified(const Record& record) {
    // 有空闲记录位置
    if (records.size() < RECORDS_LENTH) {
        return true;
    }
    // 无空闲记录位置, records.size() == RECORDS_LENTH
    else if (record.score > records[RECORDS_LENTH - 1].score) {  // 分比最后一名高
        records.erase(records.begin() + RECORDS_LENTH - 1);
        return true;
    } else if (record.score == records[RECORDS_LENTH - 1].score &&
               record.game_time < records[RECORDS_LENTH - 1].game_time) {
        // 分和最后一名一样，对局用时更短
        records.erase(records.begin() + RECORDS_LENTH - 1);
        return true;
    } else  // 分比最后一名低，不记录
        return false;
}


// 将游戏对局记录加入对局排行榜
void GameStats::add_record(const Record& record) {
    records.push_back(record);
    sort_records();
}


// 输出记录
void GameStats::print_record() const {
    cout << "--------------------------------排行榜----------------------------------------------" << endl;
    cout << "排名\t\t名字\t\t得分\t\t时间\t\t日期" << endl;
    int rank = 1;
    for (Record record : records) {
        cout << rank++ << "\t\t" << record.name << "\t\t" << record.score << "\t\t" << fixed << setprecision(1)
             << record.game_time << "s\t\t" << record.date_time << endl;
    }
    cout << "------------------------------------------------------------------------------------" << endl;
}