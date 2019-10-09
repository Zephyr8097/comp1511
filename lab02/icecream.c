// Written By ZephyrZhou(z5212919@unsw.edu.au)
// Written 28-02-2019
// For COMP1511 Lab02 Exercise icecream

#include<stdio.h>
int main()
{
int x,y;
printf("How many scoops? ");
scanf("%d",&x);
printf("How many dollars does each scoop cost? ");
scanf("%d",&y);
if (10-x*y>=0)printf("You have enough money!\n");
else printf("Oh no, you don't have enough money :(\n");
return 0;
}
