#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int calc_num_bits(unsigned value) {
  return log2(value) + 1;
}

int* dec_to_bin(unsigned value) {
  int binary[calc_num_bits(value)];
  int idx = 0;
  while(value > 0) {
    binary[idx] = value % 2;
    value = value/2;
    idx++;
  }
  return binary;
}

size_t countBits(unsigned value){
  if (value <= 0) {
    return 0;
  }
  int num_ones = 0;
  int num_bits = calc_num_bits(value);

  const int* binary_rep = dec_to_bin(value);
  for (int i = 0; i < num_bits; i++) {
    if (binary_rep[i] == 1) {
      num_ones++;
    }
  }
  return num_ones;
}
