//
// Created by XX on 2024/12/29.
//

# include <stdio.h>

void num_separation(int num);

int main()
{
    int num;
    scanf("%d", &num);
    num_separation(num);
    return 0;
}

// 数字分离（递归）
// 每次调用函数时，将数字除以10，直到数字为0
void num_separation(int num)
{
    if (num == 0)
    {
        return;
    }
    num_separation(num / 10);
    printf("%d ", num % 10);
}
