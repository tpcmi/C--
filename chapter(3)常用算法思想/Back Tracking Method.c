/*�ڰ�����������н�Ľ�ռ����У�����������������Ĳ��ԣ��Ӹ��ڵ����̽����ռ�����*/

/*Ӧ�û��ݷ�˼������Ļʺ�����*/
#include<stdio.h>
int count = 0;	/*��¼�Ļʺ����ĸ���*/
int isCorrect(int i, int j, int(*Q)[4]) {
	int s, t;
	for (s = i, t = 0;t < 4;t++)
		if (Q[s][t] == 1 && t != j)		/*�ж���*/
			return 0;
	for (t = j, s = 0;s < 4;s++)
		if (Q[s][t] == 1 && s != i)		/*�ж���*/
			return 0;
	for (s = i-1, t = j-1;t>=0&&s>=0;t--,s--)
		if (Q[s][t] == 1 && t != j)		/*�ж�����*/
			return 0;
	for (s = i+1, t = j+1;s < 4&&t<4;s++,t++)
		if (Q[s][t] == 1 && t != j)		/*�ж�����*/
			return 0;
	for (s = i-1, t = j+1;s>=0&&t < 4;s--,t++)
		if (Q[s][t] == 1 && t != j)		/*�ж�����*/
			return 0;
	for (s = i+1, t = j-1;s < 4&&t>=0;s++,t--)
		if (Q[s][t] == 1 && t != j)		/*�ж�����*/
			return 0;

	return 1;
}

void Queen(int j, int(*Q)[4]) {
	int i, k;
	if (j == 4) {	/*�õ�һ����*/
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


/*��¥�����⣺��֪¥���ж�ʮ̨�ף���¥����һ����һ�ף�Ҳ����һ�������ס����㹲�ж����ֲ�ͬ����¥�ݷ�����*/
#include<stdio.h>
#define MAX_steps 20
int Steps[MAX_steps] = { 0 };		/*Steps[i]����1��2����¼��i�����ϵ�̨����*/
int cnt = 0;

void Upstairs(int footStep, int count, int steps) {
	/*footstepΪ��ǰҪ�ǵ�̨������count���Ѿ��ߵĽ�����stepsΪ�߹��Ĳ���*/
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
	printf("����%d���߷�\n", cnt);
}