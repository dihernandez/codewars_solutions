#include <string>
#include <vector>

class LongestConsec
{
public:
    static std::string longestConsec(std::vector<std::string> &strarr, int k);
};
    
std::string LongestConsec::longestConsec(std::vector<std::string> &strarr, int k){
  if( strarr.size() == 0 || k > strarr.size() || k <=0) {
    return "";
  }
  
  std::string longest_string = "";
  
  for (int i = 0; i < strarr.size() - k; i++) {

    std::string next_string = "";
    for (int j = i; j < k + i; j++) {
      next_string += strarr.at(j);
    }
    if (next_string.length() > longest_string.length()) {
      longest_string = next_string;
    }
  }
  for (int i = strarr.size() - k; i < strarr.size(); i++) {
    std::string next_string = "";
    for (int j = i; j < strarr.size(); j++) {
      next_string += strarr.at(j);
    }
    if(next_string.length() > longest_string.length()) {
      longest_string = next_string;
    }
  } 
  return longest_string;
}