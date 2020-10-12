#include <vector>
#include <iostream>

using namespace std;



std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
  vector<int> result {};
  enum direction {RIGHT, DOWN, LEFT, UP} dir;

  dir = RIGHT;
  if(snail_map.size() == 0){ 
    return {};
  }
  
  int length = snail_map.size(); // initial length and deapth
  int deapth = snail_map[0].size();
  
  int start = snail_map[0][0];
    
  int test = 0;
  while(test < 10) {  //result.size() < length*deapth
    test++;
    switch (dir) {
        case RIGHT:        
            cout <<" going right "<< endl;
            for(int i = 0; i <= length; i++){
                if(i== length) { 
                    cout << "changing direction " << endl;
                    dir = DOWN;
                    length -= 1;
                    break;
                } else {
                cout << "pushing back " << " i is " << i << "deapth - 1 " << snail_map[0][i] << endl;
                result.push_back(snail_map[0][i]);
                }

            }
            break;

        case DOWN:
            cout <<" going down "<< endl;
            for(int i = 0; i <= deapth; i++){
                if(i== deapth) {
                    dir = LEFT;
                    deapth -= 1;
                    break;
                } else {
                    cout << "pushing back " << " i is " << i << " " << snail_map[i][0] << endl;
                    result.push_back(snail_map[i][0]);
                }
            }
            break;

        case LEFT:
            cout <<" going left "<< endl;
                for(int i = length; i >= 0; i--){

                if(i== 0) {
                    dir = UP;
                    length -= 1;
                    break;
                }
                result.push_back(snail_map[i][0]);
            }
            break;

        case UP:
            cout <<" going up "<< endl;

            for(int i = deapth; i >= 0; i--){
                if(i== 0) {
                    dir = RIGHT;
                    deapth -= 1;
                    break;
                }
                result.push_back(snail_map[0][i]);
            }
            break;
    }
  }

  return result;
}

int main(){
    vector<int> result =  snail({{1,2}, {4,3}});
    
    for(auto v : result) {
        cout << v << endl;
    }
}