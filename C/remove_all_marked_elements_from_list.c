//  do not allocate memory
//  assign into *remaining
//  set *rem to array size
//  return remaining array

#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

int *remover(size_t ints, const int integers[ints],
             size_t vals, const int values[vals],
             size_t *rem, int *remaining) {

  size_t num_rem = 0;

  printf("rem is %lu, remaining is %d\n", *rem, *remaining);

    for (size_t i = 0; i < ints; ++i) {
      bool matches = false;
      for (size_t j = 0; j < vals; ++j) {
        
        if (values[j] == integers[i]) {
          matches = true;
          printf("match is %d\n", integers[j]);
        }
      }
      if (!matches) {
        ++num_rem;
        printf("not matching, num_rem is %lu, integers[i] is %d\n", num_rem, integers[i]);
        remaining[num_rem - 1] = integers[i];
      }
    }  
    *rem = num_rem;
    printf("remainder is %zu\n", *rem);

    for (size_t i = 0; i < num_rem; ++i) {
        printf("remaining is %d\n", remaining[i]);
    }

    return remaining;
}