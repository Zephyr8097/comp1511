//written by ZephyrZhou(z5212919@unsw.edu.au)
//written 07-03-2019
//lab03 exerciese order3_challenge2
#include <stdio.h>
int main()
{
	int a,b,c;
	printf("Enter integer: ");
	scanf("%d", &a);
    printf("Enter integer: ");
	scanf("%d", &b);
	printf("Enter integer: ");
	scanf("%d", &c);
	printf("The integers in order are: %d %d %d\n",        
	    (((((a >= b)* b + (a <= b)* a) >= c)* c + (((a >= b)* b + (a <= b)* a) <= c) * ((a >= b)* b + (a <= b)* a))/((((a >= b)* b + (a <= b)* a) >= c) + (((a >= b)* b + (a <= b)* a) <= c))),
	    (a + b + c - (((((a >= b)* a + (a <= b)* b)/((a >= b) + (a <= b)) >= c)* ((a >= b)* a + (a <= b)* b)/((a >= b) + (a <= b)) + (((a >= b)* a + (a <= b)* b)/((a >= b) + (a <= b)) <= c) * c)/((((a >= b)* a + (a <= b)* b)/((a >= b) + (a <= b)) >= c) + (((a >= b)* a + (a <= b)* b)/((a >= b) + (a <= b)) <= c))) - (((((a >= b)* b + (a <= b)* a) >= c)* c + (((a >= b)* b + (a <= b)* a) <= c) * ((a >= b)* b + (a <= b)* a))/((((a >= b)* b + (a <= b)* a) >= c) + (((a >= b)* b + (a <= b)* a) <= c)))),
	    (((((a >= b)* a + (a <= b)* b)/((a >= b) + (a <= b)) >= c)* ((a >= b)* a + (a <= b)* b)/((a >= b) + (a <= b)) + (((a >= b)* a + (a <= b)* b)/((a >= b) + (a <= b)) <= c) * c)/((((a >= b)* a + (a <= b)* b)/((a >= b) + (a <= b)) >= c) + (((a >= b)* a + (a <= b)* b)/((a >= b) + (a <= b)) <= c)))		    
	    );
	    return 0;
}	    
