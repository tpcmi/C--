/*概率算法分为四类：数值概率算法，蒙特卡洛算法，拉斯维加斯算法，舍伍德算法；
 数值概率算法往往只能得到近似解，并且精度随着计算时间的增加而不断提高。*/

/*设f(x)=1-x^2,计算定积分：I=f(x)从0到1的定积分。*/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<time.h>
double Darts(int n) {
	double x, y;
	time_t t;
	int i, count = 0;
	srand(unsigned)time(&t);
	for (i = 0;i < n;i++) {
		x = rand() % 100 / 100.0;
		y = rand() % 100 / 100.0;
		if (y <= 1 - pow(x, 2))
			count++;
	}
	return (double)count / (double)n;
}

int main() {
	int n;
	printf("Please input the accuracy\n");
	scanf("%d", &n);
	printf("The result is about\n");
	printf("%f\n", Darts(n));
}