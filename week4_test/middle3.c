//written by ZephyrZhou(z5212919@unsw.edu.au)
//written 14-03-2019
//week4 test middle3
#include<stdio.h>
int main()
{
    int a,b,c,max,min,middle=0;
    printf("Enter integer: ");
    scanf("%d", &a);
    printf("Enter integer: ");
    scanf("%d", &b);
    printf("Enter integer: ");
    scanf("%d", &c);
    //max
    if(a >= b) {
        max=a;
    } else {
        max=b;
    } if(c >= max) {
        max=c;
    }
    //min
    if(a <= b) {
        min=a;
    } else {
        min=b;
    } if(c <= min) {
        min=c;
    }
    //mid
    if(max==a && min==b) {
        middle=c;
    }if(max==a && min==c) {
        middle=b;
    }if(max==b && min==a) {
        middle=c;
    }if(max==c && min==a) {
        middle=b;
    }if(max==b && min==c) {
        middle=a;
    }if(max==c && min==b) {
        middle=a;
    }
    printf("Middle: %d\n",middle);
    return 0;
}
