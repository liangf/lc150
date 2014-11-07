#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int max_len = 0;
		int i = 0, j;	
		while (i < s.length()) {
			//cout << "i:" << s[i] << endl;
			vector<int> map(256, -1);
			int len = 0;
			for (j=i; j<s.length(); j++) {
				if ( map[ s[j] ] < 0 ) {
					map[ s[j] ] = j;
					len++;
				}
				else break;
			}
			if (len > max_len) max_len = len;
			if (j >= s.length()) break;
			//cout << "j:" << j << " "<< s[j] << " " << map[s[j]] <<endl;
			//cout << "len:" << len << endl;
			i = map[ s[j] ] + 1;
		}
		return max_len;
	}
};

int main()
{
	//string s = "abcabcbb";
	//string s = "wlrbbmqbhcdarzowkkyhiddqscdxrjmowfrxsjybldbefsarcbynecdyggxxpklorellnmpapqfwkhopkmco";
	//string s = "hnwnkuewhsqmgbbuqcljjivswmdkqtbxixmvtrrbljptnsnfwzqfjmafadrrwsofsbcnuvqhffbsaqxwpqcac";
	string s = "qopubjguxhxdipfzwswybgfylqvjzhar";
	Solution S;
	cout << S.lengthOfLongestSubstring(s) << endl;
}
