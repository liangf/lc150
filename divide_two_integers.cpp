#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		int result = 0;
		long long num = abs((long long) dividend);
		long long d = abs((long long) divisor);
		while (d <= num) {
			int count = 0;
			long long d1 = d;
			while (d1<<1 <= num) {
				d1 <<= 1;
				count++; 
			}
			num -= d<<count;
			result += 1<<count;
		}
		if ((dividend>0&&divisor>0)||(dividend<0&&divisor<0)) return result;
		return -result;
	}
};

int main()
{
	Solution s;
	//cout << s.divide(9, 2) << endl;
	//cout << s.divide(2, 2) << endl;
	//cout << s.divide(9, 3) << endl;
	//cout << s.divide(-9, 3) << endl;
	//cout << s.divide(-9, -3) << endl;
	//cout << s.divide(INT_MAX, 1) << endl;
	cout << s.divide(INT_MAX, INT_MIN) << endl;
}
