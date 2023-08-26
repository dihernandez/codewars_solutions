#include <stdlib.h>
#include <stdbool.h>

int find_outlier(const int *values, size_t count) {
  bool norm_is_even = false;
  int num_even_values = 0;
  
  for (int i = 0; i < count; ++i) {
    if (values[i] % 2 == 0) {
      num_even_values++;
    }
  }
  norm_is_even = num_even_values >= 2;
  
  for (int i = 0; i < count; ++i) {
    if (norm_is_even) {
      if (values[i] % 2 != 0) {
        return values[i];
      }
    } else {
      if (values[i] % 2 == 0) {
        return values[i];
      }
    }
  }
  
}