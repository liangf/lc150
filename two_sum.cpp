#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
/*
class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> result;
		for (int i=0; i<numbers.size(); i++) {
			for (int j=i+1; j<numbers.size(); j++) {
				if (numbers[i]+numbers[j] == target) {
					result.push_back(i+1);
					result.push_back(j+1);
					return result;	
				}
			}
		}
		return result;
	}
};*/

class Solution {
public:
	vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> result;
		unordered_map<int, int> umap;
		for (int i=0; i<numbers.size(); i++) {
			umap[ numbers[i] ] = i + 1;
		}
		for (int i=0; i<numbers.size(); i++) {
			if (umap.find(target-numbers[i]) != umap.end()) {
				if (i+1 != umap[target-numbers[i]]) {
					if (i+1 > umap[target-numbers[i]]) {
						result.push_back(umap[target-numbers[i]]);
						result.push_back(i+1);
					}
					result.push_back(i+1);
					result.push_back(umap[target-numbers[i]]);
					return result;
				}
			}
		}
		return result;
	}
};
int main()
{
	vector<int> numbers;
	numbers.push_back(2);
	numbers.push_back(2);
	numbers.push_back(1);

	Solution s;
	vector<int> result = s.twoSum(numbers, 4);
	cout << result[0] << " " << result[1] << endl;
}
