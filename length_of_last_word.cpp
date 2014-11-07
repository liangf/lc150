#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
	int lengthOfLastWord(const char *s) {
		int len = strlen(s), i = len - 1, count = 0;
		if (len == 0) return 0;
		while ( ' ' == s[i] ) {
			i--;
		}

		for (; i>=0; i--) {
			if (' ' == s[i]) return count;
			count++;
		}
		return count;
	}
};

int main()
{
	//char c[12] = "hello world";
	//char c[2] = "h";
	char c[9] = "h  ab   ";

	Solution s;
	cout << s.lengthOfLastWord(c) << endl;
}
