#include <string>
#include <vector>

string encrypt(string text, int rule) {
  std::string encrypted = "";
  std::vector<char> characters (text.begin(), text.end());
  for (auto it = text.begin(); it != text.end(); it++) {
    encrypted += *it + rule;
  }
  return encrypted;
};