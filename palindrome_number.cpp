#include <iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0) return false;
		int base = 1;
		while (x/base >= 10) {
			base *= 10;
		}
		while (base > 1) {
			if (x/base != x%10) return false;
			x = x - (x/base)*base;
			x = x/10;
			base = base/100; 
		}
		return true;
	}
};


int main()
{
	Solution s;
	//cout << s.isPalindrome(12321) << endl;
	//cout << s.isPalindrome(10) << endl;
	cout << s.isPalindrome(1001) << endl;
	//cout << s.isPalindrome(10021) << endl;
}
