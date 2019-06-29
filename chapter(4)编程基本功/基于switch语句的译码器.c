/*前缀码是一种无二异性的编码，如果要设计长短不一的编码，，必须使用前缀码。广泛应用的哈弗曼编码就是一种前缀码。*/
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