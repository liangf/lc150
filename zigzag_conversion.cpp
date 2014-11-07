#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string convert(string s, int nRows) {
		if (nRows <= 1) return s;
		string result = "";
		for (int i=0; i<nRows; i++) {
			for (int j=i; j<s.length(); j+=2*nRows-2) {
				//cout << i << " " << j << endl;
				result.push_back(s[j]);
				if (i!=0 && i!=nRows-1 && j+2*nRows-2-2*i<s.length()) {
					//result.push_back(s[j+2*nRows-2-2*i]);
					result += s[j+2*nRows-2-2*i];
					//cout << i << "*" << j+2*nRows-2-2*i << endl;
				}
			}
		}
		return result;
	}
};


int main()
{
	Solution s;
	//cout << s.convert("0123456789abcd", 4) << endl;
	cout << s.convert("0123456789abcd", 3) << endl;
}
