#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Map Map;

struct Map {
    char key;
    int value;
};

struct Map word_occurences(const char *str_in, char letter) {
  struct Map word_occurences_map;
  int occurences = 0;

    for (int i = 0; i < strlen(str_in); ++i) {
      if (str_in[i] == letter) {
        occurences++;
      }
    }
  
    word_occurences_map.key = letter;
    word_occurences_map.value = occurences;

  return word_occurences_map;
}

bool permute_a_palindrome(const char *str_in) {
  int str_len = strlen(str_in);
  if (str_len <= 1) {
    return true;
  }
  
  struct Map word_occurences_var[str_len];
  for(int i = 0; i < str_len; ++i) {
    word_occurences_var[i].key = 0;
    word_occurences_var[i].value = 0;
  }
  
  for (int i = 0; i < str_len; ++i) {
    if(!memchr(word_occurences_var, str_in[i], sizeof(word_occurences_var))) {
      word_occurences_var[i] = word_occurences(str_in, str_in[i]);
    }
  }
  
  int nonzero_occurences = 0;
  for (int i = 0; i < str_len; ++i) {
    if (word_occurences_var[i].value % 2 != 0) {
      nonzero_occurences++;
    }  
  }
  if (nonzero_occurences > 1) {
    return false;
  } else {
    return true;
  }
}