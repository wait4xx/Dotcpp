//
// Created by XX on 2025/02/07.
//

#include<stdio.h>
#include<stdlib.h>
int main()

{

    int a, b, count;
    char symbol1, symbol2, c[3];
    count = 0;

    while(scanf("%d%c%d%c%s", &a, &symbol1, &b, &symbol2, c) != EOF)
    {
        if(c[0] == '?')
        {
            continue;
        }
        switch(symbol1)
        {
            case '+':if(a + b == atoi(c)){
                count++;
            };break;
            case '-':if(a - b == atoi(c)){
                count++;
            };break;
        }
    }
    printf("%d", count);
    return 0;

}