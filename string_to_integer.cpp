#include <iostream>
#include <cstring>
#include <climits>
using namespace std;

class Solution {
public:
	int atoi(const char *str) {
		int flag = 1;
		int sum = 0;
		int i=0;
		for (; i<strlen(str); i++) {
			if (str[i] != ' ') break;
		} 
		if (str[i]=='+' || str[i]=='-') {
			if (str[i] == '-') flag = -1;
			i++;
		}
		//cout << i << " " << str[i] << endl;
		for (; i<strlen(str); i++) {
			if (str[i]>'9' || str[i]<'0') break;
			if (sum>INT_MAX/10 || (sum==INT_MAX/10 && str[i]>'7')) {
				if (flag > 0) return INT_MAX;
				else return INT_MIN;
			}
			sum = sum*10 + str[i] - '0';		
		}
		return sum * flag;
	}
};

int main()
{
	//char str[] = "12345";
	//char str[] = "0";
	//char str[] = "+1";
	//char str[] = "+-2";
	//char str[] = "        -2147483647";
	//char str[] = "-0012a42";
	//char str[] = "+0 123";
	char str[] = "12 123";
	//char str[] = " b1112333";
	
	Solution s;
	cout << s.atoi(str) << endl;
}
