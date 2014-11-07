#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int> > &grid) {
		
	}
	void travel(vector<vector<int> > &grid,
				vector<int> &res, int m, int n) {
		if (m+1==grid.size() && n+1==grid[0].size()) {
			return;
		}
		if (m < grid.size()) {
			res.push_back(grid[m][n]);
			travel(grid, res, m+1, n);
			res.pop_back();
		}
		if (n < grid[0].size()) {
			res.push_back(grid[m][n]);
			trabel(grid, res, m, n+1);
			res.pop_back();
		}
	}
};

int main()
{

}
