#include "GameSetting.h"

#include <limits.h>

#include <chrono>
#include <iostream>
#include <thread>

#include "Input.h"
using namespace std;

// 修改设置
void GameSetting::change_setting() {
    bool finished = false;
    while (!finished) {
        clearScreen();
        cout << "------------设置选项------------" << endl;
        cout << "1.地图大小: " << map_size << "×" << map_size << "  (4~27)" << endl;
        cout << "2.速度:  " << snack_speed << "  (1~100)" << endl;
        cout << "3.穿墙: " << (allow_through_bound ? "√" : "×") << endl;
        cout << "4.穿身体: " << (allow_through_body ? (allow_through_bound ? "√ 无敌" : "√") : "×") << endl;
        cout << "5.食物同时存在个数: " << food_quantity << "  (1~" << map_size * map_size - 3 << ")" << endl;
        cout << "6.是否使用随机种子进行游戏: " << (use_random_seed ? "√" : "×") << endl;
        if (!use_random_seed) {
            cout << "7.固定种子:  " << seed << endl;
        }
        cout << "\n0.返回" << endl;
        cout << "--------------------------------" << endl;
        cout << "\n请选择: ";
        int max_chioce = (use_random_seed ? 6 : 7);

        int answer = input_a_int(0, max_chioce);

        switch (answer) {
            case 0:
                finished = true;
                break;
            case 1:
                set_map_size();
                break;
            case 2:
                set_snack_speed();
                break;
            case 3:
                set_allow_through_bound();
                break;
            case 4:
                set_allow_through_body();
                break;
            case 5:
                set_food_quantity();
                break;
            case 6:
                set_use_random_seed();
                break;
            case 7:
                set_fixed_seed();
                break;
            default:
                break;
        }
    }
}

// 修改设置
void GameSetting::set_map_size() {
    cout << "更改地图边长为(4~27): ";
    int answer = input_a_int(INT_MIN, INT_MAX);
    if (answer > 27) {
        answer = 27;
    } else if (answer < 4) {
        answer = 4;
    }
    map_size = answer;
    if (food_quantity > map_size * map_size - 3) {
        food_quantity = map_size * map_size - 3;
    }
};

void GameSetting::set_snack_speed() {
    cout << "更改速度为: ";
    int answer = input_a_int(INT_MIN, INT_MAX);
    if (answer > 100) {
        answer = 100;
    } else if (answer < 1) {
        answer = 1;
    }
    snack_speed = answer;
};

void GameSetting::set_allow_through_bound() { allow_through_bound = !allow_through_bound; };

void GameSetting::set_allow_through_body() { allow_through_body = !allow_through_body; };

void GameSetting::set_food_quantity() {
    cout << "更改食物同时存在数量为: ";
    int answer = input_a_int(INT_MIN, INT_MAX);
    if (answer < 1) {
        answer = 1;
    } else if (answer > map_size * map_size - 3) {
        answer = map_size * map_size - 3;
    }
    food_quantity = answer;
};

void GameSetting::set_use_random_seed() { use_random_seed = !use_random_seed; }

void GameSetting::set_fixed_seed() {
    cout << "更改种子为: ";
    int answer = input_a_int(INT_MIN, INT_MAX);
    seed = answer;
}