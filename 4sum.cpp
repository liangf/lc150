#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int> > fourSum(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		vector<vector<int> > solution;
		for (int i=0; i<num.size(); i++) {
			for (int j=i+1; j<num.size(); j++) {
				int start = j+1, end = num.size()-1;
				while (start < end) {
					int sum = num[i]+num[j]+num[start]+num[end];
					if (sum == target) {
						vector<int> result;
						result.push_back(num[i]);	
						result.push_back(num[j]);	
						result.push_back(num[start]);	
						result.push_back(num[end]);	
						solution.push_back(result);	
						while (start<end && num[start]==num[start+1]) start++;
						start++;
						while (end>start && num[end]==num[end-1]) end--;
						end--;
					}
					else if (sum < target) start++;
					else end--;
				}
				while (j<num.size() && num[j]==num[j+1]) j++;
			}
			while (i<num.size() && num[i]==num[i+1]) i++;
		}
		return solution;
	}
};

int main()
{
	vector<int> num;
	num.push_back(1);
	num.push_back(0);
	num.push_back(-1);
	num.push_back(0);
	num.push_back(-2);
	num.push_back(2);

	Solution s;
	vector<vector<int> > sol = s.fourSum(num, 0);
	for (int i=0; i<sol.size(); i++) {
		for (int j=0; j<sol[i].size(); j++) {
			cout << sol[i][j] << " ";
		}
		cout << endl;
	}
}
