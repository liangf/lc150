#include <iostream>
using namespace std;

class Solution {
public:
	int firstMissingPositive(int A[], int n) {
		for (int i=0; i<n; i++) {
			if (A[i]<=0 || A[i]==i+1 || A[i]>n) continue;
			while (true) {
				swap(A[i], A[ A[i]-1 ]);
				if (A[i]<=0 || A[i]==i+1 || A[i]>n) break;
				if (A[i] == A[ A[i]-1 ]) break;
			}	
		}
		for (int i=0; i<n; i++) {
			if (A[i] != i+1) return i+1;
		}
		return n+1;
	}
};

int main()
{
	//int A[] = {1, 2, 0};
	//int A[] = {3, 4, -1, 1};
	int A[] = {1, 1};
	Solution s;
	cout << s.firstMissingPositive(A, 2) << endl;
}
