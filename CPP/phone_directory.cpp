#include <string>
#include <iostream>
#include <stack>
#include <ctype.h>
#include <vector>
#include <map>
#include <cstring>

class PhoneDir
{
public:
    static std::string phone(const std::string& orgdr, std::string num);
private:
    static std::vector<std::string> split_string(const std::string& orgdr);
    static std::string clean_string(const std::string& selected_string);
    static std::string get_number(std::string& selected_str, std::string& num);
    static std::string get_name(std::string& selected_str);
    static std::string get_addr(std::string& selected_str, std::string& number, std::string& name);
};

std::vector<std::string> PhoneDir::split_string(const std::string& orgdr) {
  std::string str_mutable = std::string(orgdr);
  std::vector<std::string> entries;
  std::string token = "";
  std::string delimiter = "\n";
  size_t pos;
  
  while ((pos = str_mutable.find(delimiter)) < str_mutable.size()) {    
    token = str_mutable.substr(0, pos);
    str_mutable.erase(0, pos + delimiter.length());
    entries.push_back(token);
  }
  
  return entries;
}

std::string PhoneDir::clean_string(const std::string& selected_str) {
  
  std::string cleaned_string = "";
  
  for(const char& c : selected_str) {
    if (std::isalpha(c) || std::isdigit(c) || std::isspace(c) || c == '-' || c == '.') {
      cleaned_string += c;
    }
  }
  
  // get rid of multiple spaces
  for(int i = 0; i < cleaned_string.size() - 1; ++i) {  
    if(cleaned_string.at(i) == ' ' && cleaned_string.at(i + 1) == ' ') {
      cleaned_string.erase(i, 1);
    }

  }
  
  return cleaned_string;
}

std::string PhoneDir::get_number(std::string& selected_str, std::string& num) {
  int start_index, end_index;
  start_index = selected_str.find(num);
  if(start_index == std::string::npos) {
    return "Error => Not found: nb";
  }
  
  end_index = start_index + 1;
    
  while(end_index < selected_str.size() && !isspace(selected_str.at(end_index))) {
    end_index++;
  } 
  
  std::string number = selected_str.substr(start_index, end_index - start_index);
  return number;
}


std::string PhoneDir::get_name(std::string& selected_str) {

  int start_index = 0, end_index = 0;
  
  for(int i = 0; i < selected_str.size() - 1; ++i) {        
    if(selected_str.at(i) == '<' && std::isalpha(selected_str.at(i + 1))) {
      start_index = i;
    } else if(selected_str.at(i + 1) == '>') {
      end_index = i;
    }
  }
  
  return selected_str.substr(start_index + 1, end_index - start_index);
}

std::string PhoneDir::get_addr(std::string& selected_str, std::string& number, std::string& name) {
  std::string addr = std::string(selected_str);
  int number_index = 0, name_index = 0; 
  
  number_index = addr.find(number);
  addr.erase(number_index, number.size());  
  name_index = addr.find(name);
  addr.erase(name_index, name.size());
  
  for(int i = 0; i < addr.size(); ++i) {
    if(addr.at(i) == '_') {
      addr[i] = ' ';
    }
  }
  
  std::string cleaned_string = clean_string(addr);
  return cleaned_string.substr(cleaned_string.find_first_not_of(' '), std::string::npos);
}

std::string PhoneDir::phone(const std::string& orgdr, std::string num){
  std::vector<std::string> entries;
  std::string result = "", addr = "", name = "", number = "";

  // split into entries
  int num_entries = 0;
  entries = split_string(orgdr);

  std::string selected_entry = "";
  for(int i = 0; i < entries.size(); ++i){
    if(entries.at(i).find(num) != std::string::npos) {
      selected_entry = entries.at(i);
      num_entries++;
    }
  }
  
  if(num_entries < 1) {
    return "Error => Not found: nb";
  } else if(num_entries > 1) {
    return "Error => Too many people: nb";
  }
  
  number = clean_string(get_number(selected_entry, num));
  name = get_name(selected_entry);
  addr = get_addr(selected_entry, number, name);
  
  result = "Phone => " + number + ", Name => " + name + ", Address => " + addr;
  return result;
}