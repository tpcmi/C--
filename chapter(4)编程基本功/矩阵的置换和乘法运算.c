/*����ת��*/
/*�����µ��õĺ������β��ж�������ָ���ά�����ָ���������������ָ���ά�����һ�е�ָ�룬������+i����ָ���ά�����i+1�е�ָ��
Ҳ����˵ָ�����һ�����͵�һά���飬�����Ϊ��ά����ָ��Ĵ��ݣ�ʵ�ο������������������β�һ��Ҫ����(*a)[n]����ʽ������n��ʾ������*/



#include<stdio.h>
int main() {
	int a[3][4], b[4][3];
	printf("Please input 3*4 matrix\n");
	InputMatrix(a, 3, 4);
	MatrixTranspose(a, b);
	printf("The Transposex Matrix is\n");
	OutputMatrix(b, 4, 3);
}
void InputMatrix(int(*a)[4], int n, int m) {
	int i, j;
	for (i = 0;i < n;i++)
		for (j = 0;j < m;j++)
			scanf("%d", *(a + i) + j);
}
void OutputMatrix(int(*b)[3], int n, int m) {
	int i, j;
	for (i = 0;i < n;i++) {
		for (j = 0;j < m;j++)
			printf("%d", *(*(b + i) + j));
		printf("\n");
	}
}
void MatrixTranspose(int(*a)[4], int(*b)[3]) {
	int i, j;
	for (i = 0;i < 4;i++)
		for (j = 0;j < 3;j++)
			b[i][j] = a[i][j];
}



/*����˷�����A1[2][3]��A2[3][4]�����������.*/
#include<stdio.h>
int main() {
	int A[2][3] = { {1,2,3},{4,5,6} };
	int B[3][4] = { {1,0,2,3},{4,1,5,6},{6,8,9,0} };
	int C[2][4] = { {0,0,0,0},{0,0,0,0} };
	int i, j, k;
	for (i = 0;i < 2;i++)
		for (j = 0;j < 4;j++)
			for (k = 0;k < 3;k++)
				C[i][j] = C[i][j] + A[i][k] * B[k][j];
	printf("The result is\n");
	for (i = 0;i < 2;i++) {
		for (j = 0;j < 4;j++)
			printf("%d", C[i][j]);
		printf("\n");
	}
}




