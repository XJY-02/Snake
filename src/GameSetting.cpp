#include "GameSetting.h"

#include <limits.h>

#include <iostream>

#include "Input.h"
using namespace std;

// 修改设置
void GameSetting::set_map_size() {
    cout << "更改地图大小为: ";
    int answer = input_a_int(1, INT_MAX);
    map_size = answer;
};

void GameSetting::set_snack_speed() {
    cout << "更改速度为: ";
    int answer = input_a_int(1, INT_MAX);
    snack_speed = answer;
};

void GameSetting::set_allow_through_bound() { allow_through_bound = !allow_through_bound; };

void GameSetting::set_allow_through_body() { allow_through_body = !allow_through_body; };

void GameSetting::set_food_utility() {
    cout << "更改食物效用为: ";
    int answer = input_a_int(1, INT_MAX);
    food_utility = answer;
};