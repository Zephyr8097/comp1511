// Written 27-02-2019
// By Zephyr Zhou (z5212919@unsw.edu.au)
// For COMP1511 Lab02 Exercise1

#include<stdio.h>
int main()
{
int x;
scanf("%d",&x);
if (x>0){
        printf("You have entered a positive number.\n");
}
else if(x<0){
        printf("Don't be so negative!\n");
}
else {
        printf("You have entered zero.\n");
}
return 0;
}
