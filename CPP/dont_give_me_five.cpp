#include <string>

int dontGiveMeFive(int start, int end)
{  
  int count = 0;
  
  for (int i = start; i <= end; i++) {
    std::string number = std::to_string(i);
    if (number.find(std::to_string(5)) != std::string::npos) {
      count++;
    }
  }

  return (end - start + 1) - count;
}


