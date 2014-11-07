#include <iostream>
#include <climits>
using namespace std;
/*
class Solution {
public:
	int sqrt(int x) {
		return sqrt(x, 0, x);
	}
	int sqrt(int x, int left, int right) {
		int mid = (left+right)/2;
		if (left > right) return right;
		else if (mid > INT_MAX/mid) return sqrt(x, left, mid-1);
		else if (mid*mid == x) return mid;
		else if (mid*mid < x) return sqrt(x, mid+1, right);
		else if (mid*mid > x) return sqrt(x, left, mid-1); 
	}
};*/

class Solution {
public:
	int sqrt(int x) {
		long long left = 0, right = x;
		while (left <= right) {
			long long mid = (left+right)/2;
			long long square = mid * mid;
			if (square == x) return mid;
			else if (square < x) left = mid + 1;
			else right = mid - 1;	
		}		
		return right;
	}
};

int main()
{
	Solution s;
	cout << s.sqrt(2147395599) << endl;
	//cout << s.sqrt(15) << endl;
}
