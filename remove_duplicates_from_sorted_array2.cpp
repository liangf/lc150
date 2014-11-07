#include <iostream>
using namespace std;


class Solution {
public:
	int removeDuplicates(int A[], int n) {
		if (n == 0) return 0;

		int cur = 1;
		int old = 1;
		int occurence = 0;
		while (cur < n) {
			if (A[cur] == A[cur-1]) {
				occurence++;
				if (occurence > 1) {
					cur++;
					continue;
				}
				else {
					A[old] = A[cur];
					old++;
					cur++;
				}
			}
  			else {
				occurence = 0;
				A[old] = A[cur];
				old++;
				cur++;
			}
		}
		return old;
	}
};

int main() 
{
	int A[] = {1,1,1,2,2,2};
	int n = 6;

	Solution s;
	int k = s.removeDuplicates(A, n);
	for (int i=0; i<k; i++) cout <<A[i] << endl;
}
