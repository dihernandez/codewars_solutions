#include <string>
#include <vector>

std::vector<std::string> split_str(std::string str) {
  std::vector<std::string> split;
  
  size_t pos = 0;
  std::string token;
  std::string delimiter = " ";
  
  while ((pos = str.find(delimiter)) != std::string::npos) {
    token = str.substr(0, pos);
    str.erase(0, pos + delimiter.size());
    split.push_back(token);
  }
  split.push_back(str);
  
  return split;
} 

std::string pig_it(std::string str)
{
    std::string pig_latin = "";
    std::vector<std::string> string_vector = split_str(str);
    std::string pig_word;
    
    for(auto it = string_vector.begin(); it != string_vector.end(); ++it) {
      std::string word = *it;
      if(word.size() < 1) {
        pig_word = word;
      } else {
          pig_word = word.substr(1, word.size()) + word.substr(0,1) + "ay";
      }
      
      for(auto &c : word) {
        if(!std::isalpha(c)) {
          pig_word = c;
          break;
        }
      }
      
      if(it == string_vector.begin()) {
        pig_latin += pig_word;
      } else {
        pig_latin += " " + pig_word;
      }
    }
    
  return pig_latin;
}