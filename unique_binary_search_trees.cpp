#include <iostream>

using namespace std;


class Solution {
public:
	int numTrees(int n) {
		int count[n+1];

		for (int i=0; i<n+1; i++) count[i] = 0;
		count[0] = 1;
		count[1] = 1;

		if (n == 0) return count[0];
		if (n == 1) return count[1];

		for (int i=2; i<=n; i++) {
			for (int j=0; j<=i-1; j++) {
				count[i] += count[j] * count[i-1-j];
			}
		}
		return count[n];
	}
};


int main()
{
	Solution s;
	cout << s.numTrees(2) << endl;
}
