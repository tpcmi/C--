/*ǰ׺����һ���޶����Եı��룬���Ҫ��Ƴ��̲�һ�ı��룬������ʹ��ǰ׺�롣�㷺Ӧ�õĹ������������һ��ǰ׺�롣*/
#include<stdio.h>
void Decode(char* str, int n) {
	int i = 0;
	while (i < n) {
		switch (str[i]) {
		case '1':
			printf("a");
			break;
		case '0': {
			i++;
			switch (str[i]) {
			case '1':printf("b");
				break;
			case '0': {
				i++;
				switch (str[i]) {
				case '1':printf("c");
					break;
				}
				break;
			}
			}
			break;
		}
		}
		i++;
	}
}

int main() {
	char str[18] = "001011101001011001";
	Decode(str, 18);
}