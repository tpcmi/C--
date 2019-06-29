/*指在问题求解时，总是做出在当前看来最好的选择，不从整体最优考虑，局部最优解*/

/*有一批集装箱要装入一个载重量为C的货船中，每个集装箱的质量由用户自己输入指定，在货船的装载体积不限的前提下，如何装载集装箱才能尽可能多地将集装箱装入货船中？*/
#include<stdio.h>
void sort(int w[], int t[], int n) {
	int i, j, tmp;
	/*动态开辟一个临时数组，存放w[]中的内容，用于排序*/
	int* w_tmp = (int*)malloc(sizeof(int) * n);
	for (i = 0;i < n;i++)
		t[i] = i;	/*初始化数组t*/
	for (i = 0;i < n;i++)
		w_tmp[i] = w[i];
	for(i=0;i<n-1;i++)	/*冒泡排序*/
		for(j=0;j<n-i-1;j++)
			if (w_tmp[j] > w_tmp[j + 1]) {
				tmp = w_tmp[j];
				w_tmp[j] = w_tmp[j + 1];
				w_tmp[j + 1] = tmp;
				tmp = t[j];
				t[j] = t[j + 1];
				t[j + 1] = tmp;
			}
}

void loading(int x[], int w[], int c, int n) {
	int i, s = 0;
	/*动态开辟一个临时数组，存放w[]下标，如果t[i],t[j],i<j,则w[t[i]]<=w[t[j]]*/
	int* t = (int*)malloc(sizeof(int) * n);
	sort(w, t, n);
	for (i = 0;i < n;i++)
		x[i] = 0;
	for (i = 0;i < n && w[t[i]] <= c;i++) {
		x[t[i]] = 1;
		c -= w[t[i]];
	}
}

int main() {
	int x[5], w[5], c, i;
	printf("Please input the maxium loading of the sheep\n");
	scanf("%d", &c);
	printf("Please input the weight of Five box\n");
	for (i = 0;i < 5;i++)
		scanf("%d", &w[i]);
	loading(x, w, c, 5);
	printf("The following boxes will be loaded\n");
	for (i = 0;i < 5;i++) 
		if (x[i] == 1)
			printf("BOX:%d", i);
	getch();
}