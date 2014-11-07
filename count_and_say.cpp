#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	string countAndSay(int n) {
		if (n <= 0) return "";
		string pre = "";
		string result = "1";
		for (int i=2; i<=n; i++) {
			int count = 1;
			pre = result;
			result = "";
			for (int j=1; j<pre.length(); j++) {
				if (pre[j] != pre[j-1]) {
					result.push_back(count+'0');
					result += pre[j-1];
					count = 1;
				}
				else count++;
			}
			result.push_back(count+'0');
			result += pre[pre.length()-1];
		}	
		return result;
	}
};

int main()
{
	Solution s;
	cout << s.countAndSay(4) << endl;
}
