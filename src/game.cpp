#include "Game.h"

#include <conio.h>  // Windows 专用

#include <chrono>  // 时间库
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <random>
#include <thread>  // 线程库

#include "Food.h"
#include "GameSetting.h"
#include "GameStats.h"
#include "Input.h"
#include "Snack.h"

using namespace std;


// 打印游戏菜单
void Game::print_menu() {
    cout << "--------贪吃蛇--------\n"
         << "     1.开始游戏\n"
         << "     2.设置\n"
         << "     3.对局排行榜\n"
         << "\n     0.退出\n"
         << "----------------------\n";
}


// 进入游戏菜单
void Game::enter_menu() {
    is_running = true;

    while (is_running) {
        clearScreen();
        print_menu();  // 打印菜单

        int menu_select = input_a_int(0, 3);  // 菜单选项选择

        clearScreen();
        switch (menu_select) {  // 进入选项
            case 0:             // 退出
                is_running = false;
                break;
            case 1: {
                // 选择开始游戏
                do {
                    // 设置随机种子
                    int seed;
                    if (setting.use_random_seed) {                       // 启用随机种子
                        random_device rd;                                // 硬件随机数设备（如果可用）
                        mt19937 gen(rd());                               // 使用Mersenne Twister引擎
                        uniform_int_distribution<int> dist(0, INT_MAX);  // 均匀整数分布
                        setting.seed = dist(gen);
                    }
                    seed = setting.seed;

                    //  创建游戏对象
                    GameBoard gameboard(setting.map_size, WALL_SHAPE, GROUND_SHAPE);

                    Snack snack(setting.map_size, setting.snack_speed, setting.allow_through_bound,
                                setting.allow_through_body, SNACK_SHAPE);

                    Food food(snack, setting.map_size, FOOD_SHAPE, setting.food_quantity, seed);


                    // 初始化对局信息
                    stats.ini_game_stats();

                    // 游戏开始
                    game_start(gameboard, snack, food);

                    // 游戏结束
                    game_over();

                } while (play_again);  // 再来一把

                break;
            }
            case 2:  // 进入设置
                setting.change_setting();
                break;
            case 3:  // 进入排行榜
                stats.print_record();
                std::cout << "\n按 ESC 键返回..." << std::endl;
                wait_esc();
                break;
            default:
                break;
        }
    }
}

// 游戏对局主逻辑
void Game::game_start(GameBoard& gameboard, Snack& snack, Food& food) {
    // 记录时间初始化
    auto time_begin = chrono::steady_clock ::now();
    Direction current_direction = Direction::right;
    chrono::steady_clock::time_point time_now;
    std::chrono::duration<double> total_duration;

    while (true) {
        // 计算游戏时间
        time_now = chrono::steady_clock::now();
        total_duration = std::chrono::duration<double>(time_now - time_begin);
        stats.current_game_time = (float)total_duration.count();

        // 打印界面
        clearScreen();
        gameboard.print(snack, food, stats);

        // 判断是否填满
        bool full = true;
        for (auto row : gameboard.map) {
            for (auto cell : row) {
                if (cell != Entity::snack && cell != Entity::snack_head && cell != Entity::snack_tail) {
                    full = false;
                    break;
                }
            }
            if (!full) break;
        }
        if (full)  // 填满，游戏胜利
        {
            cout << "\n--------游戏胜利!--------\n" << endl;
            break;
        }

        // 获取输入
        char key;
        if (_kbhit()) {      // 检查是否有按键
            key = _getch();  // 获取按键（不等待）
            switch (key) {
                case 'w':
                case 'W':
                    if (current_direction != Direction::down) {
                        current_direction = Direction::up;
                    }
                    break;
                case 's':
                case 'S':
                    if (current_direction != Direction::up) {
                        current_direction = Direction::down;
                    }
                    break;
                case 'a':
                case 'A':
                    if (current_direction != Direction::right) {
                        current_direction = Direction::left;
                    }
                    break;
                case 'd':
                case 'D':
                    if (current_direction != Direction::left) {
                        current_direction = Direction::right;
                    }
                    break;
                default:
                    break;
            }
        }

        // 数据处理

        // 获得新头位置,未开启穿墙则穿墙时越界
        pair<int, int> new_head_position = snack.get_new_head_position(current_direction);

        bool snack_alive = true;  // 存活标志

        // 检查是否撞墙
        if (new_head_position.first < 0 || new_head_position.second < 0 ||
            new_head_position.first > snack.map_size - 1 || new_head_position.second > snack.map_size - 1) {
            snack_alive = false;
        } else if (!setting.allow_through_body) {  // 检查是否撞身体
            for (auto& snack_body : snack.snack_body) {
                if (snack_body == new_head_position) {
                    snack_alive = false;
                    break;
                }
            }
        }

        if (snack_alive) {  // 蛇存活
            bool eat_food = false;
            // 检查是否吃到食物
            for (int i = 0; i < (int)food.foods.size(); i++) {
                if (food.foods[i] == new_head_position) {
                    eat_food = true;
                    stats.current_score++;
                    food.renew_food_i(snack, i);
                    break;
                }
            }
            // 移动
            snack.move_and_may_grow(new_head_position, eat_food);


        } else {  // 蛇死亡
            cout << "\n--------游戏结束--------\n" << endl;
            break;
        }
        // 延迟
        int milliseconds_to_nesize_txt_print = 1000 / snack.speed;
        this_thread::sleep_for(chrono::milliseconds(milliseconds_to_nesize_txt_print));
    }
    // 等待3s
    this_thread::sleep_for(chrono::seconds(3));
}


// 游戏对局结束
void Game::game_over() {
    // 生成本局记录
    Record current_game_record = {"Unknown", stats.current_score, stats.current_game_time, stats.game_start_time};

    // 展示对局信息
    cout << "--------对局信息汇总--------" << endl;
    cout << "得分                   " << current_game_record.score << endl;
    cout << "耗时                   " << fixed << setprecision(1) << current_game_record.game_time << "s" << endl;

    cout << "----------游戏设置----------" << endl;
    cout << (setting.use_random_seed ? " 随机" : " 固定") << " 种子: " << setting.seed << endl;
    cout << " 蛇速度: " << setting.snack_speed << endl;
    cout << " 穿墙功能: " << (setting.allow_through_bound ? "开" : "关") << endl;
    cout << " 穿身体: " << (setting.allow_through_body ? "开" : "关") << endl;
    cout << " 食物同时存在数量: " << setting.food_quantity << " 个" << endl;
    cout << "----------上榜情况----------" << endl;
    //  判断是否上榜
    bool need_to_record = stats.is_record_qualified(current_game_record);
    // 上榜
    if (need_to_record) {
        cout << "恭喜上榜!!! 请输入游戏名: ";
        current_game_record.name = get_a_string();              //  询问玩家名
        stats.add_record(current_game_record);                  // 将游戏记录加入排行榜
        int rank = stats.get_record_rank(current_game_record);  // 获取排名
        cout << "已上传至对局排行榜, 位列第" << rank << "名" << endl;
    }
    // 未上榜
    else
        cout << "很可惜，没有上榜..." << endl;
    // 询问是否再来一局
    cout << "\n按 Enter键 再来一把    或    按 ESC键 退出至主菜单" << endl;
    play_again = enter_or_esc();
}
