//
// Created by XX on 2024/12/21.
//

#include <stdio.h>

int func(int n);

int main() {
    int n, result;
    scanf("%d", &n);
    result = func(n);
    printf("%d\n", result);
    return 0;
}

int func(int n) {
    int result = 0; // 初始化result
    if (n <= 100000)
    {
        result = n * 0.1;
    }
    else if (n > 100000 && n <= 200000)
    {
        result = func(100000) + (n - 100000) * 0.075;
    }
    else if (n > 200000 && n <= 400000)
    {
        result = func(200000) + (n - 200000) * 0.05;
    }
    else if (n > 400000 && n <= 600000)
    {
        result = func(400000) + (n - 400000) * 0.03;
    }
    else if (n > 600000 && n <= 1000000)
    {
        result = func(600000) + (n - 600000) * 0.015;
    }
    else
    {
        result = func(1000000) + (n - 1000000) * 0.01;
    }
    return result;
}