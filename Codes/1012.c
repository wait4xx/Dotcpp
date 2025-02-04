//
// Created by XX on 2024/12/21.
//

# include <stdio.h>
# include <ctype.h>

int main(){
    char input_str[200];
    int n1 = 0, n2 = 0, n3 = 0, n4 = 0;
    fgets(input_str, sizeof(input_str), stdin);
    for (int i = 0; input_str[i] != '\n' && EOF; i++) {
        if (isalpha(input_str[i])) {
            n1++;
        }
        else if (isalnum(input_str[i])) {
            n2++;
        }
        else if (isspace(input_str[i])) {
            n3++;
        }
        else {
            n4++;
        }
    }
    printf("%d %d %d %d", n1, n2, n3, n4);
    return 0;
}