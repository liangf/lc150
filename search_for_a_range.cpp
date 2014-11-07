#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		vector<int> result;
		int left = 0, right = n-1;
		int min = -1, max = -1;
		while (left <= right) {
			int mid = (left+right)/2;
			//cout << left << " " << right << " " << mid << endl;
			if (left == right) {
				if (target == A[mid]) {
					min = mid;
					max = mid;
				}
				else if (A[min]<target && target<A[max]) {}
				else {
					min = -1;
					max = -1;
				}
				break;
			}
			if (target == A[mid]) {
				if (A[left] < target) left = left+1;
				if (A[right] > target) right = right-1;
				if (A[left]==target && A[right]==target) {
					min = left;
					max = right;
					break;
				}
			}
			else if (target < A[mid]) {
				min = left;
				max = right;
				right = mid-1;
			}
			else {
				min = left;
				max = right;
				left = mid + 1;
			}
		}
		if (left>right) {
			min = -1;
			max = -1;
		}
		result.push_back(min);
		result.push_back(max);
		return result;
	}
};*/

class Solution {
public:
	vector<int> searchRange(int A[], int n, int target) {
		int left = 0, right = n-1;
		vector<int> result(2, -1);
		while (left <= right) {
			int mid = (left+right)/2;
			if (target == A[mid]) {
				if (A[left] < target) left = left + 1;
				if (A[right] > target) right = right -1;	
				if (A[left]==target && A[right]==target) {
					result[0] = left;
					result[1] = right;	
					break;
				}
			}
			else if (target < A[mid]) right = mid - 1;
			else left = mid + 1;
		}	
		return result;
	}
};

int main()
{
	//int A[] = {1, 3, 5, 7, 9};
	int A[] = {5, 7, 7, 8, 8, 10};
	//int A[] = {1};
	Solution s;
	vector<int> result = s.searchRange(A, 6, 12);
	cout << result[0] << ", " << result[1] << endl;
}
