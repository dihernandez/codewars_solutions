#include <stddef.h>
#include <stdbool.h>

enum result {EVENS_WIN, ODDS_WIN, TIE};

enum result bits_battle (size_t length, const int numbers[length])
{
  int even_contrib[length];
  int odd_contrib[length];
  for(int i = 0; i < length; ++i) {
    even_contrib[i] = 0;
    odd_contrib[i] = 0;
  }
  
  for (int i = 0; i < length; ++i) {
    int contrib = 0;
    int number = numbers[i];
    int num_copy = number;
    
    int binary_num[32];
    for (int c = 0; c < 32; ++c) {
      binary_num[c] = 0;
    }
    
    int bc = 0;
    if (number < 0) {
      num_copy *= -1;
    }
    while (num_copy > 0) {
      binary_num[bc] = num_copy % 2;
      num_copy /= 2;
      ++bc;
    }
    
    for (int c = 0; c < 32; ++c) {
      contrib += binary_num[c];
    }
    
    if (number < 0) {
        contrib *= -1;
    }    
    
    if (number % 2 == 0) {  
      even_contrib[i] = contrib;
    }
    else {
      odd_contrib[i] = contrib;
    }
  }
  
  int odd_total = 0;
  int even_total = 0;
  
  for (int i = 0; i < length; ++i) {
    odd_total += odd_contrib[i];
    even_total += even_contrib[i];
  }
  
  if (odd_total > even_total) {
    return ODDS_WIN;
  } else if (even_total > odd_total) {
    return EVENS_WIN;
  } else {
    return TIE;
  }
}