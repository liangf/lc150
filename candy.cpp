#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int candy(vector<int> &ratings) {
		int result = 0;
		vector<int> left(ratings.size(), 1);
		vector<int> right(ratings.size(), 1);
		for (int i=1; i<ratings.size(); i++) {
			if (ratings[i] > ratings[i-1]) left[i] = left[i-1] + 1;
			//if (ratings[i] == ratings[i-1]) left[i] = left[i-1];
		}
		for (int i=ratings.size()-2; i>=0; i--) {
			if (ratings[i] > ratings[i+1]) right[i] = right[i+1] + 1;
			//if (ratings[i] == ratings[i+1]) right[i] = right[i+1];
		}
		for (int i=0; i<ratings.size(); i++) {
			result += max(left[i], right[i]);
		}	
		return result;
	}
};

int main()
{
	vector<int> ratings;
	ratings.push_back(5);
	ratings.push_back(3);
	ratings.push_back(4);
	ratings.push_back(4);
	ratings.push_back(3);
	ratings.push_back(2);

	Solution s;
	cout << s.candy(ratings) << endl;
}
