#include "Game.h"

#include <cstdlib>
#include <iostream>

#include "Food.h"
#include "GameSetting.h"
#include "GameStats.h"
#include "Input.h"
#include "Snack.h"

using namespace std;

// 清屏
void Game::clearScreen() { system("cls"); }

// 打印游戏菜单
void Game::print_menu() {
    cout << "--------贪吃蛇--------\n"
         << "     1.开始游戏\n"
         << "     2.设置\n"
         << "     3.排行榜\n"
         << "----------------------\n";
}

// 修改设置
void Game::change_setting() {
    bool finished = false;
    while (!finished) {
        cout << "设置选项: " << endl;
        cout << "1.地图大小: " << setting.map_size << "格" << endl;
        cout << "2.速度:  " << setting.snack_speed << "步/s" << endl;
        cout << "3.穿墙: " << (setting.allow_through_bound ? "开" : "关") << endl;
        cout << "4.穿身体: " << (setting.allow_through_body ? "开" : "关") << endl;
        cout << "5.食物效用: " << setting.food_utility << "生长/食物" << endl;
        cout << "6.返回" << endl;

        int answer = input_a_int(1, 6);

        switch (answer) {
            case 1:
                setting.set_map_size();
                break;
            case 2:
                setting.set_snack_speed();
                break;
            case 3:
                setting.set_allow_through_bound();
                break;
            case 4:
                setting.set_allow_through_body();
                break;
            case 5:
                setting.set_food_utility();
                break;
            case 6:
                finished = true;
                break;
            default:
                break;
        }
    }
}


// 游戏主逻辑
void Game::game_start(GameBoard& gameboard, Snack& snack, Food& food) {}


// 进入游戏菜单
void Game::enter_menu() {
    is_running = true;

    while (is_running) {
        clearScreen();
        print_menu();
        int menu_select = input_a_int(1, 3);
        switch (menu_select) {
            case 1: {
                // 注意：这里添加花括号
                // 在局部作用域内创建对象
                GameBoard gameboard(setting.map_size);
                Snack snack;
                Food food(setting.food_utility);
                game_start(gameboard, snack, food);
                break;
            }
            default:
                break;
        }
    }
}
