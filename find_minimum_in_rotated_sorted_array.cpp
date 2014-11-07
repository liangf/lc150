#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int findMin(vector<int> &num) {
		int left = 0, right = num.size()-1;
		int mid = (left+right)/2;
		if (num[left] <= num[right]) return num[left];
		while (left < right) {
			mid = (left+right)/2;
			if (num[mid] > num[right]) left = mid + 1;
			else right = mid;
		}
		return num[left];
	}
};


int main()
{
	vector<int> num;
	num.push_back(4);
	num.push_back(5);
	num.push_back(6);
	num.push_back(7);
	num.push_back(0);
	num.push_back(1);
	num.push_back(2);

	Solution s;
	cout << s.findMin(num) << endl;
}
