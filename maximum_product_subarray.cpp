#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
	int maxProduct(int A[], int n) {
		if (n <= 0) return 0;
		int product = 1, product2 = 0, result = INT_MIN;
		for (int i=0; i<n; i++) {
			if (A[i] == 0) {
				product = 1;	
				product2 = 0;
				result = max(result, 0);
				continue;
			}
			else if (A[i] < 0) {
				if (product2 == 0) {
					product2 = 1;
					product *= A[i];
					result = max(result, product);
					continue;
				}
			}
			product *= A[i];
			product2 *= A[i];
			result = max(max(result, product), product2);
			//cout << A[i] << ": ";
			//cout << "product:" << product << " ";
			//cout << "product2:" << product2 << endl;
		}
		return result;
	}
};

int main()
{
	//int A[] = {2, 3, -2, 4, 3};
	int A[] = {2, -5, -2, -4, 3};
	//int A[] = {2, 3, -2, 4, 3, -1, 100};
	//int A[] = {-2};
	//int A[] = {0};
	
	Solution s;
	cout << s.maxProduct(A, 5) << endl;
}
