#include<stdio.h>
int main() {
	int i, j, k, buf[7], tmp[7];
	for (i = 0;i <= 6;i++) {
		if (i == 0)
			printf("%d",1);
		else if (i == 1) {
			printf("\n%d %d\n", 1, 1);
			buf[0] = 1;
			buf[1] = 1;
		}
		else {
			for (j = 1;j < i + 1;j++) {
				if (j == 1 || j == i + 1) {
					printf("%d", 1);
					tmp[j - 1] = 1;
				}
				else {
					printf("%d", buf[j - 2] + buf[j - 1]);
					tmp[j - 1] = buf[j - 2] + buf[j - 1];				//������ط�������ʱ���������ڴ洢��ʱ��ӡ��ֵ����Ϊ����buf�ﻹ����һ�е����ݣ�
				}
			}
			printf("\n");
			for (k = 0;k < 7;k++)										//�˴�����i�е����ݴ�ŵ�buf�����У�
				buf[k] = tmp[k];
		}
	}
}