#include <iostream>
#include <climits>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;


class Solution {
public:
	int threeSumClosest(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		int min = INT_MAX, result;
		int len = num.size();
		for (int left=0; left<len-2; left++) {
			int right = len - 1;	
			for (int mid = left+1; mid<right; ) {
				int sum = num[left] + num[mid] + num[right];
				if (sum == target) { return target; }
				else if (sum < target) {
					if (abs(target-sum) < min) {
						min = abs(target-sum);
						result = sum;
					}
				//cout<<left<<" "<<mid<<" "<<right<<":"<<result<<endl;
					mid++;
				}
				else {
					if (abs(target-sum) < min) {
						min = abs(target-sum);
						result = sum;
					}
				//cout<<left<<" "<<mid<<" "<<right<<":"<<result<<endl;
					right--;
				}
			}
			while (left<right-1 && num[left]==num[left+1]) left++;
		}
		return result;
	}
};


int main()
{
	vector<int> num;
/*	num.push_back(-1);	
	num.push_back(2);	
	num.push_back(1);	
	num.push_back(-4);	*/

	num.push_back(-3);	
	num.push_back(-2);	
	num.push_back(-5);	
	num.push_back(3);	
	num.push_back(-4);	

	Solution s;
	//cout << s.threeSumClosest(num, 1) << endl;
	cout << s.threeSumClosest(num, -1) << endl;
}
