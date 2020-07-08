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


//vector<vector<unsigned int>> extractColThrees(vector<vector<unsigned int>> rows) {


  // vector<vector<unsigned int>> cols;
  // for(int i = 0; i < 3; i++) {


  //   for(int j = 0; j < NUM_SQUARES; j++) {
  //     vector<unsigned int> intermediate = cols.at(i%9);
  //     intermediate.push_back(rows.at(j*9 + i%9));
  //     rows.at(i%9) = intermediate;

  //   }

  // }


//}
  

bool validateSquares(unsigned int board[]) {
  bool is_valid;

  vector<vector<unsigned int>> rows = extractRowThrees(board);
  vector<vector<unsigned int>> squares = {};
  vector<vector<unsigned int>> fsquares = {};


  for(int i = 0; i < NUM_SQUARES; i++) { 
    vector<unsigned int> subsection = {};
    //squares.push_back(subsection);
    //fsquares.push_back(subsection);
  }

  for(auto r : rows) {
    for(auto v : r) {
      cout << "row value is " << v << endl;
    }
    cout << "next row" << endl;

  }

  for(int i = 0; i < rows.size(); i++){
    if(i%3 == 0){
      squares.push_back(rows.at(i));
      cout <<" i here " << endl;
    } 
  }

  for(int i = 0; i < rows.size(); i++){
    if(i%3 == 1){
      squares.push_back(rows.at(i));
      cout <<" i here " << endl;
    } 
  }

  for(int i = 0; i < rows.size(); i++){
    if(i%3 == 2){
      squares.push_back(rows.at(i));
      cout <<" i here " << endl;
    } 
  }

  // for(int i = 0; i < 9; i++ ) {
  //   vector<unsigned int> v = squares.at(i);
  //   cout << "squares lenth is" << squares.size() << ((i%3)*3) << "v length is " << v.size() << endl;
  //   //fsquares.at(i).push_back(squares.at(i/3).at((i%3)*3));
  //   //fsquares.at(i) = squares.at(i/3).at((i%3)*3 + 1);
  //   //fsquares.at(i) = squares.at(i/3).at((i%3)*3 + 2);
  //   cout << "after push_back " << endl;
  // }

  // for (auto s : squares) {
    //cout << "square indx" << s.at((counter%3)*3) << endl;
    //fsquares.push_back();
    // fsquares.push_back(s.at((counter%3)*3 + 1));
    // fsquares.push_back(s.at((counter%3)*3 + 2));

  //}

  // int counter = 0;
  // vector<unsigned int> intermediate = {};
  // for(auto s: squares) {

  //   for(int i = 1; i < s.size(); i++) {
  //     intermediate.push_back(s[i]);
  //     counter++;
  //     cout << "intermediate length is " << intermediate.size() << endl;
  //     if(intermediate.size() == 9) {
  //       break;
  //     }

  //     // cout << "s[i] is " << s[i] << endl
  //       //intermediate = {};
  //   }
  //   if(counter%9 == 0) {
  //     fsquares.push_back(intermediate);
  //     intermediate = {};
  //   }

  // }
  
  // vector<unsigned int> intermediate = {};

  // for(int i = 0; i < 3; i++) {
  //   for(auto s : squares[i]){ 
  //     cout << "putting this in intermediate " << s << endl;
  //     intermediate.push_back(s);
  //   }
  // }
  // fsquares.push_back(intermediate);

  // intermediate {};
  // for(int i = 3; i < 6; i++) {
  //   for(auto s : squares[i]){ 
  //     cout << "putting this in intermediate " << s << endl;
  //     intermediate.push_back(s);
  //   }
  // }
  // fsquares.push_back(intermediate); 

  for(int ns = 0; ns < NUM_SQUARES; ns++) {
      vector<unsigned int> intermediate = {};

      for(int i = ns/3; i < ns/3 + 3; i++) {
        for(auto s : squares[i]){ 
          cout << "putting this in intermediate " << s << endl;
          intermediate.push_back(s);
        }
      }
      fsquares.push_back(intermediate);
  }


  cout << "squares is of size " << squares.size();
  for(auto s:squares) {
    for (auto v : s) {
      cout << "square value is " << v << endl;
    }
    cout << "square is of size " << s.size() << endl;
   // int counter = 0;
  }
  // for(auto s : squares) {
  //   vector<unsigned int> intermediate = {};
  //   for(auto sub: s) {
  //       cout << "square value is" <<sub << endl;
  //       if(counter < 3) {
  //         intermediate.push_back(s)
  //       }
  //   }
  //   vector<vector<unsigned int>> intermediate = {};
  //   while(counter < 3) {
  //     intermediate.push_back(s);
  //     counter++;
  //   }
  //   fsquares.push_back(intermediate);
  //   intermediate = {};
  //   while (counter >=3 && counter < 6) {
  //     intermediate.push_back(s);
  //     counter++;
  //   }
  //   fsquares.push_back(intermediate);

    //if(counter%3 == 0){
       //vector<unsigned int > intermediate = squares.at((counter%3)*3);
       //cout << "index is" << (counter%3)*3 << endl;
       // for(auto a: squares.at((counter%3)*3)) {
       //    cout << "squres at index is " << a << (counter%3)*3<< endl;
       // }
       //fsquares.push_back(intermediate);
   // } 
    //cout << "next subsqure" << endl;
  //   counter++;

  // }


  for(auto f : fsquares) {
    for(auto i: f) {
      cout<<"in fsquares middle " << i << endl;

    }
    cout << "next fsquares " << f.size() << endl;

  }
  // for(int r = 0; r < NUM_SQUARES * 3; r++) {
  //     vector<unsigned int> intermediate = squares.at(r/3);
  //     for(auto val : rows.at(r)) {
  //       intermediate.push_back(val);
  //     }
  //     // for(auto val : rows.at(r + 1)) {
  //     //   intermediate.push_back(val);
  //     // }
  //     // for(auto val : rows.at(r + 2)) {
  //     //   intermediate.push_back(val);
  //     // }
  //     squares.at(r/3) = intermediate; 
  // } 

  // int counter = 0;
  // for(int r: rows) {
  //   vector<unsigned int> intermediate = squares.at(counter/3);

  //   for(int i = 0; i < NUM_SQUARES; i++) {
  //     intermediate.push_back(r.at(i*9 + 9));
  //   }
  //   squares.at(counter/3) = intermediate;
  //   counter++;
  // }
  // for(auto s : squares) {
  //   for(auto v : s) {
  //     cout << "row value is " << v << endl;
  //   }
  //   cout << "next row" << endl;

  // }
  // vector<vector<unsigned int>> squares = {};

  // for(int i = 0; i < NUM_SQUARES; i++) { 
  //   vector<unsigned int> subsection = {};
  //   squares.push_back(subsection);
  // }


  //   for(int v = 0; v < NUM_ROWS * NUM_COLS; v++) {
  //     vector<unsigned int> intermediate = squares.at(v%NUM_SQUARES);
  //     unsigned int index = (v%9)*v;
  //     intermediate.push_back(board[index]);
  //     intermediate.push_back(board[index + 1]);
  //     intermediate.push_back(board[index + 2]);
  //     squares.at(v%NUM_SQUARES) = intermediate; 

  //   }



//  cout << "Squares is of size " << squares.size() << endl;

  // for(auto s : squares){
  //   cout << "in validateSubsection " << s.size() << endl;

  //   if(!validateSubsection(s)){
  //   return false;

  //   }
  // }
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