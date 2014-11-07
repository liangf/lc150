#include <iostream>
#include <iomanip>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(int A[], int m, int B[], int n) {
		if ((m+n)%2 == 1) return select(A, m, B, n, (m+n)/2+1);
		else  
			return (select(A, m, B, n, (m+n)/2) + select(A, m, B, n, (m+n)/2+1))/2.0;
	}
	int select(int A[], int m, int B[], int n, int k) {
		if (m==0 && n==0) return 0;
		if (m == 0) return B[k-1];
		if (n == 0) return A[k-1];
		if (k == 1) return min(A[0], B[0]);

		int ra = min(k/2, m);
		int rb = min(k-ra, n);
		//cout <<k<<": "<<ra<<","<<rb << endl;
		//cout << A[0] << " " << B[0] << endl;
		if (A[ra-1] < B[rb-1]) return select(A+ra, m-ra, B, n, k-ra);
		else return select(A, m, B+rb, n-rb, k-rb);
	}
};


int main()
{
	//int A[] = {};
	//int B[] = {1};
	
	//int A[] = {};
	//int B[] = {2, 3};

	//int A[] = {1, 3, 5, 7, 9};
	//int B[] = {2, 4, 8, 10, 12, 14, 16, 18};

	int A[] = {2, 3};
	int B[] = {};

	Solution s;
	cout << s.findMedianSortedArrays(A, 2, B, 0) << endl;
}
