#include<stdio.h>
int main() {
	char c;
	printf("Please input a character\n");
	scanf("%c", &c);
	getchar();
	printf("The ASCⅡ of %c is %d\n", c, c);	/*玄机在这一行*/
}