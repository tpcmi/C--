/*结构化程序设计要求将具有特定功能的程序块编写成函数，这样程序结构清晰，易于调试，复用性强，也易于代码维护。
通过调用函数改变主函数中的值，函数的调用是在内存的堆栈中实现的，因此一旦函数调用完毕，函数内部的局部变量都
会被释放掉，想要对主函数中的数组值进行修改，无法通过函数的返回值来实现，只能将数组的首地址作为函数的参数进
行传递，被调函数通过主函数传递来的数组首地址对数组内容进行修改。*/
#include<stdio.h>
void inputArray(int* array, int len) {
	int i;
	for (i = 0;i < len;i++)
		scanf("%d", array + i);
}

int main() {
	int i, array[10];
	printf("Please input data for array\n");
	inputArray(array, 10);		
	for (i = 0;i < 10;i++)
		printf("%d", array[i]);
}

/*inputArray()函数里的实参array是数组名，是一个地址常量，表示数组的首地址，形参array是一个指针变量，用于接收
实参传递过来数组的首地址。此处形参也可以定义为int array[]的形式，但只限于数组首地址的传递。对于一般指针的传递，
形参还是需要定义为指针变量的形式，array+i等价于&array[i]*/