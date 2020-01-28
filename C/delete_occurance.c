#include <stddef.h>

struct NumCount {
  int number;
  int count;
};

int* delete_nth(size_t szin, int order[szin], int max_e, size_t *szout) {
  struct NumCount counted[szin];
  int digits_seen[szin]; // maximum of zsim distinct digits
  for(int i = 0; i < szin; i++) {
    for(int c = 0; c < szin; c++){
        if(counted[i].number == digits_seen[c]) {
            digits_seen[i] = order[i];
            counted[i].count += 1;
        } else {
            counted[i].number = 1;
            counted[i].count = 1;
        }
      }
    } 
    for(int i = 0; i < szin; i++) {
    printf("zsin is %d \n", order[i]);
    printf("digits seen is %d \n", digits_seen[i]);
    printf("counted numbers are %d \n", counted[i].number);
    printf("counted counts are %d \n", counted[i].count);
    }
}
