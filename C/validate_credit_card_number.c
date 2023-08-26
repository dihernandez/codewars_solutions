#include <stdbool.h>
#include <stdio.h>

bool validate(long digits) {

  long digits_copy = digits;
  int num_digits = 0;
  
  do {
    digits_copy /= 10;
    num_digits++;
  } while (digits_copy != 0);
  
  char digits_str[num_digits + 1];
  int digits_arr[num_digits];
  int mutated_digits_arr[num_digits];
  
  sprintf(digits_str, "%ld", digits);
    
  for (int i = 0; i < num_digits; ++i) {
    digits_arr[i] = (int) digits_str[i] - 48;
  }
  
  
  for (int i = 0; i < num_digits; ++i) {
    mutated_digits_arr[i] = digits_arr[i];
  }
  
  if (num_digits%2 == 0) {
    for (int i = 0; i < num_digits; i += 2) {
      int new_value = digits_arr[i] * 2;
      if (new_value > 9) {
        new_value -= 9;
      }
      mutated_digits_arr[i] = new_value;
    }
  }
  else if (num_digits%2 == 1) {
    for (int i = 1; i < num_digits; i += 2) {
      int new_value = digits_arr[i] * 2;
      if (new_value > 9) {
        new_value -= 9;
      }
      mutated_digits_arr[i] = new_value;
    }
  }

  int total = 0;
  for (int i = 0; i < num_digits; ++i) {
    total += mutated_digits_arr[i];
  }
  
  return total%10 == 0;
}