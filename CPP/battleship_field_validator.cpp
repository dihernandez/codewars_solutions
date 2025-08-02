#include <vector>
#include <iostream>
#include <unordered_map>
/* Overal organization: keep map of type of ship to quantity detected
scan grid five times: once to identify single cells, once to identify
destroyers, once to identify cruisers, and once to identify battleship,
then once to search for any illegal shapes or positions*/

int ROWS = 10;
int COLS = 10;

// helper methods

bool is_surrounded_by_zeros(int r, int c, std::vector<std::vector<int>> directions,
  std::vector<std::vector<int>>& field) {

  bool surroundings_are_zero = true;
  for(auto dir : directions) {
    int new_r = r + dir[0];
    int new_c = c + dir[1];
    //std::cout << "new_r is " << new_r << " new_c is " << new_c << std::endl;
    if(new_r >= 0 && new_r < ROWS && new_c >= 0 && new_c < COLS) {
      if(field[new_r][new_c] == 1) {
    //    std::cout << "field at new loc is " << field[new_r][new_c] << std::endl;
        surroundings_are_zero = false;
      }
    }
  }
  return surroundings_are_zero;
}

int sum_valid_neighbors(int r, int c, std::vector<std::vector<int>> &field) {
  int sum_neighbors = 0;

  if(r - 1 >= 0) {
    sum_neighbors += field[r-1][c];
  }
  if(r + 1 < ROWS){
      sum_neighbors += field[r+1][c];
  }
  if(c - 1 >= 0) {
      sum_neighbors += field[r][c-1];
  }
  if(c + 1 < COLS) {
      sum_neighbors += field[r][c+1];
  }

  return sum_neighbors;
}

// implementation methods

bool has_no_diagonal_neighbors(std::vector<std::vector<int>> & field) {
  std::vector<std::vector<int>> diagonal_dirs = {{1,-1},{1,1},{-1,1},{-1,-1}};
  bool no_diagonal_neighbors = true;
  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      if(field[r][c] == 1 && !is_surrounded_by_zeros(r, c, diagonal_dirs, field)){
        std::cout << "r  is  " << r << " c is " << c << std::endl;
        no_diagonal_neighbors = false;
      }
    }

  }
  return no_diagonal_neighbors;
}

bool has_no_touching_ships(std::vector<std::vector<int>> field) {
  bool no_touching_ships = true;
  for(int r = 0; r < ROWS; r++) {
    for(int c = 0; c < COLS; c++) {
      bool has_horizontal = (r - 1 >= 0 && field[r-1][c] == 1) ||
       (r + 1 < ROWS && field[r+1][c] == 1);
       bool has_vertical = (c - 1 >= 0 && field[r][c-1] == 1) ||
       (c + 1 < COLS && field[r][c+1] == 1);
       if (has_horizontal && has_vertical) {
         no_touching_ships = false;
       }
    }
  }
  return no_touching_ships;
}

// Identify submarines:
int count_subs(std::vector<std::vector<int>>& field) {
  int num_subs = 0;
  std::vector<std::vector<int>> directions = {{1,-1},{1,1},{-1,1},{-1,-1},
  {1,0},{-1,0},{0,1},{0,-1}};

  for (int r = 0; r < ROWS; r++) {
    for (int c = 0; c < COLS; c++) {
      if (field[r][c] == 1) {
        if (is_surrounded_by_zeros(r, c, directions, field)) {
          num_subs++;
        }
      }
    }
  }
  return num_subs;
}

std::unordered_map<int,int> count_ships(std::vector<std::vector<int>> &field) {
  std::unordered_map<int, int> ships = {};

  for(int r = 0; r < ROWS; r++) {
    for(int c = 0; c < COLS; c++) {
      int num_neighbors = sum_valid_neighbors(r, c, field);
      if(num_neighbors == 1) {
        bool is_below = r+1 < ROWS && field[r+1][c] == 1;
        bool is_right = c+1 < COLS && field[r][c+1] == 1;
        if (is_below) {
          int ship_size = 1;
          int next_cell = r + 1;
          while(field[next_cell][c] == 1) {
            ship_size++;
            next_cell++;
          }
          if(ship_size == 2) {
            std::cout << "r: " << r << " c: " << c << std::endl;
          }
          if(ships.find(ship_size) == ships.end()) {
            ships.insert({ship_size, 1});
            for(const auto &[size, count] : ships) {
              std::cout << "ship size " << size << " count " << count << std::endl;
            }
          } else {
            ships[ship_size]++;
            for(const auto &[size, count] : ships) {
              std::cout << "ship size " << size << " count " << count << std::endl;
            }
          }
        }
        if (is_right) {
          int ship_size = 1;
          int next_cell = c + 1;
          while(field[next_cell][next_cell] == 1) {
            ship_size++;
            next_cell++;
          }
          if(ships.find(ship_size) == ships.end()) {
            ships.insert({ship_size, 1});
          } else {
            //std::cout << "ship size 2 is " << ships[ship_size] << std::endl;
            ships[ship_size]++;
          }
        }
      }
    }

  }
  return ships;
}



bool validate_battlefield(std::vector< std::vector<int> > field) {
  // Write your magic here ;)
  return true;
}

int main() {
  std::vector<std::vector<int>> valid_field = std::vector< std::vector<int> > {
      std::vector<int> {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
      std::vector<int> {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
      std::vector<int> {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
      std::vector<int> {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
      std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
      std::vector<int> {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
      std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
      std::vector<int> {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
      std::vector<int> {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
      std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    std::vector<std::vector<int>> invalid_field = std::vector< std::vector<int> > {
        std::vector<int> {1, 0, 0, 0, 0, 1, 1, 0, 0, 0},
        std::vector<int> {1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
        std::vector<int> {1, 0, 1, 0, 1, 1, 1, 0, 1, 0},
        std::vector<int> {1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        std::vector<int> {0, 0, 0, 0, 1, 1, 1, 0, 0, 0},
        std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        std::vector<int> {0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
        std::vector<int> {0, 0, 1, 1, 0, 0, 0, 1, 0, 0},
        std::vector<int> {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
      };
    std::cout << "num subs " << count_subs(valid_field) << std::endl;
    //std::cout << "valid field diagonals: "<< has_no_diagonal_neighbors(valid_field) << std::endl;
    //std::cout << "invalid field diagonals: " << has_no_diagonal_neighbors(invalid_field) << std::endl;
    //std::cout << "touching ships " << has_no_touching_ships(valid_field) << std::endl;
    //std::cout << "touching ships " << has_no_touching_ships(invalid_field) << std::endl;
    std::unordered_map<int,int> ships = count_ships(valid_field);
    for(const auto &[size, count] : ships) {
      std::cout << "ship size " << size << " count " << count << std::endl;
    }
}
