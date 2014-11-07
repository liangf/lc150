#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

bool mysort(Interval a, Interval b) {
	return a.start < b.start;
}
class Solution {
public:
	vector<Interval> merge(vector<Interval> &intervals) {
		Interval newInterval(INT_MIN, INT_MIN);
		vector<Interval> result;
		sort(intervals.begin(), intervals.end(), mysort);
		for (int i=0; i<intervals.size(); i++) {
			if (intervals[i].end < newInterval.start) {
				result.push_back(intervals[i]);
			}
			else if (intervals[i].start > newInterval.end) {
				result.push_back(newInterval);
				newInterval = intervals[i];
			}
			else {
				newInterval.start = min(newInterval.start, intervals[i].start);
				newInterval.end = max(newInterval.end, intervals[i].end);
			}

		}
		result.push_back(newInterval);
		result.erase(result.begin());
		return result;
	}
};


int main() 
{
	vector<Interval> intervals;
/*	intervals.push_back(Interval(1, 3));
	intervals.push_back(Interval(2, 6));
	intervals.push_back(Interval(8, 10));
	intervals.push_back(Interval(15, 18));*/

	intervals.push_back(Interval(2, 3));
	intervals.push_back(Interval(4, 5));
	intervals.push_back(Interval(6, 7));
	intervals.push_back(Interval(8, 9));
	intervals.push_back(Interval(1, 10));

	Solution s;
	intervals = s.merge(intervals);
	for (int i=0; i<intervals.size(); i++) {
		cout << intervals[i].start << "," << intervals[i].end << endl;
	}
}
