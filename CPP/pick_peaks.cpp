#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

/* finds first peak occurance
returns index of first peak occurance
*/
vector<int> find_peaks(vector<int> data) {
  vector<int> peak_idx;
  if(data.size() < 3) {
    return peak_idx;
  }
  for(int i = 1; i < data.size() - 1; i++) {
    if (data[i - 1] < data[i] && data[i + 1] < data[i]) {
      peak_idx.push_back(i);
    }
  }
  
  return peak_idx;
}


void print_vector(vector<int> to_print) {
  for(auto v : to_print) {
    cout << v << endl;
  }
}

vector<int> find_plateaus(vector<int> data) {
  
  vector<int> plateau_idx;
  if(data.size() < 3) {
    return plateau_idx;
  }
  int start_consecutive = 0;
  int seen_before = 0;
  int furthest_seen = 0;
//   while(seen_before < data.size()) {
//     seen_before++;
//     for(int i = furthest_seen; i < data.size() - 1; i++) {
//         if(data[i - 1] < data[i] && data[i] == data[i + 1]){
//           start_consecutive = i;
//           cout << "start consecutive is " << start_consecutive << endl;
//           break;
//         }
//     }
//     if(start_consecutive != 0) {
//       for(int i = furthest_seen; i < data.size() - 1; i++) {
//         if(data[i +1] < data[i]) {
//           vector<int>::iterator it;
//           it = find(plateau_idx.begin(), plateau_idx.end(), start_consecutive); 
//           if (it == plateau_idx.end()){
//             plateau_idx.push_back(start_consecutive);
//             cout << "in push back" << endl;
//           }
//           furthest_seen = i + 1;
          
//           break;
//         }
//       }
      
  
//   }
// cout << "furthest seen is " << furthest_seen << endl;
//   }
    vector<int> updateable = data;
    while(updateable.size() > 0) {
   
    for(int i = 1; i < updateable.size(); i++) {
          if(updateable[i - 1] < updateable[i] && updateable[i] == updateable[i + 1]){
          start_consecutive = i;
          cout << "start consecutive is " << start_consecutive << "updateable[i] is " << updateable[i] << endl;
          break;
        }
    }

    if(start_consecutive != 0) {
      for(int i = start_consecutive; i < updateable.size() - 1; i++) {
        if(updateable[i +1] < updateable[i]) {
          //cout << "updateable[i+ i] is " << updateable[i + 1] << "at " << i + 1 << endl;
          vector<int>::iterator it;
          it = find(plateau_idx.begin(), plateau_idx.end(), start_consecutive); 
          if (it == plateau_idx.end()){
            plateau_idx.push_back(start_consecutive);
            cout << "in push back" << "start consecutive is "<< start_consecutive <<  endl;
          }
          furthest_seen = i + 1;
          
          break;
        }
      }
      

  
    }
    int offset = furthest_seen - start_consecutive;
    updateable.erase(updateable.begin());
      cout << "updateable is " << endl;
      print_vector(updateable);
  //  cout << "furthest seen is " << furthest_seen << endl;
  }
  
  
  // for(int i = 1; i < data.size() - 1; i++) {
  //     if(data[i - 1] < data[i] && data[i] == data[i + 1]){
  //       start_consecutive = i;
  //       break;
  //     }
  // }
  // if(start_consecutive != 0) {
  //   for(int i = start_consecutive; i < data.size() - 1; i++) {
  //     if(data[i +1] < data[i]) {
  //       plateau_idx.push_back(start_consecutive);
  //       break;
  //     }
  //   }
  // }
  return plateau_idx;
}

// vector<int> find_plateaus(vector<int> data) {
  
//   vector<int> plateau_idx;
//   if(data.size() < 3) {
//     return plateau_idx;
//   }
//   int start_consecutive = 0;
//   for(int i = 1; i < data.size() - 1; i++) {
//       if(data[i - 1] < data[i] && data[i] == data[i + 1]){
//         start_consecutive = i;
//       }
//   }
//   if(start_consecutive != 0) {
//     for(int i = start_consecutive; i < data.size() - 1; i++) {
//       if(data[i +1] < data[i]) {
//         plateau_idx.push_back(start_consecutive);
//         break;
//       }
//     }
//   }
//   return plateau_idx;
// }

PeakData pick_peaks(vector<int> v) {
   cout << "input is " << endl;
  for(auto val : v){
    cout << val << ",";
  }
  
  cout << endl;
  PeakData result;
  vector<int> peaks_idx = find_peaks(v);
  vector<int> plateaus_idx = find_plateaus(v);
  vector<int> indecies(peaks_idx.size() + plateaus_idx.size());
  merge(peaks_idx.begin(), peaks_idx.end(), plateaus_idx.begin(), plateaus_idx.end(), indecies.begin()); 
  //peaks_idx.insert(peaks_idx.end(), plateaus_idx.begin(), plateaus_idx.end());
  vector<int> peaks_val;
  for(auto p : indecies) {
    peaks_val.push_back(v[p]);
    //cout << p << endl;
  }

  result.pos = indecies;
  result.peaks = peaks_val;
  return result;
}