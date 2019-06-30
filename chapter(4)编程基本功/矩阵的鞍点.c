/*�ھ����У����ܻ���������Ԫ�أ��ڸ������������ֻ��һ�������ڸ�������С��������Ԫ�س�Ϊ���㣬Ҳ�п���û�а��㡣��������һ��5*5�ľ���Ѱ�Ұ��㡣*/
/*���������������ʼ��ʱ������һ����־flag����flagΪ0��ʱ���ʾ���ǰ��㣬��flagΪ1ʱ��ʾΪ����*/
#include<stdio.h>
int getSaddlePoint(int* x, int* y, int (*A)[5], int m, int n) {
    int max, i, j, k, flag;
    for (i = 0; i < m;i++) {	//Ѱ��ÿһ�У�
        max = 0;
        flag = 1;
        for (j = 0;j < n;j++) 	//Ѱ����һ�е����㣻
            if (A[i][j] > A[i][max])
                max = j;
        for(k=0;k<n;k++)    //  ͬ��ֻ����һ�����ֵ��
            if(A[i][max]==A[i][k]&& max!=k){
                flag=0;
                break;
            }
        if(flag==1){
            for(k=0;k<m;k++){
                if(A[k][max]<=A[i][max]&&k!=i){
                    flag=0;
                    break;
                }
            }
        }
        if(flag==1){
            *x=i;
            *y=max;
            return 1;
        }
    }
    return 0;
}

int main(){
    int A[5][5],i,j,x,y;
    printf("Please input some digit into the 5*5 matrix\n");
    for(i=0;i<5;i++)
        for(j=0;j<5;j++)
            scanf("%d",&A[i][j]);
    if(getSaddlePoint(&x,&y,A,5,5))
        printf("\nSaddlePoint is at (%d,%d)",x+1,y+1);
    else
        printf("\nThere is no saddlepoint in the matrix\n");
}
