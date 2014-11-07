#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	int largestRectangleArea(vector<int> &height) {
		height.push_back(0);
		stack<int> s;
		int max_area = 0;
		for (int i=0; i<height.size(); i++) {
			if (s.empty() || height[i]>height[s.top()]) s.push(i);
			else {
				int tmp = s.top();
				s.pop();
				max_area = max(max_area, (s.empty()?i:i-s.top()-1)*height[tmp]);
				i--;
			}
		}
		return max_area;
	}
};


int main()
{
	vector<int> height;
	height.push_back(2);
	height.push_back(1);
	height.push_back(5);
	height.push_back(6);
	height.push_back(2);
	height.push_back(3);

	Solution s;
	cout << s.largestRectangleArea(height) << endl;
}
