#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int nbDig(int n, int d) {
  int all_digits[n];
  char str_digit[n];
  int num_d = 0;
  
  printf("n is %d, d is %d \n", n, d);
  
  for(int i = 0; i <= n; i++) {
    all_digits[i] = pow(i, 2);
  }
  
  for(int i = 0; i <= n; i++) {
    sprintf(str_digit, "%d", all_digits[i]);
    
    for(int j = 0; j <= strlen(str_digit); j++) {
      if(str_digit[j] == (d + '0')) {
        num_d++;
      }
    }
  }
