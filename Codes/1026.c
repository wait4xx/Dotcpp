//
// Created by XX on 2024/12/29.
//

# include <stdio.h>

int main()
{
    int arr[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 9; i >= 0; i--)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}