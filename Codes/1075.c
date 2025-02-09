//
// Created by XX on 2025/02/09.
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14159265358979323846
#define MAX_CASES 26  // 定义最大用例数

struct billiards {
    int L, W, x, y, R, a, v, s;
};

int read_input(struct billiards *billiardses, int max_cases);
void get_point(struct billiards temp);
void get_point_new(struct billiards temp);

int main() {
    struct billiards billiardses[MAX_CASES];
    int count = read_input(billiardses, MAX_CASES);

    for (int i = 0; i < count; i++) {
        get_point_new(billiardses[i]);
    }

    return 0;
}

int read_input(struct billiards *billiardses, int max_cases) {
    int count = 0;
    while (count < max_cases) {
        int L, W, x, y, R, a, v, s;
        // 读取输入并检查完整性
        if (scanf("%d %d %d %d %d %d %d %d", &L, &W, &x, &y, &R, &a, &v, &s) != 8) {
            while (getchar() != '\n');  // 清除错误输入
            continue;
        }

        // 终止条件：所有参数（包括 R）均为0
        if (L == 0 && W == 0 && x == 0 && y == 0 && R == 0 && a == 0 && v == 0 && s == 0) {
            break;
        }

        // 检查输入合法性
        if (R <= 0 || x < R || x + R > L || y < R || y + R > W || a < 0 || a >= 360 || v < 0 || s < 0) {
            continue;
        }

        // 存储到结构体
        billiardses[count] = (struct billiards){L, W, x, y, R, a, v, s};
        count++;
    }
    return count;
}

void get_point(struct billiards temp) {
    double x = temp.x, y = temp.y;
    double dx = temp.v * cos(temp.a * PI / 180);
    double dy = temp.v * sin(temp.a * PI / 180);

    for (int i = 0; i < temp.s; i++) {
        x += dx;
        y += dy;

        // 处理左右壁碰撞
        if (x - temp.R <= 0 || x + temp.R >= temp.L) {
            dx = -dx;
            x = (x - temp.R <= 0) ? temp.R : temp.L - temp.R;
        }

        // 处理上下壁碰撞
        if (y - temp.R <= 0 || y + temp.R >= temp.W) {
            dy = -dy;
            y = (y - temp.R <= 0) ? temp.R : temp.W - temp.R;
        }
    }

    printf("%.2lf %.2lf\n", x, y);
}

void get_point_new(struct billiards temp)
{
    int a = temp.a;
    int v = temp.v;
    int R = temp.R;
    int x = temp.x;
    int y = temp.y;
    int L = temp.L;
    int W = temp.W;
    int s = temp.s;

    double angle = a * PI / 180.0; // 将角度转换为弧度
    double vx = v * cos(angle); // x方向速度
    double vy = v * sin(angle); // y方向速度
    
    double newX = x, newY = y;
    
    for (int t = 0; t < s; t++) {
        newX += vx;
        newY += vy;
        
        // 检查与边界的碰撞
        if (newX - R < 0) { // 左壁
            newX = 2 * R - newX;
            vx = -vx;
        }
        if (newX + R > L) { // 右壁
            newX = 2 * (L - R) - newX;
            vx = -vx;
        }
        if (newY - R < 0) { // 下壁
            newY = 2 * R - newY;
            vy = -vy;
        }
        if (newY + R > W) { // 上壁
            newY = 2 * (W - R) - newY;
            vy = -vy;
        }
    }
    
    printf("%.2lf %.2lf\n", newX, newY);
}