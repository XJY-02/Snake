#ifndef INPUT_H
#define INPUT_H

#include <string>

// 接收2个整数之间的整数
int input_a_int(const int& low, const int& high);

//  清屏
void clearScreen();

// 等待按下 ESC
void wait_esc();

// 等待按下 Enter
void wait_enter();

// Enter返回true，ESC返回false
bool enter_or_esc();

// 接收一行字符串
std::string get_player_name();

// 返回当前时间字符串
std::string get_current_time();

#endif