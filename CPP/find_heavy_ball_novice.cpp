#include<vector>

unsigned int findBall(Scales scales) {

  unsigned int indexOfHeavyBall = 0;
  
  if(scales.getWeight({0,1,2,3}, {4,5,6,7}) == -1) { // left side is heavier
    if (scales.getWeight({0,1},{2,3}) == -1) {
      if(scales.getWeight({0},{1}) == -1) {
        return 0;
      } else {
        return 1;
      }
    } else {
      if(scales.getWeight({2},{3}) == -1) {
        return 2;
      } else {
        return 3;
      }
    }
  } else {
    if(scales.getWeight({4,5}, {6,7}) == -1) {
      if (scales.getWeight({4}, {5}) == -1) {
        return 4;
      } else {
        return 5;
      }
    } else {
      if (scales.getWeight({6},{7}) == -1) {
        return 6;
      } else {
        return 7;
      }
    }
  } 

  return indexOfHeavyBall;
}