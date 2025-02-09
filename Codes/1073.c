//
// Created by XX on 2025/02/07.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct question
{
    int num_one;
    char operator;
    int num_two;
    int result;
};

int check_homework(struct question *questions, int n);

int main()
{
    int count = 0;
    struct question *questions = malloc(sizeof(struct question));
    while (1)
    {
        char temp[50];
        if (fgets(temp, sizeof(temp), stdin) != NULL && temp[0] != '\n')
        {
            int num_one, num_two;
            int result = 9999;
            char operator;
            if (strchr(temp, '?') != NULL)
            {
                char temp_c;
                sscanf(temp, "%d%c%d=%c", &num_one, &operator, &num_two, &temp_c);
            }
            else
            {
                sscanf(temp, "%d%c%d=%d", &num_one, &operator, &num_two, &result);
            }
            questions[count].num_one = num_one;
            questions[count].operator = operator;
            questions[count].num_two = num_two;
            questions[count].result = result;
            count++;
            questions = (struct question *)realloc(questions, sizeof(struct question) * (count + 1));
        }
        else
        {
            break;
        }
    }

    printf("%d\n", check_homework(questions, count));
    
    return 0;
}

int check_homework(struct question *questions, int n)
{
    int uncorrect = 0;
    for (int i = 0; i < n; i++)
    {
        if (questions[i].result == 9999) uncorrect++;
        else
        {
            if (questions[i].operator == '+')
            {
                if (questions[i].num_one + questions[i].num_two != questions[i].result) uncorrect++;
            }
            else
            {
                if (questions[i].num_one - questions[i].num_two != questions[i].result) uncorrect++;
            }
        }
    }
    return uncorrect;
}
