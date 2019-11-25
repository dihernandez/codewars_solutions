#include <stdio.h>
#include <stdlib.h>

int mxdiflg(
  const char **firstArray, size_t firstArrayLength, 
  const char **secondArray, size_t secondArrayLength) {
  

  if(firstArrayLength == 0 | secondArrayLength == 0) {
    return -1;
  }
  
  size_t shortest_first = strlen(firstArray[0]);
  size_t shortest_second = strlen(secondArray[0]);
  size_t longest_first = strlen(firstArray[0]);
  size_t longest_second = strlen(secondArray[0]);


  for (int i = 0; i < firstArrayLength; i++) {
    if(strlen(firstArray[i]) < shortest_first) {
      shortest_first = strlen(firstArray[i]);
    } 
    if(strlen(firstArray[i]) > longest_first) {
      longest_first = strlen(firstArray[i]);
    }
  }
  
  for (int i = 0; i < secondArrayLength; i++) {
    if(strlen(secondArray[i]) < shortest_second) {
      shortest_second = strlen(secondArray[i]);
    } 
    if(strlen(secondArray[i]) > longest_second) {
      longest_second = strlen(secondArray[i]);
    }
  }
  
  if(abs(longest_first - shortest_second) > abs(longest_second - shortest_first)) {
    return abs(longest_first - shortest_second);
  } else {
    return abs(longest_second - shortest_first);
  }
  

} 
