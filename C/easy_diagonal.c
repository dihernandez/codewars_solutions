#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef unsigned long long ull;
ull diagonal(int n, int p)
{
    ull *triangle[n + 1];
    ull coef = 1;
    
    for (int col = 0; col < n + 1; ++col) {
      for (int row = 0; row < n + 1; ++row) {
        triangle[col] = calloc(n + 1, sizeof(ull) * row);
      }
    }

    for (int row = 0; row <= n; ++row) {
        for (int col = 0; col <= row; ++col) {
          if(row == 0 || col == 0) {
            coef = 1;
          } else {
            coef = coef * (row - col + 1)/col;
          }
          triangle[row][col] = coef;
      }
      
    }
  
  ull total = 0;
  int sel_col = p;
  ull to_sum[n - sel_col];

  for (int row = 0; row < n + 1; ++row) {
    if (triangle[row][sel_col] == 0) {
      // do nothing
    } else {
      to_sum[row - sel_col] = triangle[row][sel_col];
    }
  }
  
  for (int i = 0; i <= n - sel_col; ++i) {
    total += to_sum[i];
  }
  
  return total;
}