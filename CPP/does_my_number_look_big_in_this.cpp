#include <vector>
#include <string>
#include <cmath>

std::vector<int> separate_digits(int value) {
  std::string stringified = std::to_string(value);
  std::vector<char> characters(stringified.begin(), stringified.end());
  std::vector<int> ints;

  for (auto it = characters.begin(); it != characters.end(); ++it){
    int median = *it - '0';
    ints.push_back(median);
  }
  return ints;
} 

bool narcissistic( int value ){
  int narcissistic_value = 0;
  std::vector<int> digits = separate_digits(value);
  int power = digits.size();
  
  for (auto it = digits.begin(); it != digits.end(); it++){
    narcissistic_value += pow((float)*it, (float)power);
  }
  std::cout << narcissistic_value << std::endl;
  return narcissistic_value == value;
}


int main(int argc, char* argv[]) {

	std::cout << narcissistic(7) << std::endl;

	return 0;

}