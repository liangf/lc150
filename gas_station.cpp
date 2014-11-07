#include <iostream>
#include <vector>
using namespace std;

/*
// this is O(n*n) time cost
class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		for (int i=0; i<gas.size(); i++) {
			int remain = 0;
			int index = i, j = i;
			for (; j<gas.size()+i; j++) {
				if (j >= gas.size()) index = j - gas.size();
				remain = remain + gas[index] - cost[index];
				//cout << i << "remain:" << remain << endl;
				if (remain < 0) break;
				index++;
			}
			if (j == gas.size()+i) return i;
		}
		return -1;
	}
};*/

class Solution {
public:
	int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
		int remain[gas.size()];
		for (int i=0; i<gas.size(); i++) {
			remain[i] = gas[i] - cost[i];
		}
		
		int sum = 0, sum2 = 0;
		int index = 0;
		for (int i=0; i<gas.size(); i++) {
			sum = sum + remain[i];
			sum2 = sum2 + remain[i];
			if (sum2 < 0) {
				index = i + 1;
				sum2 = 0;
			}		
		}
		if (sum < 0) return -1;
		else return index;
	}
};

int main()
{
	vector<int> gas;
	gas.push_back(1);
	gas.push_back(3);
	gas.push_back(2);
	
	vector<int> cost;
	cost.push_back(1);
	cost.push_back(2);
	cost.push_back(3);

	Solution s;
	cout << s.canCompleteCircuit(gas, cost) << endl;
}
