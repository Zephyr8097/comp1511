//written by ZephyrZhou(z5212919@unsw.edu.au)
//written 05-03-2019
//lab03 exerciese is_leap_year
#include<stdio.h>
int main()
{
    int year;
    printf("Enter year: ");
    scanf("%d",&year);
    if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("%d is a leap year.\n",year);
    } else {
        printf("%d is not a leap year.\n",year);
    }
    return 0;
}
