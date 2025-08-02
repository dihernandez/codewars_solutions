int solution(int number) {
  int total = 0;
  if(number == 0) {
    return 0;
  } else {
    for(int i = 0; i < number; i++) {
        if((i%5 == 0)&& (i%3 == 0)) {
          total += i;
        }
        else if(i%5 == 0) {
          total += i;
        } else if(i%3 == 0){
          total += i;
        } 
      }
    }
  return total;
}