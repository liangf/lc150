#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <fstream>
using namespace std;
/*
class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> result;
		if (S.length()==0 || L.size()==0) return result;
		unordered_map<string, int> umap;
		for (int i=0; i<L.size(); i++) {
			if (umap.find(L[i]) != umap.end()) umap[ L[i] ]++;
			else umap[ L[i] ] = 1;
		}
		int m = L[0].length();
	for (int j=0; j<m; j++) {
		unordered_map<string, int> umap2 = umap;
		int left = j, count = 0;
		for (int i=j; i<=(int)S.length()-m; ) {
			string s_i_m = S.substr(i, m); 
			if (umap2.find(s_i_m)==umap2.end()) {
				count = 0;
				umap2 = umap;
				i += m;
				left = i;
				continue;
			}
			umap2[s_i_m]--;
			if (umap2[s_i_m] >= 0) {
				count++;
				i += m;
			}
			else {
				if (S.substr(left, m) == S.substr(i, m)) {
					umap2[S.substr(left, m)]++;
					left += m;
					i += m;
				}
				else {
					count = 0;
					umap2 = umap;
					left = i;
				}	
			}
			if (count == L.size()) {
				count--;
				umap2[S.substr(left, m)]++;
				result.push_back(left);
				left += m;
			}
		}	
	}
		return result;
	}
};*/

class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> result;
		if (S.length()==0 || L.size()==0) return result;
		unordered_map<string, int> umap;
		for (int i=0; i<L.size(); i++) {
			if (umap.find(L[i]) != umap.end()) umap[ L[i] ]++;
			else umap[ L[i] ] = 1;
		}
		int m = L[0].size();
		for (int i=0; i<m; i++) {
			unordered_map<string, int> umap2;
			int count = 0, left = i;
			for (int j=i; j<=(int)S.length()-m; j+=m) {
				string str = S.substr(j, m);
				if (umap.find(str) != umap.end()) {

					if (umap2.find(str) != umap2.end()) umap2[str]++;
					else umap2[str] = 1;
					if (umap2[str] <= umap[str]) count++;
					else {
						//while (umap2[str] > umap[str]) {
						//	string temp = S.substr(left, m);
						//	umap2[temp]--;
						//	if (umap2[temp] < umap[temp]) count--;
						//	left += m;
						//}
						if (S.substr(left, m) == S.substr(j, m)) {
							string temp = S.substr(left, m);
							umap2[temp]--;
							left += m;
						}
						else {
							count = 1;
							umap2[S.substr(left, m)]++;
							left = i;
						}	
					}
					if (count == L.size()) {
						result.push_back(left);
						string temp = S.substr(left, m);
						umap2[temp]--;
						count--;
						left += m;
					}
				}
				else {
					umap2.clear();
					count = 0;
					left = j + m;

				}
			}
		}
		return result;
	}
};
/*
class Solution {
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> result;
		if (S.length()==0 || L.size()==0) return result;
		unordered_map<string, int> umap;
		for (int i=0; i<L.size(); i++) {
			if (umap.find(L[i]) != umap.end()) umap[ L[i] ]++;
			else umap[ L[i] ] = 1;
		}
		int m = L[0].size();
		for (int i=0; i<m; i++) {
			unordered_map<string, int> umap2 = umap;
			int count = 0, left = i;
			for (int j=i; j<=(int)S.length()-m; j+=m) {
				string str = S.substr(j, m);
				if (umap.find(str) != umap.end()) {
					umap2[str]--;
					if (umap2[str] >= 0) count++;
					else {
						if (S.substr(left, m) == S.substr(j, m)) {
							string temp = S.substr(left, m);
							umap2[temp]++;
							left += m;
						}
						else {
							count = 1;
							umap2[S.substr(left, m)]--;
							left = i;
						}	
					}
					if (count == L.size()) {
						result.push_back(left);
						string temp = S.substr(left, m);
						umap2[temp]++;
						count--;
						left += m;
					}
				}
				else {
					//umap2.clear();
					umap2 = umap;
					count = 0;
					left = j + m;
				}
			}
		}
		return result;
	}
};*/

int main()
{
/*	string S = "barfoothefoobarman";
	vector<string> L;
	L.push_back(string("foo"));
	L.push_back(string("bar"));
*/
/*
	string S = "abababcdabcdab";
	vector<string> L;
	L.push_back(string("ab"));
	L.push_back(string("cd"));
	L.push_back(string("ab"));
*/

/*	string S = "aaabbbc";
	vector<string> L;
	L.push_back(string("a"));
	L.push_back(string("a"));
	L.push_back(string("b"));
	L.push_back(string("b"));
	L.push_back(string("c"));
*/
/*
	string S = "abaababbaba";
	vector<string> L;
	L.push_back(string("ab"));
	L.push_back(string("ba"));
	L.push_back(string("ab"));
	L.push_back(string("ba"));
*/
	//string S = "mississippi";
	//vector<string> L;
	//L.push_back(string("mississippis"));
/*
	string S = "bcaadbc";
	vector<string> L;
	L.push_back(string("a"));
	L.push_back(string("b"));
	L.push_back(string("c"));
	L.push_back(string("d"));
*/
/*
	string S = "abababab";
	vector<string> L;
	L.push_back(string("a"));
	L.push_back(string("b"));
	L.push_back(string("a"));
*/

	string S;
	vector<string> L;
 	ifstream myReadFile;
 	myReadFile.open("data.txt");
 	if (myReadFile.is_open()) {
 		while (!myReadFile.eof()) {
    		myReadFile >> S;
 		}
	}
	//cout << S << endl;
	string S2;
 	ifstream myReadFile2;
 	myReadFile2.open("data2.txt");
 	if (myReadFile2.is_open()) {
 		while (!myReadFile2.eof()) {
    		myReadFile2 >> S2;
 		}
	}
	//cout << S2 << endl;
	int i = S2.find('"');
	while (i < S2.length()) {
		int j = S2.find('"', i+1);
		if (j-i > 2) L.push_back(S2.substr(i+1, j-i-1));
		if (j == string::npos) j = S2.length();
		i = j;
	}
	myReadFile.close();	
	myReadFile2.close();	
	//for (int k=0; k<L.size(); k++) {
	//	cout << L[k] << ",";
	//}	cout << endl;

	Solution s;

	vector<int> result = s.findSubstring(S, L);
	for (int i=0; i<result.size(); i++) {
		cout << result[i] << endl;
	}

}
