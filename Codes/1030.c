//
// Created by XX on 2024/12/29.
//

# include <stdio.h>

void print_arr(int arr[9])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            printf("%d ", arr[j * 3 + i]);
        }
        printf("\n");
    }
}

int main()
{
    int arr[9];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            scanf("%d", &arr[i * 3 + j]);
        }
    }
    // 转置输出打印
    print_arr(arr);
    return 0;
}