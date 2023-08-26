#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

char *fromNb2Str (int n, int moduli[/*length*/], int length)
{
  // first check if moduli are valid
  bool is_not_pairwise_coprime = false;
  bool is_greater_than_n = false;
  
  int product = 1;
  
  // check if n is not greater than product
  for (int i = 0; i < length; ++i) {
    
    printf("length is %d, moduli are %d\n", length, moduli[i]);
    product *= moduli[i]; 
  }
  is_greater_than_n = (product <= n);
  
  
      for ( int i = 1; i < length; i++ ) 
    { 
        for (int j = 0; j < i; j++ ) 
        { 
          int num1 = moduli[i];
          int num2 = moduli[j];
          int hcf = 1;
          
          for(int k=1;k<=num1;k++) {
            if(num1%k==0 && num2%k==0)
            {
              hcf = k;
            }
           }
                    
          if (hcf != 1) {
            is_not_pairwise_coprime = true;
          }
        } 
    } 
  
  if (is_not_pairwise_coprime || is_greater_than_n) {
    printf("is_not_pairwise_coprime %d, is_greater_than %d", is_not_pairwise_coprime, is_greater_than_n);
    return "Not applicable";
  }
  
  int mod_nums[length];
  
  for (int i = 0; i < length; ++i) {
    mod_nums[i] = n % moduli[i];
    printf("mod is %d\n", mod_nums[i]);
  }
  int res_len = 4*(length) + 1;
  char *result = malloc(res_len* sizeof(char));

  for (int i = 0; i < length; ++i) {
    char to_append[4];
    int str_len = strlen(result);
    if (str_len < res_len - 3) {
      if (i == 0) {
      

        sprintf(to_append,"-%d", mod_nums[i]);
      } 
      else {
        sprintf(to_append, "--%d", mod_nums[i]);
      }
      strcat(result, to_append);

      if (i == length - 1) {
        strcat(result, "-\0");

      }
    }
  }

  printf("strlen is %lu, res_len is %d\n", strlen(result), res_len);
  printf("result is %s\n", result);
  return result;
}