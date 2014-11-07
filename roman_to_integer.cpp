#include <iostream>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
	int romanToInt(string s) {
		map<char, int> romans;
		romans['I'] = 1;
		romans['V'] = 5;
		romans['X'] = 10;
		romans['L'] = 50;
		romans['C'] = 100;
		romans['D'] = 500;
		romans['M'] = 1000;
		
		int sum = 0;
		int old = 0;
		int cur = 0;
		for (int i=0; i<s.length(); i++) {
			char c = s[i];
			old = cur;
			cur = romans[c];
			if (old < cur) sum = sum + cur - 2*old;
			else sum = sum + cur;	
		}
		return sum;
	}
};

int main()
{
	string s;
	//s = "CXCIX";
	//s = "MMMCCCXXXIII";
	//s = "MCDXXXVII";
	s = "MDCCCLXXX";
	Solution S;
	cout << S.romanToInt(s) << endl;

}
