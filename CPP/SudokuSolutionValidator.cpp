#include <list>
#include <iostream>
using namespace std;

// bool squareIsValid(unsigned int (&square)[9]) {
//   list<int> numbers_present = {1,2,3,4,5,6,7,8,9,0};
//   list<int> numbers_present_immutable = {1,2,3,4,5,6,7,8,9,0};
//   for(auto& c : square) {
//     for (auto num : numbers_present_immutable) {
//      if(c == num) {
//       numbers_present.remove(num);
//     }     
//     }

//   }
//   return numbers_present.size() == 0;
// }

const unsigned int NUM_ROWS = 9;
const unsigned int NUM_COLS = 9;

bool sectionIsValid(list<unsigned int> &section) {
  list<unsigned int> numbers_present = {1,2,3,4,5,6,7,8,9,0};
  list<unsigned int> numbers_present_immutable = {1,2,3,4,5,6,7,8,9,0};
  for(auto& c : section) {
    cout  << c << endl;
    for (auto& num : numbers_present_immutable) {
      if(c == 0) {
        return false;
      }
      if(c == num) {
        numbers_present.remove(num);
      }     
    }

  }
  return numbers_present.size() == 0;
}

// bool colIsValid(unsigned int col[9]) {
  
//   return true;
// }
list<list<unsigned int>> extractRows(unsigned int **pointer) {
  unsigned int **board = pointer;
  list<list<unsigned int>> rows;

   for(unsigned int i = 0; i < NUM_ROWS; i++) {
      list<unsigned int> row = {};
      for(unsigned int j = 0; j < NUM_COLS; j++) {
        row.push_back(board[i][j]);
      }
      rows.push_back(row);
   }
   return rows;
 }

list<list<unsigned int>> extractSquares(unsigned int **pointer) {
  unsigned int *board = pointer;
  list<list<unsigned int>> squares = {};
   for(unsigned int i = 0; i < NUM_ROWS; i++) {
      cout << board[i] << endl;
   }
  //for(auto b : board) {
  //    squares.push_front(b);
 // }
  //return squares;
  return squares;
}

bool validSolution(unsigned int board[9][9]){
  /* Write your solution here */
  unsigned int **pointer = &board[0];

  list<list<unsigned int>> rows = extractRows(pointer);
  //list<list<unsigned int>> cols;//extractCols(board);
  //list<unsigned int> squares = extractSquares(pointer);
  bool is_valid = true;
//  for(auto c: cols) {
//    if(!sectionIsValid(c)) {
//      is_valid = false;
//    }
//  }
 for(auto r: rows) {
     if(!sectionIsValid(r)) {
      is_valid = false;
     } 
      for(auto i : r) {
      cout << i << endl;
     }
  }

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