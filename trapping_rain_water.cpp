#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
	int trap(int A[], int n) {
		if (n <= 0) return 0;
		int left[n], right[n];
		int max = 0;
		left[0] = 0;
		for (int i=1; i<n; i++) {
			if (A[i-1] > max) max = A[i-1];		
			left[i] = max;
		}
		max = 0;
		right[n-1] = 0;
		for (int i=n-2; i>=0; i--) {
			if (A[i+1] > max) max = A[i+1];
			right[i] = max;
		}
		int sum = 0;
		for (int i=0; i<n; i++) {
			int each = min(left[i], right[i]) - A[i];	
			if (each > 0) sum += each;
		}
		return sum;
	}
};

int main()
{
	int A[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	Solution s;
	cout << s.trap(A, 12) << endl;
}
