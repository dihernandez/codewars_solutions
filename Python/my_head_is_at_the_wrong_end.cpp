#include <array>
#include <vector>
#include <string>

std::array<std::string, 3> fixTheMeerkat(std::array<std::string, 3> arr) {
  std::array<std::string,3> correct_order;
  std::vector<std::string> reversed; 

  for (int i = 2; i >= 0; --i) {
    reversed.push_back(arr[i]);
  }
  std::copy_n(reversed.begin(), 3, correct_order.begin());
  return correct_order;
}