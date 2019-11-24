#include <stdbool.h>
#include <math.h>

bool is_square(int n) {
    if(n == 0){
      return true;
    }
    for(int i = 1; i < n/2; i++) {
      if(i*i > n) {
        break;
      }
      if(i*i == n) {
        return true;
      }
    }
    return false;
}
