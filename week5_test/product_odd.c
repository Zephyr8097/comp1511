//Written by ZephyrZhou(z5212919)
//23-03-2019
//week5 test product_odd

#include<stdio.h>

int main() {
    int lower, upper;
    printf("Enter lower: ");
    scanf("%d",&lower);
    printf("Enter upper: ");
    scanf("%d",&upper);
    int product = 1, i = lower + 1;
    while(i < upper) {
        if(i % 2 != 0) {
            product = product * i;
        }  
        i++;      
    }
    printf("%d\n",product);
    return 0;
}           
