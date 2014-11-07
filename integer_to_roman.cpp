#include <iostream>
#include <map>
#include <vector>
#include <cmath>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string s;
		map<int, char> romans;
		int num_i;

		vector<int> digits;
		while (num) {
			digits.push_back(num%10);
			num = num/10;
		}	
		for (int i=digits.size()-1; i>=0; i--) {
			num_i = digits[i]*pow(10, i);
			if (num_i == 4) s += "IV"; 
			else if (num_i == 9) s += "IX";
			else if (num_i == 40) s += "XL";
			else if (num_i == 90) s += "XC";
			else if (num_i == 400) s += "CD";
			else if (num_i == 900) s += "CM";
			else {
				s += getRoman(digits[i], i);	
			}
		}
		return s;
	}

	string getRoman(int base, int k) {
		char c1[] = {'I', 'X', 'C', 'M'};
		char c2[] = {'V', 'L', 'D'};
		string s = "";
	
		if (base/5 > 0) {
			s.append(1, c2[k]);
			base = base - 5;
		}
		s.append(base, c1[k]);

		return s;
	}
};


int main()
{
	Solution s;
	cout << s.intToRoman(3333) << endl;
}
