#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		string result = "";
		reverse(num1.begin(), num1.end());
		reverse(num2.begin(), num2.end());
		string base = "";
		for (int i=0; i<num2.length(); i++) {
			//cout << num1 << "*" << num2[i]<< endl;
			string s = multiply(num1, num2[i]);
			if (s != "0") s.insert(0, base);
			result = add(s, result);
			//cout << result << endl;
			base.push_back('0');
		}
		reverse(result.begin(), result.end());
		return result;
	}
	string multiply(string s, char c) {
		if (c == '0') return "0";
		string result = "";
		int a = c - '0';
		int carry = 0;
		for (int i=0; i<s.length(); i++) {
			int b = s[i] - '0';
			int sum = a*b + carry;
			carry = sum>=10 ? sum/10 : 0;
			result.push_back('0' + sum%10);
		}
		if (carry > 0) result.push_back('0' + carry);
		return result;
	}
	string add(string s1, string s2) {
		//cout << s1 << "+" << s2 << endl;
		int i1 = 0, i2 = 0;
		string result = "";
		int carry = 0;
		while (i1<s1.length() || i2<s2.length()) {
			int a = i1<s1.length()?s1[i1]-'0':0;
			int b = i2<s2.length()?s2[i2]-'0':0;
			int sum = a + b + carry;
			//cout << a << " " << b << " " << sum << endl;
			carry = sum>=10 ? sum/10 : 0;
			result.push_back('0' + sum%10);	
			i1++; i2++;
		}
		if (carry > 0) result.push_back('0'+carry);
		return result;
	}
};

int main()
{
	//string num1 = "9";
	//string num2 = "99";
	
	string num1 = "123";
	string num2 = "0";

	//string num1 = "123";
	//string num2 = "456";

	//string num1 = "123456789";
	//string num2 = "987654321";

	//string num1 = "0";
	//string num2 = "52";

	//string num1 = "52";
	//string num2 = "60";
	Solution s;
	cout << s.multiply(num1, num2) << endl;
	//cout << s.add("", "");
}
