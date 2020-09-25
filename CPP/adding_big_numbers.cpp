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

	//cout << "In getOverlap A is " << a << " B is " << b << endl;

	for(int i = min(a.length(), b.length()) - 1; i >= 0; i--) {
	  	//cout << "i is " << i << " a is " << a.at(i) << " b is  " << b.at(i) << endl;
	  	sum = (int)a.at(i) - 48 + (int)b.at(i) - 48; // convert to ascii int value
	  	//string prev_sum;
	  	//working_sum >> prev_sum;

	  	//cout << "sum is " << sum << endl;

	  	working_sum << sum;

	  	//total_so_far += sum.str();
	  //	cout << "working_sum in getOverlap is " << working_sum.str() << endl;
	}
	return working_sum;
}

string add(const string& a, const string& b) {

	//cout << "A is: " << a << " B is: " << b << endl;

  	stringstream working_sum;


  	string total = "";
  	string total_so_far = "";
  	int sum = 0;


    if(a.length() == 0) {
		return  b;
	} else if(b.length() == 0) {
		return a;
	}

	if(a.length() == b.length()) {

		cout << "here 0 " << endl;
		bool apply_zero = false;

		//working_sum = getOverlap(a, b);
		for (int i = a.length() - 1; i >= 0; i--){
			//if(last_digit > 10){

							cout << "here 1" << endl;
		sum = (int)a.at(i) - 48 + (int)b.at(i) - 48;
		cout << "here 2" << endl;
			if(sum >= 10){
				apply_zero = true;

				//sum = (int)a.at(i) - 48 + 1; // convert to ascii int value
			//	cout <<" sum is " << sum << endl;
				//last_digit = sum;
			//	cout << "last digit for A > B is " << last_digit << endl;
				working_sum << 1;

			} else {
				working_sum << sum;
			}
		//	cout << "working sum is " << working_sum.str() << endl;
		}
		if(apply_zero) {
		//	working_sum << 0;
			apply_zero = false;
			std::stringstream temp;
			temp << 0;
			temp << working_sum.rdbuf();
			working_sum = std::move(temp); // or ss.swap(temp);
		}
		
		cout << "when equal, workng sum is" << working_sum.str() << endl; 

	}
	else if (a.length() > b.length()) {
		string reversed_a = a.substr(b.length() + 1);

		//reverse(reversed_a.begin(), reversed_end());
		//cout << "passed in a is " << reversed_a << endl;
		string overlap = getOverlap(reversed_a, b).str();
		//reverse(overlap.begin(), overlap.end());
		working_sum << overlap;

		int last_digit = (int)a.at(b.length() - 1) - 48 + (int)b.at(b.length() - 1) - 48;
		if(last_digit > 10) {
			int last_digit_location = overlap.length();
			overlap.replace(last_digit_location, 1, "0");
		}

		for (int i = a.length() - b.length() - 1; i >= 0; i--){
			//if(last_digit > 10){
			
			if(last_digit >= 10){
				sum = (int)a.at(i) - 48 + 1; // convert to ascii int value
			//	cout <<" sum is " << sum << endl;
				last_digit = sum;
			//	cout << "last digit for A > B is " << last_digit << endl;
				working_sum << sum;
				working_sum << 1;
			} else {
				working_sum << a.at(i);
			}
		//	cout << "working sum is " << working_sum.str() << endl;
		}

 	} else if(b.length() > a.length()) {
		string reversed_b = b.substr(a.length() + 1);

		//reverse(reversed_a.begin(), reversed_end());
		//cout << "passed in a is " << reversed_b << endl;
		string overlap = getOverlap(a, reversed_b).str();
		//reverse(overlap.begin(), overlap.end());
		working_sum << overlap;

		//cout << "overlap is " << working_sum.str() << endl;

		int last_digit = (int)b.at(a.length() - 1) - 48 + (int)a.at(a.length() - 1) - 48;
		if(last_digit >= 10) {
			int last_digit_location = overlap.length();
			overlap.replace(last_digit_location, 1, "0");
		}

		for (int i = b.length() - a.length() - 1; i >= 0; i--){
			//if(last_digit > 10){
			
			if(last_digit >= 10){
				sum = (int)b.at(i) - 48 + 1; // convert to ascii int value
			//	cout <<" sum is " << sum << endl;
				last_digit = sum;
				//cout << "last digit is for B > A" << last_digit << endl;
				working_sum << sum;
				working_sum << 1;
			} else {
				working_sum << b.at(i);
			}
			//cout << "working sum is " << working_sum.str() << endl;
		}
 	}

  total = working_sum.str();
  reverse(total.begin(), total.end()); 

  return total;
}

int main(int argc, char const *argv[])
{
	//auto result1 = add("9999", "1111"); //35689
	//auto result2 = add("1111", "9999"); //35689
	string a = "158999009324585664465070610004588531091497358748198957388692316791834288558396";
	string b = "1788378871862488679099277847";
			// "158999009324585664465070610004588531091497358748200745767564179280513387836243"
			// "15899900932458566446507061000458853109149735874819521616180198612215197316131117118171112141112151"
	auto result3 = add(a, b);
	auto result4 = add(b, a);

	//cout << result1 << " " << result2 << endl;
	//auto result2 = add("983", "456");
	cout << " a len " << a.length() << " b len " << b.length() << " result 3 " << result3 << " result 4 " << result4 << endl;
	return 0;
}