/*�ھ����У����ܻ���������Ԫ�أ��ڸ���������ڸ�������С��������Ԫ�س�Ϊ���㣬Ҳ�п���û�а��㡣��������һ��5*5�ľ���Ѱ�Ұ��㡣*/
/*���������������ʼ��ʱ������һ����־flag����flagΪ0��ʱ���ʾ���ǰ��㣬��flagΪ1ʱ��ʾΪ����*/
#include<stdio.h>
int main() {
	int getSaddlePoint(int* x, int* y, int (*A)[5], int m, int n) {
		int max, i, j, k, flag;
		for (i = 0, i < m;i++) {	//Ѱ��ÿһ�У�
			max = 0;
			flag = 1;
			for (j = 1;j < n;j++) 	//Ѱ����һ�е����㣻
				if (A[i][j] > A[i][max])
					max = j;
			for(k=0,k<n;k++)
				if(A[i][max]==A[i])
		}
	}
}