#include <inttypes.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

void insertion_sort(char *digits, int num_digits) {
  for (int i = 1; i < num_digits; i++) {
    char current_val = digits[i];
    int prev_index = i - 1;
    
    while(prev_index >= 0 && digits[prev_index] < current_val) {
      digits[prev_index + 1] = digits[prev_index];
      prev_index--;
    }
    digits[prev_index + 1] = current_val;
  }
}

uint64_t digits_to_int(char *digits, int num_digits) {
  uint64_t number = 0;
   for(int i = 0; i < num_digits; i++) {
     uint64_t digit = digits[i] - '0';
     number *= 10;
     number += digit;
   }
  return number;
}

uint64_t descendingOrder(uint64_t n)
{
  if(n ==0){
    return 0;
  } else{
    char digits[1024];
    sprintf(digits, "%lu", n);
    int num_digits = strlen(digits);
    insertion_sort(digits, num_digits);
    return digits_to_int(digits, num_digits);
  }
}