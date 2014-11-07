#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int> &num) {
		for (int i=num.size()-2; i>=0; i--) {
			if (num[i] < num[i+1]) {
				for (int j=num.size()-1; j>i; j--) {
					if (num[j] > num[i]) {
						swap(num[i], num[j]);
						break;
					}
				}
				reverse(num.begin()+i+1, num.end());
				return;
			}
		}	
		reverse(num.begin(), num.end());
	}
};

int main()
{
	vector<int> num;
/*	num.push_back(1);
	num.push_back(2);
	num.push_back(3);*/
	
/*	num.push_back(3);
	num.push_back(2);
	num.push_back(1);*/

	num.push_back(1);
	num.push_back(1);
	num.push_back(3);

	Solution s;
	s.nextPermutation(num);
	for (int i=0; i<num.size(); i++) {
		cout << num[i] << " ";
	}
	cout << endl;
}
