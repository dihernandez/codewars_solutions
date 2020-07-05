using namespace std;
string cleanString(const string &s) {
    vector<char> stack;
    string output = "";
    
    for(auto c : s) {
      if(c == '#') {
        if(stack.size() != 0) {
          stack.pop_back();
        } else {
          //pass
        }
      } else {
        stack.push_back(c);
      }
    }
  
    for(auto c : stack) {
      output += c;
    }
    
    return output;
}