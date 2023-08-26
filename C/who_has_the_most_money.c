#include <stddef.h>

#define NAMELIM     0x8

struct student {
    char name[NAMELIM+1];
    unsigned fives;
    unsigned tens;
    unsigned twenties;
};

const char *most_money(const struct student *v, size_t n)
{
  
  if (n == 1) {
    return v[0].name;
  }
  
  char *selected_student = v[0].name;
  int max_amount = 0;
  int repeats = 1;
  
  for (int i = 0; i < n; ++i) {
    int total = 0;
    total += v[i].fives * 5;
    total += v[i].tens * 10;
    total += v[i].twenties * 20;
    if (total > max_amount) {
      selected_student = v[i].name;
      max_amount = total;
    }
    else if (total == max_amount) {
      repeats++;
    }
    
  }
  if (repeats != n) {
    return selected_student;
  } else {
    return "all";
  }
}