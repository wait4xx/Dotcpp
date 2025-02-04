//
// Created by XX on 2025/2/2.
//

#include <stdio.h>
#include <stdlib.h>

struct Student {
    char id[20];
    char name[20];
    int score_one;
    int score_two;
    int score_three;
};

void information_input(struct Student *student, int n);

void score_sort(struct Student *student, int n);

int main()
{
    int n;
    scanf("%d", &n);
    char *input_str = (char *)malloc(n * sizeof(char));
    struct Student *students = (struct Student *)malloc(n * sizeof(struct Student));
    information_input(students, n);
    score_sort(students, n);
    return 0;
}

void information_input(struct Student *student, int n)
{
    for (int i = 0; i < n; i++)
    {
        scanf("%s %s %d %d %d", student[i].id, student[i].name, &student[i].score_one, &student[i].score_two, &student[i].score_three);
    }
}

void score_sort(struct Student *student, int n)
{
    int score_one_avg = 0, score_two_avg = 0, score_three_avg = 0;
    int scores = student[0].score_one + student[0].score_two + student[0].score_three;
    int max_score_index = 0;
    for (int i = 0; i < n; i++)
    {
        score_one_avg += student[i].score_one;
        score_two_avg += student[i].score_two;
        score_three_avg += student[i].score_three;
        int scores_temp = student[i].score_one + student[i].score_two + student[i].score_three;
        if (scores_temp > scores)
        {
            max_score_index = i;
        }
    }
    score_one_avg /= n;
    score_two_avg /= n;
    score_three_avg /= n;
    printf("%d %d %d\n", score_one_avg, score_two_avg, score_three_avg);
    printf("%s %s %d %d %d\n", student[max_score_index].id, student[max_score_index].name, student[max_score_index].score_one, student[max_score_index].score_two, student[max_score_index].score_three);
}