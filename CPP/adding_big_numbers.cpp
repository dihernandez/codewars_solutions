#include <algorithm>
#include <cstring>
#include <string>
#include <sstream> 
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <typeinfo>

using namespace std;

void getSubproblems(const string& inputStr, vector<string> &subproblems) {
    for(int i = 0; i <= inputStr.length() - 1; i++) { //assumes a and b are of same length
      if(i%2 == 0) {
        
          char aChar = inputStr[i];
          char bChar = inputStr[i + 1];
  //         cout << aChar << "is " << typeid(aChar).name() << endl;
  //         cout << bChar << "is " << typeid(aChar).name() << endl;
          auto couple = string(1,aChar)+bChar;
  
          subproblems.push_back(couple);
      }
  }
  
}

string add(const string& a, const string& b) {
//     vector<string> aSubproblems {};
//     vector<string> bSubproblems {};
  
//     getSubproblems(a, aSubproblems);
//     getSubproblems(b, bSubproblems);
  

// //   for(auto n : a) {
// //     cout << "a is " << n << endl;
// //     cout << "a plus is. " << typeid(n).name() << endl;
// //   }
//   cout << a.length() << endl;

//   for(auto c : aSubproblems) {
//     std::cout << "aSubproblem is " << c << std::endl;
    
//   }
//    for(auto c : bSubproblems) {
//     std::cout << "bSubproblem is " << c << std::endl;
    
//   }

  stringstream working_sum;


  string total = "";
  string total_so_far = "";
  int sum = 0;
  bool carry_term = false;
  bool carry_applied = true;

  //for (int i = 0; i < (min(aSubproblems.size(), bSubproblems.size()) -1); i++) {
    	//auto current_sum = atoi(aSubproblems[i].c_str()) + atoi(bSubproblems[i].c_str());

    	// if (current_sum > 100) {
    	// 	cout << "carry term" << current_sum << endl;
    	// 	carry_term = true;
    	// 	carry_applied = true;
    	// }


    	// if(carry_term && carry_applied) {
    	// 	carry_term = false; // reset
    	// 	carry_applied = false; // is no longer our turn to add
    	// 	current_sum += 1;
    	// 	cout << "current_sum is" << current_sum << endl;
    	// 	working_sum << current_sum;
    	// 	total += working_sum.str();
    	// 	cout << "total is " << total << endl;
    	// 	//total += current_sum;
    	// 	//cout << "in here" << total << endl;
    	// 	//cout << total.substr(total.length() - 1, total.length()) << endl;
    	// 	//total += total.substr(total.length() - 1, total.length()); //update total
  
    	// }
    
  //}

  for(int i = min(a.length(), b.length()) - 1; i >= 0; i--) {
  	cout << "i is " << i << " a is " << a.at(i) << " b is  " << b.at(i) << endl;
  	sum = (int)a.at(i) - 48 + (int)b.at(i) - 48; // convert to ascii int value
  	//string prev_sum;
  	//working_sum >> prev_sum;

  	cout << "sum is " << sum << endl;

  	working_sum << sum;

  	//total_so_far += sum.str();
  	cout << "working_sum is " << working_sum.str() << endl;

  }

  total = working_sum.str();
  reverse(total.begin(), total.end()); 

  return total;
}

int main(int argc, char const *argv[])
{
	auto result1 = add("123", "456");
	cout << result1 << endl;
	//auto result2 = add("983", "456");
	//cout << result2 << endl;
	return 0;
}