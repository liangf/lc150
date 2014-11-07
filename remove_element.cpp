#include <iostream>
using namespace std;

class Solution {
public:
	int removeElement(int A[], int n, int elem) {
		if (n == 0) return 0;

		int right = n - 1;
		int i = 0;
		while (i < right) {
			if (elem == A[i]) {
				swap(A[i], A[right]);
				right--;
			}
			else i++;
		}
		if (elem == A[i]) return right;
		return right+1;
	}
};


int main()
{
	int A[] = {3};
	int n = 1;
	
	Solution s;
	cout << s.removeElement(A, n, 1) << endl;	
}
