#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		int A[word1.length()+1][word2.length()+1];
		for (int i=0; i<=word1.length(); i++) {
			for (int j=0; j<=word2.length(); j++) {
				A[i][j] = 0;
			}
		}
		for (int i=0; i<=word1.length(); i++) {
			A[i][0] = i;
		}
		for (int j=0; j<=word2.length(); j++) {
			A[0][j] = j;
		}
		for (int i=1; i<=word1.length(); i++) {
			for (int j=1; j<=word2.length(); j++) {
				if (word1[i-1] == word2[j-1]) A[i][j] = A[i-1][j-1];
				else {
					A[i][j] = min(min(A[i-1][j], A[i][j-1]), A[i-1][j-1]) + 1;	
				}
			}
		}
		return A[word1.length()][word2.length()];
	}
};

int main()
{
	//string s1 = "rabbit";
	//string s2 = "rabbbit";
	
	//string s1 = "bca";
	//string s2 = "abc";
	
	string s1 = "";
	string s2 = "a";

	Solution s;
	cout << s.minDistance(s1, s2) << endl;
}
