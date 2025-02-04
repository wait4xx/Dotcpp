//
// Created by XX on 2025/2/2.
//

#include <stdio.h>

#define LEAO_YEAR(y) \
    do{ \
      if(y % 4 == 0 && y % 100 != 0 || y % 400 == 0) \
        printf("L\n"); \
      else \
        printf("N\n"); \
    }while(0)

int main()
{
    int year;
    scanf("%d", &year);
    LEAO_YEAR(year);
    return 0;
}