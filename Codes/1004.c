#include <stdio.h>

int born(int x){
    if(x > 4){
        return born(x - 1) + born(x - 3);
    }
    return x;
}

int main()
{
    int n, n_array[100], i = 0;
    
    while(1){
        scanf("%d", &n);
        n_array[i] = n;
        if(n == 0){
            break;
        }
        i++;
    }

    for(int i=0; n_array[i] != 0; ++i){
        printf("%d\n", born(n_array[i]));
    }
    return 0;
}