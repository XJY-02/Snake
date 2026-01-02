#include <iostream>

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