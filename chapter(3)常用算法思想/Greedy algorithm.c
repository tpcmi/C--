/*ָ���������ʱ�����������ڵ�ǰ������õ�ѡ�񣬲����������ſ��ǣ��ֲ����Ž�*/

/*��һ����װ��Ҫװ��һ��������ΪC�Ļ����У�ÿ����װ����������û��Լ�����ָ�����ڻ�����װ��������޵�ǰ���£����װ�ؼ�װ����ܾ����ܶ�ؽ���װ��װ������У�*/
#include<stdio.h>
void sort(int w[], int t[], int n) {
	int i, j, tmp;
	/*��̬����һ����ʱ���飬���w[]�е����ݣ���������*/
	int* w_tmp = (int*)malloc(sizeof(int) * n);
	for (i = 0;i < n;i++)
		t[i] = i;	/*��ʼ������t*/
	for (i = 0;i < n;i++)
		w_tmp[i] = w[i];
	for(i=0;i<n-1;i++)	/*ð������*/
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
	/*��̬����һ����ʱ���飬���w[]�±꣬���t[i],t[j],i<j,��w[t[i]]<=w[t[j]]*/
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