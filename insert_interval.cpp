#include <iostream>
#include <vector>
using namespace std;

struct Interval {
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};
/*
class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval> result;
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
		return result;
	}
};*/

class Solution {
public:
	vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
		vector<Interval>::iterator it = intervals.begin();
		while (it != intervals.end()) {
			if ((*it).end < newInterval.start) {
				it++;
			}
			else if ((*it).start > newInterval.end) {
				it = intervals.insert(it, newInterval);
				return intervals;
			}
			else {
				newInterval.start = min(newInterval.start, (*it).start);
				newInterval.end = max(newInterval.end, (*it).end);
				it = intervals.erase(it);
			}
		}
		intervals.push_back(newInterval);	
		return intervals;
	}
};

int main()
{
	vector<Interval> intervals;
	intervals.push_back(Interval(1, 2));
	intervals.push_back(Interval(3, 5));
	intervals.push_back(Interval(6, 7));
	intervals.push_back(Interval(8, 10));
	intervals.push_back(Interval(12, 16));
	//Interval newInterval(4, 9);
	Interval newInterval(0, 1);
	
/*	intervals.push_back(Interval(1, 5));
	Interval newInterval(2, 3);*/
	
	//Interval newInterval(5, 7);

	Solution s;
	intervals = s.insert(intervals, newInterval);
	for (int i=0; i<intervals.size(); i++) {
		cout << intervals[i].start << "," << intervals[i].end << endl;
	}
}
