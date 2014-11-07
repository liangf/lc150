#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;
/*
class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		int result = 0;
		int	solution = INT_MAX;
		help(triangle, 0, 0, result, solution);
		return solution;
	}
	void help(vector<vector<int> > &triangle, int row, int col,
				int &result, int &solution) {
		//cout << row << "," << col << endl;
		if (row==triangle.size() || col==triangle[row].size()) {
			if (result < solution) solution = result;
			return;
		}
		result += triangle[row][col];

		help(triangle, row+1, col, result, solution);
		help(triangle,row+1, col+1, result, solution);
		result -= triangle[row][col];
		//cout <<row<< ","<<col<<" "<< triangle[row][col] << " ";
		//cout << result << " "<< solution <<endl;
	}
};*/

class Solution {
public:
	int minimumTotal(vector<vector<int> > &triangle) {
		if (triangle.size() == 0) return 0;
		
		int mintotal = INT_MAX;	
		vector<int> row;
		row = triangle[0];
		row.resize( triangle[triangle.size()-1].size() );
			
		for (int i=1; i<triangle.size(); i++) {
			for (int j=triangle[i].size()-1; j>=0; j--) {
				if (j == 0) row[j] = row[j] + triangle[i][j];
				else if (j == triangle[i].size()-1) row[j] = row[j-1] + triangle[i][j];
				else row[j] = min(row[j-1], row[j]) + triangle[i][j];
			}
		}
		for (int i=0; i<row.size(); i++) {
			if (row[i] < mintotal) mintotal = row[i];	
		}
		return mintotal;
	}
};

int main()
{
	vector<vector<int> >triangle;
	vector<int> vec;
	vec.push_back(-1);	
	triangle.push_back(vec);
	vec.clear();

	vec.push_back(2);	
	vec.push_back(3);	
	triangle.push_back(vec);
	vec.clear();
		
	vec.push_back(1);	
	vec.push_back(-1);	
	vec.push_back(-3);	
	triangle.push_back(vec);
	vec.clear();
/*
	vector<vector<int> >triangle;
	vector<int> vec;
	vec.push_back(2);	
	triangle.push_back(vec);
	vec.clear();

	vec.push_back(3);	
	vec.push_back(4);	
	triangle.push_back(vec);
	vec.clear();
		
	vec.push_back(6);	
	vec.push_back(5);	
	vec.push_back(7);	
	triangle.push_back(vec);
	vec.clear();

	vec.push_back(4);	
	vec.push_back(1);	
	vec.push_back(8);	
	vec.push_back(3);	
	triangle.push_back(vec);
	vec.clear();
*/

	Solution s;
	cout << s.minimumTotal(triangle) << endl;
}
