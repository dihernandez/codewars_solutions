#include <iostream>
#include <list>
#include <vector>
using namespace std;

const unsigned int NUM_ROWS = 9;
const unsigned int NUM_COLS = 9;
const unsigned int NUM_SQUARES = 9;



bool validateSubsection(vector<unsigned int> subsection) {
  list<unsigned int> expected = {1,2,3,4,5,6,7,8,9};
  bool is_valid = true;
  for(auto s : subsection) {
    cout << "in here " << s << endl;
    expected.remove(s);
  }

  is_valid = expected.size() == 0;
  if(!is_valid) {
    cout << "is invalid " << endl;
    for (auto s: subsection) {
      cout << "in invalid " << s << endl;
    }
  }
  return is_valid;
}

bool validateRows(unsigned int board[]) {
  bool is_valid = true;

  for(int i = 0; i < NUM_ROWS * NUM_COLS; i += 9) {
    vector<unsigned int> subsection = {};
    for (int j = 0; j < NUM_ROWS; j++) {
      subsection.push_back(board[j+i]);
    }
    if(board[i] == 0) {
      is_valid = false;
    } else {
      if(!validateSubsection(subsection)){
        cout << "in validateSubsection " << subsection.size() <<endl;
        is_valid = false;
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
  for(int i = 0; i < NUM_ROWS; i++) {


    for(int j = 0; j < NUM_COLS; j++) {

      vector<unsigned int> intermediate = columns.at(i%9);
      intermediate.push_back(board[j*9 + i%9]);
      columns.at(i%9) = intermediate;
      if(board[i + j] == 0) {
        is_valid = false;
      }
    }

  }
    for(auto c : columns){
        if(!validateSubsection(c)){
          is_valid = false;

    }
   }

  return is_valid;
}

  vector<vector<unsigned int>> extractRowThrees(unsigned int board[]) {
  
  vector<vector<unsigned int>>  threes;

  for(int i = 0; i < NUM_ROWS*3; i++) { 
    vector<unsigned int> subsection = {};
    threes.push_back(subsection);
  }

  for (int s = 0;  s < NUM_ROWS*3; s++) {
     vector<unsigned int> intermediate = threes.at(s);
     intermediate.push_back(board[s*3]);
     intermediate.push_back(board[s*3 + 1]);
     intermediate.push_back(board[s*3 + 2]);
     threes.at(s) = intermediate;
     intermediate.clear();
  }

 return threes;

}
  

bool validateSquares(unsigned int board[]) {
  bool is_valid = true;

  vector<vector<unsigned int>> rows = extractRowThrees(board);
  vector<vector<unsigned int>> squares = {};
  vector<vector<unsigned int>> fsquares = {};


  for(int i = 0; i < NUM_SQUARES; i++) { 
    vector<unsigned int> subsection = {};
    fsquares.push_back(subsection);
  }

  for(auto r : rows) {
    for(auto v : r) {
    }

  }

  for(int i = 0; i < rows.size(); i++){
    if(i%3 == 0){
      squares.push_back(rows.at(i));
    } 
  }

  for(int i = 0; i < rows.size(); i++){
    if(i%3 == 1){
      squares.push_back(rows.at(i));
    } 
  }

  for(int i = 0; i < rows.size(); i++){
    if(i%3 == 2){
      squares.push_back(rows.at(i));
    } 
  }


  for(unsigned int i = 0; i < NUM_SQUARES; i++) {
    unsigned int idx = i/3;
    vector<unsigned int> intermediate = {};

    for(auto s : squares[i*3]) {
      intermediate.push_back(s);
    }
    for(auto s : squares[i*3 + 1]) {
      intermediate.push_back(s);
    }
    for(auto s : squares[i*3 + 2]) {
      intermediate.push_back(s);
    }
    fsquares[i] = intermediate;


  }

  for(auto s:squares) {
    for (auto v : s) {
    }

  }
  
  for(auto s : fsquares){
    cout << "in validateSubsection " << s.size() << endl;

    if(!validateSubsection(s)){
      for(auto v : s) {
        cout << "invalidating " << v << endl;
      }
    return false;

    }
  }
  return is_valid;

}


bool validSolution(unsigned int board[9][9]){

  unsigned int *pointer = &board[0][0];

  bool is_valid = true;

  if(!validateRows(pointer)){
    is_valid = false;
  }
  if(!validateCols(pointer)) {
    is_valid = false;
  }
  if(!validateSquares(pointer)) {
    is_valid = false;

  }

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

// unsigned int board[9][9] = {{1,2,3,4,5,6,7,8,9},
// {2,3,1,5,6,4,8,9,7},
// {3,1,2,6,4,5,9,7,8},
// {4,5,6,7,8,9,1,2,3},
// {5,6,4,8,9,7,2,3,1},
// {6,4,5,9,7,8,3,1,2},
// {7,8,9,1,2,3,4,5,6},
// {8,9,7,2,3,1,5,6,4},
// {9,7,8,3,1,2,6,4,5}}; 
  cout << validSolution(board) << endl;
  return 0;

}