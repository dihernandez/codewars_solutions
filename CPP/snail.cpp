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

  const int l = snail_map.size();
  const int d = snail_map.size(); 
  int length = snail_map.size(); // initial length and deapth
  int deapth = snail_map[0].size();
  int start_deapth = 0;
  int start_length = 0;
  int from_right = 0;
  int from_left = length - 1;
  int from_top = 0;
  int from_bottom = deapth - 1;
  
  int start = snail_map[0][0];
    
  int test = 0;
  while(result.size() <= l*d && test<16) {
    test++;
    switch (dir) {
        case RIGHT:        
            cout <<" going right "<< endl;
            for(int i = 0; i <= length; i++){
                if(i== length) { 
                    cout << "changing direction " << endl;
                    dir = DOWN;
                    length = 1;
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
            for(int i = 0; i <= deapth; i++){
                if(i== deapth) {
                    cout << "changing direction " << endl;

                    dir = LEFT;
                    deapth -= 1;
                    from_left--;
                    break;
                } else {
            
                    cout << "pushing back " << " i is " << i << " " << snail_map[i][from_left] << "from left is " << from_left << endl;
                    if(i == 0) {
                        // pass, corner 
                    } else {
                    result.push_back(snail_map[i][from_left]);
                    }
                }
            }
            break;

        case LEFT:
            cout << " going left "<< endl;
            for(int i = length; i >= 0; i--){
                if(i== 0) {

                    cout << "changing direction " << endl;
                    dir = UP;
                    length -= 1;
                    from_bottom--;
                    break;
                }                
                cout << "pushing back " << " i is " << i << " " << snail_map[from_top][i] << " deapth " << deapth << endl;
                if(i == length) {
                    //pass, corner
                } else {
                result.push_back(snail_map[from_top][i]);
                }
            

            }
            break;

        case UP:
            cout <<" going up "<< endl;

            for(int i = deapth; i >= 0; i--){
                if(i== 0) {

                    cout << "changing direction " << endl;

                    dir = RIGHT;
                    deapth -= 1;
                    from_right++;
                    break;
                }

                cout << "pushing back " << " i is " << i << " snail map selection is " << snail_map[i][from_right] << " from_right " << from_right << endl;
                result.push_back(snail_map[i][from_right]);
                

            }
            break;
    }
    //result.push_back(0);
  }

  return result;
}

int main(){
    vector<int> result =  snail({{1,2,3,4}, {12,13,14,5}, {11,16,15,6}, {10,9,8,7}});
    
    for(auto v : result) {
        cout << v << endl;
    }
}