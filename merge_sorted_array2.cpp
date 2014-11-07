#include <iostream>
using namespace std;

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		for (int z=0; z<m; z++) cout << A[z] << " ";
		cout << endl;
		for (int z=0; z<n; z++) cout << B[z] << " ";
		cout << endl;
		int k = n+n-1;
		int i = m-1;
		int j = n-1;

		for (; i>=0 && j>=0; k--) {
			if (A[i] >= B[j]) {
				A[k] = A[i];
				i--;
			}
			else {
				A[k] = B[j];
				j--;
			}
		}
		while (j >= 0) {
			A[k] = B[j];
			k--;
			j--;
		} 		

		for (int z=0; z<m+n; z++) cout << A[z] << endl;
	}
};


int main()
{
	int A[] = {1,1,2,2,3,3};
	int B[] = {1,1,2,2,3};
	int m = 6;
	int n = 5;

	Solution s;
	s.merge(A, m, B, n);
}
