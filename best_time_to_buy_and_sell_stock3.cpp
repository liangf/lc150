#include <iostream>
#include <vector>
#include <climits>
using namespace std;


class Solution {
public:
	int maxProfit(vector<int> &prices) {
		vector<int> max_left(prices.size(), 0);
		vector<int> max_right(prices.size(), 0);
		int min = INT_MAX, max = -INT_MAX;
		int max1 = -INT_MAX, max2 = - INT_MAX;
		int max_profit = 0;
		for (int i=0; i<prices.size(); i++) {
			if (prices[i] < min) min = prices[i];
			max_left[i] = prices[i] - min;	
			if (max_left[i] > max1) max1 = max_left[i];
			max_left[i] = max1;
		}	
		//print(max_left);

		for (int i=prices.size()-1; i>=0; i--) {
			if (prices[i] > max) max = prices[i];
			max_right[i] = max - prices[i];	
			if (max_right[i] > max2) max2 = max_right[i];
			max_right[i] = max2;
		}
		//print(max_right);

		for (int i=0; i<prices.size(); i++) {
			if (max_left[i]+max_right[i] > max_profit) 
				max_profit = max_left[i] + max_right[i];	
		}
		return max_profit;
	}
	void print(vector<int> &vec) {
		for (int i=0; i<vec.size(); i++) {
			cout << vec[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	vector<int> prices;
	prices.push_back(0);
	prices.push_back(3);
	prices.push_back(2);
	prices.push_back(4);
	prices.push_back(1);
	prices.push_back(3);
	prices.push_back(0);
	
	Solution s;
	cout << s.maxProfit(prices) << endl;
}
