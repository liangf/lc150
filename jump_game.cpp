#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
	bool canJump(int A[], int n) {
		if (n == 0) return true;
		for (int i=1; i<n; i++) {
			A[i] = A[i-1]<=0 ? -1 : max(A[i-1]-1, A[i]);	
		}
		return A[n-1]>=0 ? true : false;	
	}
};

int main()
{
	//int A[] = {2, 3, 1, 1, 4};
	//int A[] = {3, 2, 1, 0, 4};
	int A[] = {2, 5, 0, 0};
	Solution s;
	cout << s.canJump(A, 4) << endl;
}
