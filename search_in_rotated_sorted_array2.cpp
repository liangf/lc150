#include <iostream>
using namespace std;

class Solution {
public:
	bool search(int A[], int n, int target) {
		int left = 0;
		int right = n - 1;
		int mid = 0;

		while (left <= right) {
			mid = left + (right-left)/2;
			if (target == A[mid]) return true;
			if (A[mid] > A[left]) {
				if (A[left]<=target && target<A[mid]) right = mid - 1;
				else left = mid + 1;
			}
			else if (A[mid] < A[left]){
				if (A[mid]<target && target<=A[right]) left = mid + 1;
				else right = mid - 1;
			}
			else left++;
		}
		return false;
	}
};


int main()
{
	int A[] = {1,3,1,1,1};
	int n = 5;

	Solution s;
	cout << s.search(A, n, 3) << endl;
}
