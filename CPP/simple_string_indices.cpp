#include <stack>
#include <string>

int solve(std::string str, int index){
  if (str[index] != '(') {
    return -1;
  }

  std::string to_search = str.substr(index, str.length());
  std::stack<char> parenthesis;
  parenthesis.push(str[index]);
  int n_th_index = 1;
  
  while (!parenthesis.empty()) {
    if (to_search[n_th_index] == '(') {
      parenthesis.push('(');
    } else if (to_search[n_th_index] == ')') {
      parenthesis.pop();
    }
    n_th_index++;
  }
  return n_th_index + index - 1;
}