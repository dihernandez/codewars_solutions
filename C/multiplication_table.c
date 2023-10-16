#include <stdlib.h>
#include <stdio.h>

int **multiplication_table(int n) {
  
  int **arr;
  arr = (int **) malloc(n * sizeof( * arr));
  
  for (int i = 0; i < n; ++i) {
    arr[i] = (int * ) malloc(n * sizeof(int));
  }
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      arr[i][j] = (i + 1) *(j + 1);
    }
  }  
  return arr;
}