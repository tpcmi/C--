/*在包含问题的所有解的解空间树中，按照深度优先搜索的策略，从根节点出发探索解空间树。*/

/*应用回溯法思想求解四皇后问题*/
#include<stdio.h>
int count = 0;	/*记录四皇后解题的个数*/
int isCorrect(int i, int j, int(*Q)[4]) {
	int s, t;
	for (s = i, t = 0;t < 4;t++)
		if (Q[s][t] == 1 && t != j)		/*判断行*/
			return 0;
	for (t = j, s = 0;s < 4;s++)
		if (Q[s][t] == 1 && s != i)		/*判断列*/
			return 0;
	for (s = i-1, t = j-1;t>=0&&s>=0;t--,s--)
		if (Q[s][t] == 1 && t != j)		/*判断左下*/
			return 0;
	for (s = i+1, t = j+1;s < 4&&t<4;s++,t++)
		if (Q[s][t] == 1 && t != j)		/*判断右上*/
			return 0;
	for (s = i-1, t = j+1;s>=0&&t < 4;s--,t++)
		if (Q[s][t] == 1 && t != j)		/*判断左上*/
			return 0;
	for (s = i+1, t = j-1;s < 4&&t>=0;s++,t--)
		if (Q[s][t] == 1 && t != j)		/*判断右下*/
			return 0;

	return 1;
}

void Queen(int j, int(*Q)[4]) {
	int i, k;
	if (j == 4) {	/*得到一个解*/
		for (i = 0;i < 4;i++) {
			for (k = 0;k < 4;k++)
				printf("%d", Q[i][k]);
			printf("\n");
		}
		printf("\n");
		count++;
		return;
	}	
	for (i = 0;i < 4;i++) 
		if (isCorrect(i, j, Q)) {
			Q[i][j] = 1;
			Queen(j + 1, Q);
			Q[i][j] = 0;
		}
}

int main() {
	int Q[4][4];
	int i, j;
	for (i = 0;i < 4;i++)
		for (j = 00;j < 4;j++)
			Q[i][j] = 0;
	Queen(0, Q);
	printf("The number of the answers of FOUR_QUEEN are %d", count);
}


/*上楼梯问题：已知楼梯有二十台阶，上楼可以一步上一阶，也可以一步上两阶。计算共有多少种不同的上楼梯方法。*/
#include<stdio.h>
#define MAX_steps 20
int Steps[MAX_steps] = { 0 };		/*Steps[i]等于1或2，记录第i步登上的台阶数*/
int cnt = 0;

void Upstairs(int footStep, int count, int steps) {
	/*footstep为当前要登的台阶数，count是已经走的阶数，steps为走过的步数*/
	int i;
	if(count + footStep == MAX_steps){
		Steps[steps] = footStep;
		for (i = 0;i <= steps;i++)
			printf("%d", Steps[i]);
		printf("\n");
		cnt++;
		return;
	}
	if (count + footStep > MAX_steps)
		return;
	Steps[steps] = footStep;
	count += footStep;
	steps++;
	for (i = 1;i <= 2;i++)
		Upstairs(i, count, steps);
}

void Upstairs_All() {
	Upstairs(1, 0, 0);
	Upstairs(2, 0, 0);
}

int main() {
	Upstairs_All();
	printf("共有%d种走法\n", cnt);
}