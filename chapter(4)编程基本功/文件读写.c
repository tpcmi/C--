/*创建一个后缀名为txt的文件，并向该文件中写入一个字符串保存起来。再打开该文件，读出文件中的内容。
C库函数中提供了一组对文件操作的函数，即I/O函数，都定义在stdio.h的头文件中,需要用到以下I/O函数：
		FILE *fopen(char *filename,char *type);						//打开指定路径文件；
		int fclose(FILE *fp);										//关闭文件；
		int fread(void *buf,int size,int count,FILE *fp);			//读文件函数；
		int fwrite(void *buf,int size,int count,FILE *fp);  		//写文件函数；
fp是一个FILE类型的变量，用于保存一个文件的指针。*/

#include<stdio.h>
#include<string.h>
int main() {
	FILE *fp;
	char pathName[20], txt1[20] = { '\0' }, txt2[20] = { '\0' };
	int fileLen;
	printf("Please type the path name of file\n");
	scanf("%s", pathName);
	fp = (pathName, "w");
	printf("Please input a string to this file\n");
	scanf("%s", txt1);
	fileLen = strlen(txt1);
	fwrite(txt1, fileLen, 1, fp);
	fclose(fp);
	printf("The file has been saved\n");
	printf("The content of file :%s is", pathName);
	fp=fopen(pathName, "r");
	fread(txt2, fileLen, 1, fp);		//将文件内容写入缓冲区txt2；
	printf("%s\n", txt2);
}


/*计算文件大小
		fseek(FILE *fp,long offset,int base);		//重定位流上的文件指针，即将fp指向的文件的位置指针移向以base为基准，以offset为偏移量的位置；
		ftell(FILE *fp);		//返回当前文件指针的位置，这个位置是指当前文件指针相对于文件开头的位偏移量。*/

#include<stdio.h>
int main() {
	FILE* fp;
	long f;
	fp = fopen("C:\\test.txt", "r");
	fseek(fp, 0, SEEK_END);		//将文件指针置于最后；
	f = ftell(fp);
	fclose(fp);
	printf("The longth of the file is %d bytes\n", f);
}


/*记录程序运行的时间：
在time.h库文件中有函数可以解决这个问题。首先是clock_t类型是表示时间值的算术类型，可以记录存储一个系统时间值。另一个是clock()函数，可以返回从程序
运行开始到调用clock()函数所用的时间，返回值的类型是clock_t类型。*/

#include<stdio.h>
#include<time.h>
#include<dos.h>
int main() {
	clock_t start, end;
	start = clock();
	sleep(1);		//间隔一秒；
	end = clock();
	printf("The time was:%f\n", (end - start) / CLK_TCK);		//是将该时间转换为以秒为单位；
	return 0;
}