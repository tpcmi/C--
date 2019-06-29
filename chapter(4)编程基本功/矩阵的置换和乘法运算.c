/*矩阵转置*/
/*在以下调用的函数的形参中都调用了指向二维数组的指针变量，数组名是指向二维数组第一行的指针，数组名+i则是指向二维数组第i+1行的指针
也就是说指向的是一个整型的一维数组，因此作为二维数组指针的传递，实参可以是数组名，但是形参一定要是如(*a)[n]的形式。其中n表示列数。*/



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



/*矩阵乘法：有A1[2][3]和A2[3][4]两个矩阵相乘.*/
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




