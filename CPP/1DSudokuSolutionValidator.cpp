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
       //if(i%j == 0) {
         //subsection.push_back(board[j*9 + i]);
      //}
      vector<unsigned int> intermediate = columns.at(i%9);
      //cout << board[j*9 + i%9] << endl;
      intermediate.push_back(board[j*9 + i%9]);
      columns.at(i%9) = intermediate;
      //colums.push_back(board[j*9]);
      if(board[i + j] == 0) {
        is_valid = false;
      }
    }
    // if(i%9 == 0) {
    //   for(int j = 0; j < NUM_COLS; j++) {
    //     subsection.push_back(board[j*9]);
    //     cout << board[j*9] << endl;
    //   }
    // }


 //else {
    //   if(!validateSubsection(subsection)){
    //     cout << "in validateSubsection " << subsection.size() << endl;
    //     return false;
    //   }
    // }
  }
    for(auto c : columns){
         cout << "in validateSubsection " << c.size() << endl;
        if(!validateSubsection(c)){
          cout << "invalid " << endl;
          is_valid = false;

    }
   }

  return is_valid;
}

  vector<vector<unsigned int>> extractRowThrees(unsigned int board[]) {
  
  vector<vector<unsigned int>>  threes;

  for(int i = 0; i < NUM_SQUARES; i++) { 
    vector<unsigned int> subsection = {};
    threes.push_back(subsection);
  }
  
  for(int i = 0; i < NUM_ROWS * NUM_COLS; i += 9){


    for (int j = 0; j < NUM_ROWS; j++) {
      vector<unsigned int> intermediate = threes.at(j);

      intermediate.push_back(board[j+i]);
      threes.at(j) = intermediate;
   }

 }
 return threes;

}

bool validateSquares(unsigned int board[]) {
  bool is_valid;
  vector<vector<unsigned int>> squares = {};

  for(int i = 0; i < NUM_SQUARES; i++) { 
    vector<unsigned int> subsection = {};
    squares.push_back(subsection);
  }

  // for(int i = 0; i < NUM_ROWS * NUM_COLS; i++) {
  //     for (int j = 0; j < NUM_SQUARES; j++){
  //     vector<unsigned int> intermediate = squares.at(j);
  //       //for(int c = 0; c < 3; c++) {
  //       //cout << board[j*9 + i%9] << endl;
  //         intermediate.push_back(board[i%3]);
  //         intermediate.push_back(board[i%3 + 1]);
  //         intermediate.push_back(board[i%3 + 2]);
  //       //}
  //     squares.at(j) = intermediate;
  //   }
  // }

  // for (int r = 0; r < NUM_ROWS; r++) 
  // {

  //   vector<unsigned int> intermediate = squares.at(r);

  //   for (int c = 0; c < NUM_COLS; c++) {

  //     intermediate.push_back(board[r*9 + c%3]);
  //     intermediate.push_back(board[r*9 + (c + 1)%3]);
  //     intermediate.push_back(board[r*9 + (c + 2)%3]);

  //   }

  //       for (auto s : intermediate)
  //   {
  //     cout << "intermediate values are  " << s << endl;
  //   }
  //     squares.at(r) = intermediate;
  // }

    for(int v = 0; v < NUM_ROWS * NUM_COLS; v++) {
      vector<unsigned int> intermediate = squares.at(v%NUM_SQUARES);
      unsigned int index = (v%9)*v;
      intermediate.push_back(board[index]);
      intermediate.push_back(board[index + 1]);
      intermediate.push_back(board[index + 2]);
      squares.at(v%NUM_SQUARES) = intermediate; 

    }

    // for(int c = 0; c < 3; c++){
    //   vector<unsigned int> intermediate = squares.at(i);
    //   for(int j = 0; j < 3; j++) {
    //     if(i%3 == 1) {
    //         intermediate.push_back(board[i + 0 + c*NUM_COLS ]);
    //         intermediate.push_back(board[i + 1 + c*NUM_COLS ]);
    //         intermediate.push_back(board[i + 2 + c*NUM_COLS ]);
    //         //cout << "board at " <<  board[0 + c*3 + 9*j] << endl;
    //     } else if(i%3 == 2) {
    //         intermediate.push_back(board[i*2                                                                               + 0 + c*NUM_COLS ]);
    //         intermediate.push_back(board[i*2 + 1 + c*NUM_COLS ]);
    //         intermediate.push_back(board[i*2 + 2 + c*NUM_COLS ]);
    //     }
    //     else if(i%3 == 0) {
    //         intermediate.push_back(board[i*3 + 0 + c*NUM_COLS ]);
    //         intermediate.push_back(board[i*3 + 1 + c*NUM_COLS ]);
    //         intermediate.push_back(board[i*3 + 2 + c*NUM_COLS ]);
    //     }
    //   }
    //   squares.at(i) = intermediate;
  //}

    // for(int j = 3; j < 6; j++) {
    //   vector<unsigned int> intermediate = squares.at(i);
    //   intermediate.push_back(board[0 + 9*j]);
    //   intermediate.push_back(board[1 + 9*j]);
    //   intermediate.push_back(board[2 + 9*j]);
    //   cout << "board at " <<  board[i%3 + 9*j] << endl;
    //   squares.at(i) = intermediate;
    // }

    // for(int j = 6; j < 9; j++) {
    //   vector<unsigned int> intermediate = squares.at(i);
    //   intermediate.push_back(board[0 + 9*j]);
    //   intermediate.push_back(board[1 + 9*j]);
    //   intermediate.push_back(board[2 + 9*j]);
    //   cout << "board at " <<  board[i%3 + 9*j] << endl;
    //   squares.at(i) = intermediate;
    // }

  //}

  cout << "Squares is of size " << squares.size() << endl;

  for(auto s : squares){
    cout << "in validateSubsection " << s.size() << endl;

    if(!validateSubsection(s)){
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

  cout << "is valid is " << is_valid << endl;
  return is_valid;
}

int main() {
  cout << "in main" << endl;
unsigned int board[9][9] = {{1,2,3,4,5,6,7,8,9},
{2,3,1,5,6,4,8,9,7},
{3,1,2,6,4,5,9,7,8},
{4,5,6,7,8,9,1,2,3},
{5,6,4,8,9,7,2,3,1},
{6,4,5,9,7,8,3,1,2},
{7,8,9,1,2,3,4,5,6},
{8,9,7,2,3,1,5,6,4},
{9,7,8,3,1,2,6,4,5}}; 
  cout << validSolution(board) << endl;
  return 0;

}