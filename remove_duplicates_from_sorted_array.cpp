#include <iostream>
using namespace std;

class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n == 0) return 0;

		int old = 1;
		int cur = 1;

		while (cur < n) {
			if (A[cur-1] == A[cur]) {
				cur++;
				continue;
			}
			A[old] = A[cur];
			old++;
			cur++;
		}
		//for (int i=0; i<old; i++) cout << A[i] << endl;
		return old;
	}
};


int main()
{
	int A[] = {1,1,1,2};
	Solution s;
  	cout << s.removeDuplicates(A, 4) << endl;
	return 0;
}
