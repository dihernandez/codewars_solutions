#include <math.h>

long long findNb(long long m)
{
  long long n = 0;
  long long counter = 0;
  while(counter < m) {
    n++;
    counter += pow(n, 3);
  }
  if(counter - m != 0){
    return -1;
  }
  return n;
}