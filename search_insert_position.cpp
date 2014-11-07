#include <iostream>
using namespace std;

class Solution {
public:
	int searchInsert(int A[], int n, int target) {
		int left = 0;
		int right = n-1;
		int mid = 0;

		while (left <= right) {
			mid = (left+right)/2;
			if (target == A[mid]) return mid;
			else if (target < A[mid]) right = mid - 1;
			else left = mid + 1;
		}

		if (target < A[mid]) {
			//if(right < 0) return 0;
			//else return right;
			return right+1;
		}	
		else return left;
	}

};

int main()
{
	int A[] = {1,3,5,6};
	int n = 4;

	Solution s;
	cout << s.searchInsert(A, n, 2) << endl;
}
