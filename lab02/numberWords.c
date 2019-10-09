//Written By ZephyrZhou(z5212919@unsw.edu.au)
//Written 28-02-2019
//lab02 Exercise numberWords
#include<stdio.h>
int main()
{
    int i;
    printf("Please enter an integer: ");
    scanf("%d",&i);
    if(i == 1) {
        printf("You entered one.\n");
    } else if(i == 2){
        printf ("You entered two.\n");
    } else if(i == 3){
        printf("You entered three.\n");
    } else if(i == 4){
        printf("You entered four.\n");
    } else if(i == 5){
        printf("You entered five.\n");
    } else if(i > 5){
        printf("You entered a number greater than five.\n");
    } else if(i < 1){
        printf("You entered a number less than one.\n");
    }
    return 0;
}
