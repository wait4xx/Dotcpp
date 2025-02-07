#include <stdio.h>
int main()
{
	// char ch;
	// while  ((ch = getchar()) != (EOF && '\n'))  {
	// 		putchar(ch + 4);
	// }

	// char b[] = {0};
	// b[0] = 's';
	// printf("%s", b);
	// printf("\n");

	char a[] = {0};
	char str[] = "shanbaby";
	int i;
	for (i = 0; str[i] != EOF; i++) {
	    a[i] = str[i];
		printf("%c\n", str[i]);
		// printf(a[i]);
	}
	a[i] == '\0';
	// a = str;
	printf("%s", a);



	return 0;
}