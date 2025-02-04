//
// Created by XX on 2024/12/23.
//

# include <stdio.h>
# include <stdlib.h>

void is_complete(const int num);

int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        is_complete(i);
    }
    return 0;
}

void is_complete(const int num)
{
    int sum = 0, index = 0;
    // int factors[num/2] = {}; // 用常变量定义未报错（C99及以上标准支持，但依赖于编译器的支持）
    int *factors = (int *)malloc((num / 2) * sizeof(int)); // 更为准确的做法
    if (factors == NULL)
    {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    for (int i = 1; i <= num / 2; i ++)
    {
        if (!(num % i))
        {
            sum += i;
            factors[index] = i;
            index++;
        }
    }
    if (sum == num)
    {
        printf("%d its factors are", num);
        for (int i = 0; i < index; i++)
        {
            printf(" %d", factors[i]);
        }
        printf("\n");
    }
    free(factors);
}