//written by ZephyrZhou(z5212919@unsw.edu.au)
//written 10-03-2019
//This is for lab04 x
#include<stdio.h>
int main() {
 int size, line = 1, column = 1,i = 1;
 int j;
 printf("Enter size: ");
 scanf("%d",&size);
 j =size;
 while(line <= size){
  while(column <= size) {
   if(column == i || column == j) {
    printf("*");
   } else {
    printf("-");
    
  }
  column++;
  } 
  line++;
  column = 1;
  i++;
  j--;
  printf("\n");
 }
return 0;
}
