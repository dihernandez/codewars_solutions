#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int cube_of_int(const int n) {
  return n*n*n;
}

bool is_reverse(char* s){
  int s_len = (int)(strlen(s));
  int ints[s_len];
  for (int i = 0; i < s_len; i++) {
    ints[i] = s[i] - '0';
  }
  int sum = 0;
  for (int i = 0; i < s_len; i++){
    sum += cube_of_int(ints[i]);
  }
  if (sum%2 == 0) {
    return true;
  }
  return false;
}

char* shift_left_one(char *s) {
  int str_len = strlen(s);
  char *tmp = strdup(s);
  int shift = str_len + (-1 % str_len);
  for (int i = 0; s[i] != 0; i++) {
    int new_idx = (i + shift) % str_len;
    tmp[new_idx] = s[i];
  }
  memcpy(s, tmp, str_len);
  free(tmp);
  return s;
}

void join_strings(char *output, const char **chunks, int num_chunks) {
  int str_length = 0;
  for (int i = 0; i < num_chunks; i++) {
    str_length += strlen(chunks[i]);
  }
  for (int i = 0; i < num_chunks; i++) {
    strcat(output, chunks[i]);
  }
}

void split_str(char *str_in, char **chunks, const int step_size) {
  int str_size = strlen(str_in);
  int num_chunks = str_size/step_size;
  
  char *p = str_in;
  for (int i = 0; i < num_chunks; i++) {
    char *chunk = chunks[i];
    
    for (int j = 0; j < step_size; j++) {
      chunk[j] = *p++;
    }
    chunk[step_size] = '\0';
  }
}

char* revrot(char* s, int sz) {
  int s_len = (int)(strlen(s)); 
  if(sz <= 0 || strlen(s) == 0 || s_len < sz){
    return "";
  }
  int num_chunks = s_len/sz;
  const char **chunks = malloc(sizeof(const char*) * num_chunks);
  
  for (int i = 0; i < num_chunks; i++) {
    chunks[i] = malloc(sz + 1);
  }
  
  split_str(s, chunks, sz);
  
  int solution_size = 0;
  for (int i = 0; i < num_chunks; i++) {
    solution_size += strlen(chunks[i]);
  }
  char *solution = (char*)malloc(s_len + 1);
  solution[0] = '\0';
  for(int i = 0; i < num_chunks; i++) {
    if(is_reverse(chunks[i])) {
      char *reversed;
      reversed = strrev(chunks[i]);
      strcpy(chunks[i], reversed);
    } else {
      char *shifted;
      shifted = shift_left_one(chunks[i]);
      strcpy(chunks[i], shifted);
    }
  }
  join_strings(solution, chunks, num_chunks);
  return solution;
}