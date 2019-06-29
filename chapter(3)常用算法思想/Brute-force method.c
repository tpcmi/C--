/*寻找[1,100]之间的素数*/
#include<stdio.h>
int isPrime(int n) {
	int i;
	for (i = 2;i < n;i++)
		if (n % i == 0)
			return 0;
	return 1;
}

getPrime(int low, int high) {
	int i;
	for (i = low;i < high;i++)
		if (isPrime(i))
			printf("%d", i);
}

int main() {
	int low, high;
	printf("Please input the domain for searching prime\n");
	printf("low limitation:");
	scanf("%d", &low);
	printf("high limitation:");
	scanf("%d", &high);
	printf("The whole primes in this domain are\n");
	getPrime(low, high);
}


/*Tom有五本书，借给A，B，C三位同学，每人只能借一本书，则Tom有多少种不同的借书方法*/
#include<stdio.h>
int main() {
	int i, j, k;
	printf("There are different methods for TOM to distribute his books to A,B,C\n");
	for (i = 1;i <= 5;i++)
		for (j = 1;j <= 5;j++)
			for (k = 1;k <= 5;k++)
				if (i != j && i != k && j != k)
					printf("%d,%d,%d", i, j, k);
}