#include "snack.h"

#include <iostream>
#include <vector>

#include "Game.h"
#include "GameBoard.h"

using namespace std;

// 获得新头位置
pair<int, int> Snack::get_new_head_position(const Direction& direction) {
    auto head = snack_body[0];

    int new_x = head.first, new_y = head.second;
    // 求蛇头新位置
    switch (direction) {
        case Direction::up:
            new_x -= 1;
            if (allow_through_bound) {
                new_x = (new_x + map_size) % map_size;
            }
            break;
        case Direction::down:
            new_x += 1;
            if (allow_through_bound) {
                new_x %= map_size;
            }
            break;
        case Direction::left:
            new_y -= 1;
            if (allow_through_bound) {
                new_y = (new_y + map_size) % map_size;
            }
            break;
        case Direction::right:
            new_y += 1;
            if (allow_through_bound) {
                new_y %= map_size;
            }
            break;
        default:
            break;
    }
    return {new_x, new_y};
}


// 移动
void Snack::move_and_may_grow(pair<int, int> new_head_position, const bool& eat_food) {
    // 蛇头入队列
    snack_body.push_front(new_head_position);

    // 蛇尾出队列
    if (!eat_food) {
        snack_body.pop_back();
    }
}