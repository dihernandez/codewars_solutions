#include <vector>
#include <utility>
#include <queue>
#include <iostream>

using namespace std;

vector<pair<int,int>> get_neighbors(vector<vector<pair<int,int>>> map,
   pair<int,int> node, vector<pair<int,int>> directions, vector<vector<bool>> visited) {
     vector<pair<int,int>> neighbors = {};
     for (auto dir : directions) {
       pair<int,int> new_dir = {node.first + dir.first, node.second + dir.second};
       if (new_dir.first >=0 && new_dir.first <= 2 && new_dir.second >=0 && new_dir.second <=2) {
         if(!visited[new_dir.first][new_dir.second]) {
           neighbors.push_back(new_dir);
         } else {
           pair<int,int> two_away = {node.first + 2*dir.first, node.second + 2*dir.second};
           if(two_away.first >= 0 && two_away.first <= 2 && two_away.second >= 0 && two_away.second <= 2
           && !visited[two_away.first][two_away.second]) {
             neighbors.push_back(two_away);
           }
         }
       }
     }
     return neighbors;
   }

unsigned int countPaths(vector<vector<pair<int,int>>> map, pair<int,int> node, vector<vector<bool>> visited, int length_end, int length_so_far) {
  if(length_so_far >= length_end) {
    std::cout << "(" << node.first << "),(" << node.second << ")" <<endl;
    return 1;
  }
  visited[node.first][node.second] = true;
  int path_length = 0;
  vector<pair<int,int>> directions = {{-1,0}, {1,0}, {0,1}, {0,-1}, {1,1}, {1,-1},
   {-1,1}, {-1,1}};

  vector<pair<int,int>> neighbors = get_neighbors(map, node, directions, visited);
  for (auto n : neighbors) {
    path_length += countPaths(map, n, visited, length_end, length_so_far+1);
  }

  return path_length;
}

unsigned int countPatternsFrom(char firstDot, unsigned short length) {
  vector<vector<pair<int,int>>> map = {{{0,0},{0,1},{0,2}},{{1,0},{1,1},{1,2}},
  {{2,0},{2,1},{2,2}}};
  vector<vector<bool>> visited(3, vector<bool>(3,false));


  pair<int,int> first_node= {};
  switch (firstDot) {
   case 'A':
     first_node = {0,0};
     break;
   case 'B':
     first_node = {0,1};
     break;
   case 'C':
     first_node = {0,2};
     break;
   case 'D':
     first_node = {1,0};
     break;
   case 'E':
     first_node = {1,1};
     break;
   case 'F':
     first_node = {1,2};
     break;
   case 'G':
     first_node = {2,0};
     break;
   case 'H':
     first_node = {2,1};
     break;
   case 'I':
     first_node = {2,2};
     break;
  }
  visited[first_node.first][first_node.second] = true;
  return countPaths(map, first_node, visited, length, 1);
}

int main() {
  cout << countPatternsFrom('C',2) << endl;
}
