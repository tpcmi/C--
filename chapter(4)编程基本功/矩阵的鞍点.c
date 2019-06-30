/*在矩阵中，可能会有这样的元素，在该行中最大（有且只有一个），在该列中最小，这样的元素称为鞍点，也有可能没有鞍点。任意输入一个5*5的矩阵，寻找鞍点。*/
/*这道题核心在于在最开始的时候，设置一个标志flag，当flag为0的时候表示不是鞍点，当flag为1时表示为鞍点*/
#include<stdio.h>
int getSaddlePoint(int* x, int* y, int (*A)[5], int m, int n) {
    int max, i, j, k, flag;
    for (i = 0; i < m;i++) {	//寻找每一行；
        max = 0;
        flag = 1;
        for (j = 0;j < n;j++) 	//寻找这一行的最大点；
            if (A[i][j] > A[i][max])
                max = j;
        for(k=0;k<n;k++)    //  同行只能有一个最大值；
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
