/*����һ����׺��Ϊtxt���ļ���������ļ���д��һ���ַ��������������ٴ򿪸��ļ��������ļ��е����ݡ�
C�⺯�����ṩ��һ����ļ������ĺ�������I/O��������������stdio.h��ͷ�ļ���,��Ҫ�õ�����I/O������
		FILE *fopen(char *filename,char *type);						//��ָ��·���ļ���
		int fclose(FILE *fp);										//�ر��ļ���
		int fread(void *buf,int size,int count,FILE *fp);			//���ļ�������
		int fwrite(void *buf,int size,int count,FILE *fp);  		//д�ļ�������
fp��һ��FILE���͵ı��������ڱ���һ���ļ���ָ�롣*/

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
	fread(txt2, fileLen, 1, fp);		//���ļ�����д�뻺����txt2��
	printf("%s\n", txt2);
}


/*�����ļ���С
		fseek(FILE *fp,long offset,int base);		//�ض�λ���ϵ��ļ�ָ�룬����fpָ����ļ���λ��ָ��������baseΪ��׼����offsetΪƫ������λ�ã�
		ftell(FILE *fp);		//���ص�ǰ�ļ�ָ���λ�ã����λ����ָ��ǰ�ļ�ָ��������ļ���ͷ��λƫ������*/

#include<stdio.h>
int main() {
	FILE* fp;
	long f;
	fp = fopen("C:\\test.txt", "r");
	fseek(fp, 0, SEEK_END);		//���ļ�ָ���������
	f = ftell(fp);
	fclose(fp);
	printf("The longth of the file is %d bytes\n", f);
}


/*��¼�������е�ʱ�䣺
��time.h���ļ����к������Խ��������⡣������clock_t�����Ǳ�ʾʱ��ֵ���������ͣ����Լ�¼�洢һ��ϵͳʱ��ֵ����һ����clock()���������Է��شӳ���
���п�ʼ������clock()�������õ�ʱ�䣬����ֵ��������clock_t���͡�*/

#include<stdio.h>
#include<time.h>
#include<dos.h>
int main() {
	clock_t start, end;
	start = clock();
	sleep(1);		//���һ�룻
	end = clock();
	printf("The time was:%f\n", (end - start) / CLK_TCK);		//�ǽ���ʱ��ת��Ϊ����Ϊ��λ��
	return 0;
}