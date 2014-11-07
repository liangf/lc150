#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <climits>
#include <cstdlib>
using namespace std;

class Solution {
public:
	int evalRPN(vector<string> &tokens) {
		stack<int> nums;
		int result = INT_MAX;

		for (int i=0; i<tokens.size(); i++) {
			if (tokens[i]=="+" || tokens[i]=="-" || 
				tokens[i]=="*" || tokens[i]=="/") {
				int a = nums.top();
				nums.pop();
				int b = nums.top();
				nums.pop();
				if (tokens[i]== "+") result = b + a;
				if (tokens[i]== "-") result = b - a;
				if (tokens[i]== "*") result = b * a;
				if (tokens[i]== "/") result = b / a;
				nums.push(result);
				//cout << b << tokens[i] << a << "=" << result << endl;
			}	
			else nums.push( atoi(tokens[i].c_str()) );
		}		
		return nums.top();
	}
/*	int atoi(string& s) {
		int sum = 0;
		for (int i=0; i<s.length(); i++) {
			sum = 10*sum + s[i]-'0';
		}	
		return sum;
	}*/
};

int main()
{
	vector<string> tokens;
/*
	tokens.push_back("4");
	tokens.push_back("13");
	tokens.push_back("5");
	tokens.push_back("/");
	tokens.push_back("+");
*/	
	tokens.push_back("4");
	tokens.push_back("-13");
	tokens.push_back("+");

	Solution s;
	//string str = "123";
	//cout << s.atoi(str) << endl;
	cout << s.evalRPN(tokens) << endl;
}
