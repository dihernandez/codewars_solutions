#include <string>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

const int UPPER_CASE_OFFSET = 65;
const int NUMBER_LETTERS = 26;
const int LOWER_CASE_OFFSET = 97;

string rot13(string msg)
{
  char ciphered[msg.length()];
  char char_array[msg.length()];
  
  strcpy(char_array, msg.c_str()); 

  
  for(unsigned int i = 0; i < msg.length(); i++) {

    if((char_array[i] >= LOWER_CASE_OFFSET) && (char_array[i] < LOWER_CASE_OFFSET + NUMBER_LETTERS)) {
      char next =  (char)((char_array[i] - LOWER_CASE_OFFSET+ 13)%26 + LOWER_CASE_OFFSET);
      ciphered[i] = next;
    } else if((char_array[i] >= UPPER_CASE_OFFSET) && (char_array[i] < UPPER_CASE_OFFSET + NUMBER_LETTERS)) {
        char next =  (char)((char_array[i] - UPPER_CASE_OFFSET+ 13)%26 + UPPER_CASE_OFFSET);
        ciphered[i] = next;
    } else {
      ciphered[i] = msg[i];
    }

  }
   
  string str = ""; 
  for (unsigned int i = 0; i < msg.length(); i++) { 
      str = str + ciphered[i]; 
  } 

  return str;
} 
  
  