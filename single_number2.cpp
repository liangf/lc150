#include <iostream>
using namespace std;

class Solution {
public:
	int singleNumber(int A[], int n) {
		int one = 0, two = 0, three = 0;
		for (int i=0; i<n; i++) {
			two = two | (one & A[i]);
			one = one ^ A[i];
			three = one & two;
			two = two & (~three);
			one = one & (~three);
		}
		return one;
	}
};

int main()
{
	int A[] = {1, 2, 1, 2, 1, 2, 3};
	
	Solution s;
	cout << s.singleNumber(A, 7) << endl;
}
