#include <iostream>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:  
  int reverse(int x) {

    int is_nagtive = 1;
    if (x < 0) {
      is_nagtive = -1;
      x = -1*x;
    }

    vector<int> vec;
    while (x/10) {
      int old_x = x;
      x = x / 10;
      int d = old_x - x*10;     
      vec.push_back(d);
    }
    vec.push_back(x);

    int sum = 0;
    sum = vec[0];
    for (int i=1; i<vec.size(); i++) {
      if (sum > INT_MAX/10) return 0;
      sum  = sum * 10;
      if (sum > INT_MAX-vec[i]) return 0;
      sum += vec[i];  
    }
    return sum * is_nagtive;
  }

};

int main() 
{
  cout << INT_MAX << endl;
  Solution s;
  cout << s.reverse(-100000003) << endl;
  return 0;
}
