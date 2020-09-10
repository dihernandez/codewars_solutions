#include <algorithm>
#include <cstring>
#include <string>
#include <sstream> 
#include <vector>
#include <iostream>
#include "stdlib.h"
#include <typeinfo>

using namespace std;


stringstream getOverlap(const string& a, const string& b) {


	stringstream working_sum;
	int sum;

	for(int i = min(a.length(), b.length()) - 1; i >= 0; i--) {
	  	cout << "i is " << i << " a is " << a.at(i) << " b is  " << b.at(i) << endl;
	  	sum = (int)a.at(i) - 48 + (int)b.at(i) - 48; // convert to ascii int value
	  	//string prev_sum;
	  	//working_sum >> prev_sum;

	  	//cout << "sum is " << sum << endl;

	  	working_sum << sum;

	  	//total_so_far += sum.str();
	  	//cout << "working_sum is " << working_sum.str() << endl;
	}
	return working_sum;
}

string add(const string& a, const string& b) {


  stringstream working_sum;


  string total = "";
  string total_so_far = "";
  int sum = 0;


    	

	if(a.length() == b.length()) {

		working_sum = getOverlap(a, b);
	}
	else if (a.length() > b.length()) {
		string overlap = getOverlap(a, b).str();
		reverse(overlap.begin(), overlap.end());

		int last_digit = (int)a.at(b.length() - 1) - 48 + (int)b.at(b.length() - 1) - 48;
		if(last_digit > 10) {
			int last_digit_location = overlap.length();
			overlap.replace(last_digit_location, 1, "0");
		}

		for (int i = a.length() - b.length() - 1; i >= 0; i--){
			//if(last_digit > 10){
			
			if(last_digit >= 10){
				sum = (int)a.at(i) - 48 + 1; // convert to ascii int value
				cout <<" sum is " << sum << endl;
				last_digit = sum;
				cout << "last digit is " << last_digit << endl;
				working_sum << sum;
				working_sum << 1;
			} else {
				working_sum << a.at(i);
			}
			cout << "working sum is " << working_sum.str() << endl;
		}

 	} 

  total = working_sum.str();
  reverse(total.begin(), total.end()); 

  return total;
}

int main(int argc, char const *argv[])
{
	auto result1 = add("99", "2");
	cout << result1 << endl;
	//auto result2 = add("983", "456");
	//cout << result2 << endl;
	return 0;
}