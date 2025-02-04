//
// Created by XX on 2024/12/28.
//

# include <stdio.h>

int main()
{
    int number[10], number_sort[10];
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &number[i]);
    }
    int index = 0;
    while (1)
    {
        if (index == 10)
        {
            break;
        }
        if (!index)
        {
            for (int j = 0; j < 10; j++)
            {
                if (number[index] > number[j])
                {
                    number_sort[index] = number[j];
                }
            }
            index++;
        }
        else
        {
            int index_new = 0;
            int number_new[10 -index];
            for (int j = 0; j < 10; j++)
            {
                if (number[j] > number_sort[index - 1])
                {
                    number_new[index_new] = number[j];
                    index_new++;
                }
            }
            int number_min = number_new[0];
            for (int i = 0; i < 10 -index; i++)
            {
                if (number_min > number_new[i])
                {
                    number_min = number_new[i];
                }
            }
            number_sort[index] = number_min;
            index++;
        }
    }
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", number_sort[i]);
    }
    return 0;
}
