#include <stdint.h>

uint32_t breaking_chocolate(uint32_t n, uint32_t m) {
  if (n*m == 0) {
    return 0;
  } else {
    return m*n - 1;
  }
}