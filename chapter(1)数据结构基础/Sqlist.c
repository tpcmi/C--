#include<stdio.h>
#include<stdlib.h>

//静态地定义顺序表
#define MaxSize 100
ElemType Sqlist[MaxSize];
int  len;

//动态地生成顺序表
#define MaxSize 100
typedef  struct {
	ElemType *elem;	//指向顺序表的首地址
	int length;
	int listsize;
}Sqlist;
void initSqLlist(Sqlist *L) {	//初始化一个顺序表
	L->elem(int *)malloc(MaxSize * sizeof(ElemType));
	if (!L->elem) exit(0);
	L->length = 0;
	L->listsize = MaxSize;
}

//    difference:静态定义的顺序表占用的内存空间开辟在内存的静态区（函数栈），这个区域的内存空间会随着
//函数调用完成而被系统自动回收。动态生成的顺序表占用的内存开辟在内存的动态区（堆内存），不会被系统自动
//回收，需要程序去主动释放





/*静态顺序表第i个位置插入元素*/
void InsertElem(ElemType Sqlist[], int &n, int i, ElemType item) {
	/*该顺序表原长为n*/
	int t;
	if (n == MaxSize || i<1 || i>n + 1)
		exit(0);
	for (t = n - 1;t > i - 1;t--)
		Sqlist[t + 1] = Sqlist[t];
	Sqlist[i - 1] = item;
	n = n + 1;
}
/*动态顺序表中第i个位置插入元素优势在于如果顺序表已满可以追加一段内存空间*/

/*顺序表中删除元素*/

/*实例1：创建一个静态顺序表存放整数，大小为10，完成以下操作
	（1）输入6个整数，打印顺序表的内容，显示表中剩余空间的个数；
	（2）在顺序表第三个位置插入0，打印顺序表的内容，显示表中剩余空间的个数；
	（3）试图向表中第11个位置插入整数0，程序提示超出范围；
	（4）删除第6个元素打印顺序表的内容，显示表中剩余空间的个数；*/
void insertElem(int Sqlist[], int *len,int i,int x) {
	int t;
	if (*len == MaxSize || i<1 || i>len + 1) {
		printf("This insert is illegal\n");
		return;
	}
	for (t = *len - 1;t >= i - 1;t--)
		Sqlist[t + 1] = Sqlist[t];
	Sqlist[t - 1] = x;
	*len = *len + 1;
}
void DelElem(int Sqlist[], int* len, int i) {
	int j;
	if (i<1 || i> * len) {
		printf("This insert is illegal\n");
		return;
	}
	for (j = i;j < *len - 1;j++)
		Sqlist[j - 1] = Sqlist[j];
	*len = *len - 1;
}
/*测试函数*/
main() {
	int Sqlist[MaxSize];
	int len;
	int i;
	printf("Please input six integer number\n");

	for (i = 0;i < 6;i++)
		scanf("%d", &Sqlist[i]);
	len = 6;
	for (i = 0;i < len;i++)
		printf("%d", Sqlist[i]);
	printf("\nThe spare length is %d\n", MaxSize - len);

	insertElem(Sqlist, &len, 3, 0);
	for (i = 0;i < len;i++)
		printf("%d", Sqlist[i]);
	printf("\nThe spare length is %d\n", MaxSize - len);

	insertElem(Sqlist, &len,11, 0);
	DelElem(Sqlist, &len, 6);
	for (i = 0;i < len;i++)
		printf("%d", Sqlist[i]);
	printf("\nThe spare length is %d\n", MaxSize - len);
}


