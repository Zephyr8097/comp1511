//Written by ZephyrZhou(z5212919@unsw.edu.au)
//Written 28-02-2019
//lab02 Exercise dating_range
#include<stdio.h>
int main(void)
{
int age, up, down;
printf("Enter your age: ");
scanf("%d", &age);
down = age * 1/2 + 7;
up = (age - 7) * 2;
if(age <= 14){
printf("You are too young to be dating.\n");
}else{
printf("Your dating range is %d to %d years old.\n",down, up);
}
return 0;
}
