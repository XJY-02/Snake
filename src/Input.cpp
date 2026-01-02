#include "Input.h"

#include <conio.h>

#include <chrono>
#include <ctime>
#include <iostream>
#include <random>
using namespace std;

// 接收2个整数之间的整数
int input_a_int(const int& low, const int& high) {
    int answer;
    while (true) {
        cout << "请选择: ";
        if (!(cin >> answer)) {  // 读取失败
            cout << "无效输入" << endl;
            cin.clear();  // 清除错误标志
            cin.ignore(1000,
                       '\n');  // 丢弃错误输入
            continue;
        }
        // 读取成功
        cin.ignore(1000, '\n');  // 清理多余输入
        if (answer < low || answer > high) {
            cout << "越界输入" << endl;
            continue;
        }
        return answer;
    }
}

//  清屏
void clearScreen() { system("cls"); }

// 等待按下 ESC
void wait_esc() {
    int key;
    while (((key = _getch()) != 27)) {  // ESC是27，按下的不是ESC
        ;
    }
}

// 等待按下 Enter
void wait_enter() {
    int key;
    while (((key = _getch()) != 13)) {  // Enter是13，按下的不是Enter
        ;
    }
}

// Enter返回true，ESC返回false
bool enter_or_esc() {
    int key;
    while ((key = _getch()) != 13 && (key = _getch()) != 27) {  // 按下的不是Enter也不是ESC
        ;
    }
    if (key == 13) {  // 按下Enter
        return true;
    } else  // 按下ESC
        return false;
}

// 接收一个字符串
string get_a_string() {
    string str;
    cin >> str;
    return str;
}

// 返回当前时间字符串
string get_current_time() {
    time_t t = std::time(nullptr);
    char buf[30];
    strftime(buf, sizeof(buf), "%Y年%m月%d日 %H:%M", std::localtime(&t));
    return string(buf);
}