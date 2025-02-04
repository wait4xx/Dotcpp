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

void information_output(struct Student *student, int n);

int main() {
    int n;
    scanf("%d", &n);
    char *input_str = (char *) malloc(n * sizeof(char));
    struct Student *students = (struct Student *) malloc(n * sizeof(struct Student));
    information_input(students, n);
    information_output(students, n);
    return 0;
}

void information_input(struct Student *student, int n) {
    for (int i = 0; i < n; i++) {
        scanf("%s %s %d %d %d", student[i].id, student[i].name, &student[i].score_one, &student[i].score_two,
              &student[i].score_three);
    }
}

void information_output(struct Student *student, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s,%s,%d,%d,%d\n", student[i].id, student[i].name, student[i].score_one, student[i].score_two,
               student[i].score_three);
    }
}
