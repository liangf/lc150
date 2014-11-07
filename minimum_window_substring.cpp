#include <iostream>
#include <string>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
	string minWindow(string S, string T) {
		unordered_map<char, int> umap;
		for (int i=0; i<T.length(); i++) {
			if (umap.find(T[i]) == umap.end()) umap[ T[i] ] = 1;
			else umap[ T[i] ]++;
		}
		int count = 0, start = 0, minSt = 0, minLen = INT_MAX;
		for (int i=0; i<S.length(); i++) {
			if (umap.find(S[i]) == umap.end()) continue;
			umap[ S[i] ]--;
			if ( umap[ S[i] ] >=0 ) count++;
			while ( count == T.length() ) {
				if (i-start+1 < minLen) {
					minSt = start;
					minLen = i-start+1; 
				}
				if (umap.find(S[start]) != umap.end()) {
					umap[ S[start] ]++;
					if (umap[ S[start] ]>0) count--;
				}
				start++;
			}	
		}
		if (minLen > S.length()) return "";
		return S.substr(minSt, minLen);
	}
};

int main()
{
	//string S = "ADOBECODEBANC";
	//string T = "ABC";

	//string S = "abbabaa";
	//string T = "aab";

	//string S = "a";
	//string T = "aa";
	
	string S = "a";
	string T = "a";

	Solution s;
	cout << s.minWindow(S, T) << endl;
}
