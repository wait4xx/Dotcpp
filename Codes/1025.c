//
// Created by XX on 2024/12/29.
//

# include <stdio.h>

int main()
{
    int arr[9], num = 0;
    for (int i = 0; i < 9; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &num);
    if (arr[0] > arr[8])
    {
        for (int i = 0; i < 9; i++)
        {
            if (arr[i] < num)
            {
                printf("%d\n", num);
                printf("%d\n", arr[i]);
                num = arr[8];
            }
            else
            {
                printf("%d\n", arr[i]);
            }
        }
    }
    else
    {
        for (int i = 0; i < 9; i++)
        {
            if (arr[i] > num)
            {
                printf("%d\n", num);
                printf("%d\n", arr[i]);
                num = arr[8];
            }
            else
            {
                printf("%d\n", arr[i]);
            }
        }
    }
    return 0;
}