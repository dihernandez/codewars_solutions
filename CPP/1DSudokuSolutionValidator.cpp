#include <iostream>
#include <list>
#include <vector>
using namespace std;

const unsigned int NUM_ROWS = 9;
const unsigned int NUM_COLS = 9;
const unsigned int NUM_SQUARES = 9;



bool validateSubsection(vector<unsigned int> subsection) {
  list<unsigned int> expected = {1,2,3,4,5,6,7,8,9};

  for(auto s : subsection) {
    cout << "in here " << s << endl;
    expected.remove(s);
  }

  return expected.size() == 0;
}

bool validateRows(unsigned int board[]) {
  bool is_valid = true;

  for(int i = 0; i < NUM_ROWS * NUM_COLS; i += 9) {
    vector<unsigned int> subsection = {};
    for (int j = 0; j < NUM_ROWS; j++) {
      subsection.push_back(board[j+i]);
    }
    if(board[i] == 0) {
      return false;
    } else {
      if(!validateSubsection(subsection)){
        cout << "in validateSubsection " << subsection.size() <<endl;
        return false;
      }
    }

  }

  return is_valid;
}

bool validateCols(unsigned int board[]) {
  bool is_valid = true;
  vector<vector<unsigned int>> columns = {};

  for(int i = 0; i < NUM_COLS; i++) {
    vector<unsigned int> subsection = {};
    columns.push_back(subsection);
  }
  for(int i = 0; i < NUM_ROWS * NUM_COLS; i++) {


    for(int j = 0; j < NUM_COLS; j++) {
       //if(i%j == 0) {
         //subsection.push_back(board[j*9 + i]);
      //}
      vector<unsigned int> intermediate = columns.at(i%9);
      //cout << board[j*9 + i%9] << endl;
      intermediate.push_back(board[j*9 + i%9]);
      columns.at(i%9) = intermediate;
      //colums.push_back(board[j*9]);

    }
    // if(i%9 == 0) {
    //   for(int j = 0; j < NUM_COLS; j++) {
    //     subsection.push_back(board[j*9]);
    //     cout << board[j*9] << endl;
    //   }
    // }


    if(board[i] == 0) {
      return false;
    } //else {
    //   if(!validateSubsection(subsection)){
    //     cout << "in validateSubsection " << subsection.size() << endl;
    //     return false;
    //   }
    // }
  }
    for(auto c : columns){
        if(!validateSubsection(c)){
        cout << "in validateSubsection " << c.size() << endl;
        return false;

    }
   }

  return is_valid;
}

bool validateSquares(unsigned int board[]) {
  bool is_valid;
  vector<vector<unsigned int>> squares = {};

  for(int i = 0; i < NUM_SQUARES; i++) { 
    vector<unsigned int> subsection = {};
    squares.push_back(subsection);
  }

  for(int i = 0; i < NUM_ROWS * NUM_COLS; i++) {
      for (int j = 0; j < NUM_SQUARES; j++){
      vector<unsigned int> intermediate = squares.at(j);
        for(int c = 0; c < 3; c++) {
        //cout << board[j*9 + i%9] << endl;
          intermediate.push_back(board[i%3 + c]);
        }
      squares.at(j) = intermediate;
    }
  }

  for(auto s : squares){
    if(!validateSubsection(s)){
    cout << "in validateSubsection " << s.size() << endl;
    return false;

    }
  }
  return is_valid;

}


bool validSolution(unsigned int board[9][9]){
  /* Write your solution here */
  unsigned int *pointer = &board[0][0];

  //list<list<unsigned int>> cols;//extractCols(board);
  //list<unsigned int> squares = extractSquares(pointer);
  bool is_valid = true;

  // if(!validateRows(pointer)){ //!validateCols(pointer)) {
  //   is_valid = false;
  // }
  // if(!validateCols(pointer)) {
  //   is_valid = false;
  // }
  if(!validateSquares(pointer)) {
    is_valid = false;

  }
//  for(auto c: cols) {
//    if(!sectionIsValid(c)) {
//      is_valid = false;
//    }
//  }
 // for(auto r: rows) {
 //     if(!sectionIsValid(r)) {
 //      is_valid = false;
 //     } 
 //      for(auto i : r) {
 //      cout << i << endl;
 //     }
 //  }

// for(auto s: squares) {
//    if(!sectionIsValid(s)) {
//      is_valid = false;
//    }
//  }
  cout << "is valid is " << is_valid << endl;
  return is_valid;
}

int main() {
  cout << "in main" << endl;
  unsigned int board[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2}, 
                             {6, 7, 2, 1, 9, 5, 3, 4, 8},
                             {1, 9, 8, 3, 4, 2, 5, 6, 7},
                             {8, 5, 9, 7, 6, 1, 4, 2, 3},
                             {4, 2, 6, 8, 5, 3, 7, 9, 1},
                             {7, 1, 3, 9, 2, 4, 8, 5, 6},
                             {9, 6, 1, 5, 3, 7, 2, 8, 4},
                             {2, 8, 7, 4, 1, 9, 6, 3, 5},
                             {3, 4, 5, 2, 8, 6, 1, 7, 9}};
  cout << validSolution(board) << endl;
  return 0;

}