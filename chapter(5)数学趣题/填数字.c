//已知    ABCD*E=DCBA,求每个字母分别代表什么数字,其中每个数字各不相同；
//穷举法

#include<stdio.h>
int main(){
    int n,E=1,mul=0;
    while(E<=9){
        for(n=1000;n<=9876;n++){
            mul=E*n;
            if(mul<=9876)
                test(mul,n,E);
        }
        E++;
    }
}

int test(int x,int y,int z){
    int i,sum=0,temp=0;
    int a[4]={0,0,0,0};
    temp=x;
    for(i=0;i<4;i++){

        a[i]=temp%10;
        temp/=10;
    }
    sum=a[0]*1000+a[1]*100+a[2]*10+a[3];
    if(sum==y&&a[0]!=a[1]&&a[0]!=a[2]&&a[0]!=a[3]&&a[1]!=a[2]&&a[1]!=a[3]&&a[2]!=a[3]&&a[0]!=z&&a[1]!=z&&a[2]!=z&&a[3]!=z)
        printf("%d*%d=%d\n",z,y,x);
}
