#include <iostream>
using namespace std;

class Solution {
public:
	void merge(int A[], int m, int B[], int n) {
		int i = m-1;
		int j = n-1;
		
		for (int k=m+n-1; k>=0; k--) {
			cout << i << " " << j << " " << k << endl;
			for (int b=0; b<n; b++) cout << B[b] << " ";
			cout << endl;
			if (i>0 && j>0) {/*
				if (B[j] > A[i]) {
					A[k] = B[j];
					j--;
				}
				else {*/
					A[k] = A[i];
					i--;	
				//}	
			}
			else {
				if (i < 0) A[k] = B[j--];
			}
		}
		//for (int i=0; i<m+n; i++) cout << A[i] << endl;
	}
};


int main()
{
	int A[] = {1,1,2,2,3,3};
	int B[] = {1,1,2,2,3};

	Solution s;
	s.merge(A, 6, B, 5);
}
