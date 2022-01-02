#include <stdbool.h>
#include <math.h>
#include <stdio.h>

int square_num(int num) {
  return num*num;
}

bool is_prime(int num)
{
  if(num <= 1) {
    return false;
  } else if(num == 2) {
    return true;
  }
  int max_root = 0;
  int num_roots = 1; // start at 1 to include self
  while (square_num(max_root) <= num){
    max_root++;
    if (num % max_root == 0) {
      num_roots++;
    }  
  }
  if(num_roots <= 2){
  }
  return (num_roots <= 2) ? true : false;
}
