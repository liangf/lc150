#include <iostream>
using namespace std;

class Solution {
public:
	int jump(int A[], int n) {
		if (n <= 1) return 0; 
		for (int i=1; i<n; i++) {
			A[i] = A[i-1]<=0 ? -1 : max(A[i-1]-1, A[i]);	
		}
		int step = 0, start = 0;
		while (true) {
			start += A[start];
			step++;
			if (start >= n-1) break;
		}	
		return step;
	}
};

int main()
{
	//int A[] = {2, 3, 1, 1, 4};
	//int A[] = {0};
	int A[] = {1};
	Solution s;
	cout << s.jump(A, 1) << endl;
}
