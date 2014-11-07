#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
	int longestValidParentheses(string s) {
		int result = 0;
		stack<int> stk;
		for (int i=0; i<s.length(); i++) {
			if (s[i]==')' && !stk.empty() && s[stk.top()]=='(') {
				stk.pop();
				if (stk.empty()) result = i + 1;
				else result = max(result, i-stk.top());
			}
			else stk.push(i);
		}
		return result;
	}
};

int main()
{
	//string s = "()(()())";
	//string s = ")())(()())";
	string s = ")(()(()(((())(((((()()))((((()()(()()())())())()))()()()())(())()()(((()))))()((()))(((())()((()()())((())))(())))())((()())()()((()((())))))((()(((((()((()))(()()(())))((()))()))())";
	
	Solution S;
	cout << S.longestValidParentheses(s) << endl;
}
