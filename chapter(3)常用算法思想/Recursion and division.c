/*����ģ�ϴ������ָ�ɹ�ģ��С��ͬ������
	1.��һ���ݹ���ڣ�
	2.��������еݹ��ԣ�
	3.�ݹ��㷨���нϵͣ�ʱ��Ϳռ临�Ӷȶ��ϸ�*/

/*����n�Ľ׳�n��*/
//ѭ���۳�
int factorial(n) {
	int i, res = 1;
	for (i = 1;i <= n;i++)
		res = res * i;
	return res;
}
//Recursion
int factorial(n) {
	if (n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}

/*��һ��������n��ʾ��һϵ��������֮�ͣ�
		n=n1+n2+...+nk		(n1>=n2>=....>=nk)	
 һ�������������в�ͬ�Ļ����磺6=6��6=5+1��6=4+2��6=4+1+1��6=3+3��6=3+2+1��6=3+1+1+1,......
 n�Ĳ�ͬ�Ļ��ָ�����Ϊn�Ļ���������6�Ļ�����Ϊ11����д�����������������n�Ļ�������*/
#include<stdio.h>
int P(int n, int m) {
	if (m == 1 || n == 1) return 1;
	if (m > n) return P(n, n);
	if (m == n) return P(n, m - 1) + 1;
	return P(n, m - 1) + P(n - m, m);
}

int main() {
	int n, s;
	printf("Please input a integer for getting the number of division\n");
	scanf("%d", &n);
	s = P(n, n);
	printf("The number of division of %d is %d\n", n, s);
}


/*�ݹ��۰����*/
#include<stdio.h>
int binary_search(int key[], int low, int high, int k) {
	int mid;
	if (low > high)
		return -1;
	else {
		mid = (low + high)/2;
		if (key[mid] == k)
			return mid;
		if (k > mid[key])
			return binary_search(key, mid + 1, high, k);
		else
			return binary_search(key,low,mid-1,k)��
	}
}

int main() {
	int n, i, addr;
	int A[10] = { 2,3,5,7,8,10,12,15,19,21 };
	printf("The contents of the Arrary A[10] are\n");
	for (i = 0; i < 10; i++)
		printf("%d", A[i]);
	printf("\nPlease input a integer for search\n");
	scanf("&d", &n);
	addr = binary_search(A, 0, 9, n);
	if (-1 != addr)
		printf("%d is at the %dth unit is array A\n", n, addr);
	else
		printf("There is no %d in array A\n", n);
}



