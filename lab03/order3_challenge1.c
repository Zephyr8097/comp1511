//written by ZephyrZhou(z5212919@unsw.edu.au)
//written 07-03-2019
//lab03 exerciese order3_challenge1
#include <stdio.h>
int main()
{
	int a,b,c;
	int max,mid,min;
	int sum_of_a_b_condition_big,sum_of_a_b_condition_small;
	int sum_of_ab_c_condition_big,sum_of_ab_c_condition_small;
	int bigger_ab,smaller_ab;
	printf("Enter integer: ");
	scanf("%d", &a);
    printf("Enter integer: ");
	scanf("%d", &b);
	printf("Enter integer: ");
	scanf("%d", &c);
	//max
	bigger_ab = (a >= b)* a + (a <= b)* b;
	sum_of_a_b_condition_big = (a >= b) + (a <= b);
	bigger_ab = bigger_ab / sum_of_a_b_condition_big;
    max = (bigger_ab >= c)* bigger_ab + (bigger_ab <= c) * c;
    sum_of_ab_c_condition_big = (bigger_ab >= c) + (bigger_ab <= c);
    max = max / sum_of_ab_c_condition_big;
    //min
    smaller_ab = (a >= b)* b + (a <= b)* a;
	sum_of_a_b_condition_small = (a >= b) + (a <= b);
	smaller_ab = smaller_ab / sum_of_a_b_condition_small;
    min = (smaller_ab >= c)* c + (smaller_ab <= c) * smaller_ab;
    sum_of_ab_c_condition_small = (smaller_ab >= c) + (smaller_ab <= c);
    min = min / sum_of_ab_c_condition_small;
    //mid
    mid = a + b + c - min - max;
    printf("The integers in order are: %d %d %d\n",min,mid,max);
	return 0;
}	 
