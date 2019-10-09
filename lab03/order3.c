//written by ZephyrZhou(z5212919@unsw.edu.au)
//written 05-03-2019
//lab03 exerciese order3
#include<stdio.h>
int main()
{
    int a,b,c,max,min,mid;
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
        mid=c;
    }if(max==a && min==c) {
        mid=b;
    }if(max==b && min==a) {
        mid=c;
    }if(max==c && min==a) {
        mid=b;
    }if(max==b && min==c) {
        mid=a;
    }if(max==c && min==b) {
        mid=a;
    }
    printf("The integers in order are: %d %d %d\n", min, mid, max);
    return 0;
}             
                
   
