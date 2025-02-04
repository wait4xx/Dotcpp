//
// Created by XX on 2024/12/29.
//

# include <stdio.h>

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
    int num1 = 0, num2 = 0;
    num1 = arr[0] + arr[4] + arr[8];
    num2 = arr[2] + arr[4] + arr[6];

    printf("%d %d", num1, num2);
    return 0;
}