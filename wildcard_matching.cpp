#include <iostream>
#include <cstring>
using namespace std;

class Solution {
public:
	bool isMatch(const char *s, const char *p) {
	
		for (int i=0; i<strlen(s); i++) {
			if (s[i] != p[i]) {
				if (p[i] == '?') continue;
				else if (p[i] == '*') {

				}
				else return false;
			}
			else continue;
		}	
	}
};

int main()
{
 	int a;
	cin >> a;
	cout << a << endl;
}
