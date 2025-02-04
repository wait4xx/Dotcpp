#include <stdio.h>
int main()
{
    char input_str[100], output_str[100], input_char;
    scanf("%99s", input_str);
    for(int i=0; input_str[i] != '\0'; i++)
    {
        char output_char;
        input_char = input_str[i];
        output_char = input_char + 4;
        output_str[i] = output_char;
    }
    printf("%s", output_str);
    return 0;
}