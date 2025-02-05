//
// Created by XX on 2025/2/5.
//

#include <stdio.h>
#include <stdlib.h>

void statics(int *scores, int n, int *result);

int main()
{
    int *scores = (int *) malloc(10 * sizeof(int));
    int flag = 1;
    int count = 0;
    while (flag)
    {
        int temp = 0;
        scanf("%d", &temp);
        if (temp == 0) flag = 0;
        else
        {
            count++;
            if (count > 10) scores = (int *) realloc(scores, (count) * sizeof(int));
            scores[count - 1] = temp;
        }
    }
    int result[3] = {0, 0, 0};
    statics(scores, count, result);
    printf(">=85:%d\n60-84:%d\n<60:%d", result[0], result[1], result[2]);
    return 0;
}

void statics(int *scores, int n, int *result)
{
    for (int i = 0; i < n; i++)
    {
        if (scores[i] >= 85) result[0]++;
        else if (scores[i] >= 60) result[1]++;
        else result[2]++;
    }
}