//written by ZephyrZhou(z5212919@unsw.edu.au)
//written 09-03-2019
//This is for lab04 perfect
#include<stdio.h>
int main(){
    int number, perfect_n = 0;
    int factor = 1, sum = 0;
    printf("Enter number: ");
    scanf("%d",&number);
    printf("The factors of %d are: \n", number);
    while(factor <= number) {
        if(number % factor == 0) {
            printf("%d\n",factor);
            sum = sum + factor;
        }
        factor++;
    }
    printf("Sum of factors = %d\n",sum);
    perfect_n = sum - number;
    if(perfect_n == number) {
        printf("%d is a perfect number\n", number);
    } else printf("%d is not a perfect number\n", number);    
    return 0;
}            
            
