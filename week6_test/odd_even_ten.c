// Week 6 test: odd_even_ten
// Written by Zephyr Zhou(z5212919)
// 30-03-2019

#include <stdio.h>
#define SIZE     10

int main(void) {

    int i = 0;
    int i_odd = 0;
    int i_even = 0;
    int number[SIZE];
    int odd[SIZE];
    int even[SIZE];
    
    while (i < SIZE) {
        scanf("%d", &number[i]);
        
        if(number[i] % 2 == 0) {
            even[i_even] = number[i];
            i_even++;
        } else {
            odd[i_odd] = number[i];
            i_odd++;
        }        
        
        i++;
    }
    
    int j_odd = 0;
    int j_even = 0;
    printf("Odd numbers were: ");
    while(j_odd < i_odd) {
        printf("%d ", odd[j_odd]);    
        j_odd++;
    }
    printf("\nEven numbers were: ");
    while(j_even < i_even) {  
        printf("%d ", even[j_even]);    
        j_even++;
    }
    printf("\n");    
    

    return 0;
}


