#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if (obstacleGrid.size() == 0) return 0;	
		int row = obstacleGrid.size();
		int col = obstacleGrid[0].size(); 
		vector<vector<int> > paths(row, vector<int>(col, 0));
		paths[0][0] = obstacleGrid[0][0]==1 ? 0 : 1;

		for (int i=1; i<row; i++) {
			if (obstacleGrid[i][0]==1 || paths[i-1][0]==0) paths[i][0] = 0;
			else paths[i][0] = 1;
		}
		for (int j=1; j<col; j++) {
			if (obstacleGrid[0][j]==1 || paths[0][j-1]==0) paths[0][j] = 0;
			else paths[0][j] = 1;
		}
		for (int i=1; i<row; i++) {
			for (int j=1; j<col; j++) {
				if (obstacleGrid[i][j] == 1) paths[i][j] = 0;
				else paths[i][j] = paths[i-1][j] + paths[i][j-1];	
			}
		}
		return paths[row-1][col-1];
	}
};

int main()
{
	vector<vector<int> > grid;
	vector<int> vec;
/*
	vec.push_back(0);	
	vec.push_back(0);	
	vec.push_back(0);	
	grid.push_back(vec);
	vec.clear();

	vec.push_back(0);	
	vec.push_back(1);	
	vec.push_back(0);	
	grid.push_back(vec);
	vec.clear();

	vec.push_back(0);	
	vec.push_back(0);	
	vec.push_back(0);	
	grid.push_back(vec);
	vec.clear();*/
	
	vec.push_back(0);
	vec.push_back(1);
	grid.push_back(vec);
	Solution s;
	cout << s.uniquePathsWithObstacles(grid) << endl;
}
