//有红黄绿三种颜色的球，各3个，3个，6个，现将这12个球混合放进盒子当中，任意摸出8个球，有多少种颜色搭配？

//这道题要发现绿球最少不能取0，1这两个数，然后遍历即可；

#include<stdio.h>
int main(){
    int red,yellow,green;
    printf("red yellow, green\n");
    for(red=0;red<=3;red++)
        for(yellow=0;yellow<=3;yellow++)
            for(green=2;green<=6;green++)
                if(red+yellow+green==8)
                    printf(" %d    %d    %d\n",red,yellow,green);
}
