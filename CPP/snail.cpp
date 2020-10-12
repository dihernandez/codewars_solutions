#include <vector>
#include <iostream>

using namespace std;



std::vector<int> snail(const std::vector<std::vector<int>> &snail_map) {
  vector<int> result {};
  enum direction {RIGHT, DOWN, LEFT, UP} dir;
  
  dir = RIGHT;
  if(snail_map.size() == 0){ 
    return {};
  } else if(snail_map.size() == 1){
    return snail_map[0];
  }
;

  int length = snail_map.size(); // initial length and deapth
  int deapth = snail_map[0].size();
  int start_deapth = 0;
  int start_length = 0;
  int from_right = 0;
  int from_left = 0;
  int from_top = 0;
  int from_bottom = 0;
  
  int start = snail_map[0][0];
    
  int test = 0;
  while(result.size() <= 4*length*deapth){
    test++;
    switch (dir) {
        case RIGHT:        
            cout <<" going right "<< endl;
            for(int i = 0; i <= length; i++){
                if(i== length) { 
                    cout << "changing direction " << endl;
                    dir = DOWN;
                    length -= 1;
                    from_top++;
                    break;
                } else {
                cout << "pushing back " << " i is " << i << " from_top is " << from_top << " " << snail_map[from_top][i] << endl;
                result.push_back(snail_map[from_top][i]);
                }

            }
            break;

        case DOWN:
            cout <<" going down "<< endl;
            for(int i = 1; i <= deapth; i++){
                if(i== deapth) {
                    cout << "in i == deapth" << endl;
                    dir = LEFT;
                    deapth -= 1;
                    start_length++;
                    break;
                } else {
                    cout << "pushing back " << " i is " << i << " " << snail_map[i][length] << "deapth is " << deapth << endl;
                    result.push_back(snail_map[i][length]);
                }
            }
            break;

        case LEFT:
            cout <<" going left "<< endl;
                for(int i = length - 1; i >= 0; i--){
                
                cout << "pushing back " << " i is " << i << " " << snail_map[deapth][i] << " deapth " << deapth << endl;
                result.push_back(snail_map[deapth][i]);
            
                if(i== 0) {
                    dir = UP;
                    length -= 1;
                    start_deapth++;
                    break;
                }
            }
            break;

        case UP:
            cout <<" going up "<< endl;

            for(int i = deapth; i >= 0; i--){
                if(i== 0) {
                    dir = RIGHT;
                    deapth -= 1;
                    from_right++;
                    break;
                }

                cout << "pushing back " << " i is " << i << " snail map selection is " << snail_map[i][from_right] << " from_right " << from_right << endl;
                result.push_back(snail_map[i - 1][from_right]);
                

            }
            break;
    }
  }

  return result;
}

int main(){
    vector<int> result =  snail({{1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7}});
    
    for(auto v : result) {
        cout << v << endl;
    }
}