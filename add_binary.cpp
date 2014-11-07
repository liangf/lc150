#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string addBinary(string a, string b) {
		string s = a.length()>b.length() ? a : b;
		int add = 0;
		int i = a.length() - 1;
		int j = b.length() - 1;
		int k = max(i, j);

		while (i>=0 || j>=0) {
			int ai = i>=0 ? a[i]-'0' : 0;
			int bi = j>=0 ? b[j]-'0' : 0;
		cout << ai << " " << bi << endl;
			int sum = (ai+bi+add)%2;
			add = (ai+bi+add)/2;
			s[k] = sum + '0';
			i--;
			j--;
			k--;
		}
		if (add == 1) s = "1" + s;
		return s;
	}
};


int main()
{
	string a = "0";
	string b = "1";

	Solution S;
	string s = S.addBinary(a, b);
	cout << s << endl;
}
