#include <iostream>
using namespace std;

class Solution {
public:
	int search(int A[], int n, int target) {
	
		while () {
			mid = left + (right-left)/2;
			if (target == A[mid]) return mid;
			if (target < A[mid]) right = mid - 1;
			if (target > A[mid]) left = mid + 1;
		}	
	}
};

int main()
{

}
