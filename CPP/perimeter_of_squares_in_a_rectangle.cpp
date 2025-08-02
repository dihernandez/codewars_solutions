#include#include <vector>
#include <math.h>

typedef unsigned long long ull;
class SumFct
{
  private:
  static std::vector<ull> fib_visited;
  public:
  static ull perimeter(int n);
  static ull fib(int n);
};

std::vector<ull> SumFct::fib_visited = {};

ull SumFct::fib(int n) {
  ull x = 1;
  ull y = 1;
  ull z = 0;
  for (int i = 0; i < n; i++) {
    z = x + y;
    x = y;
    y = z;
  }
  return x;
}

ull SumFct::perimeter(int n) {
  std::vector<ull> squares;
  fib_visited.clear();

  ull sum = 0;
  for(int i = 0; i < n + 1; i++) {
    ull fib_val = fib(i);
    if(fib_val == 1 && std::count(fib_visited.begin(), fib_visited.end(), 1) < 2){
      fib_visited.push_back(1);
    } else if (!std::count(fib_visited.begin(), fib_visited.end(), fib_val)){
      fib_visited.push_back(fib_val);
    }
  }

  for(auto square: fib_visited) {
    sum += 4*square;
  }
  return sum;
}
