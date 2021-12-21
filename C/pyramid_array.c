#include <stdlib.h>

int **pyramid (unsigned n)
{
  int total_num_ints = 0;
  for (int i = 1; i <= n; ++i) {
    total_num_ints += i;
  }
  const unsigned **pyramid = malloc(sizeof(unsigned*)*n); // n arrays
  for (int i = 0; i < n; ++i) {
    pyramid[i] = malloc(sizeof(unsigned)*n);
  }

  for (int arr = 1; arr <= n; ++arr) {
    int *sub_arr = pyramid[arr - 1];
    for (int count = 1; count <= arr; ++count) {
      sub_arr[count - 1] = 1; 
    }
  } 

	return pyramid;
}

void free_pyramid (unsigned n, int* pyramid_array[n])
{
  for (int i = 0; i < n; ++i) {
    free(pyramid_array[i]);
  } 
  free(pyramid_array);
}
