#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

bool mycmp(const Point &a, const Point &b)
{	
	return a.x < b.x;
}

class Solution {
public:
	int maxPoints(vector<Point> &points) {
		int result = 0;
		for (int i=0; i<points.size(); i++) {
			int duplicate = 1, count = 0;
			unordered_map<float, int> umap;
			for (int j=0; j<points.size(); j++) {
				if (i == j) continue;
				float slope = 0;
				if (points[j].x == points[i].x) {	
					if (points[j].y == points[i].y) {
						duplicate++;	
						continue;
					}
					else slope = INT_MAX;
				}
				else slope = float(points[j].y-points[i].y)/(points[j].x-points[i].x);
				umap[slope]++;
			}
			if (umap.size() == 0) return result + duplicate;
			for (unordered_map<float, int>::iterator it=umap.begin(); it!=umap.end(); it++) {
				if (it->second+duplicate > result) {
					result = it->second + duplicate;
				}
			}
		}
		return result;
	}
};

int main()
{
	vector<Point> points;
/*	points.push_back(Point(0, 0));
	points.push_back(Point(0, 1));
	points.push_back(Point(1, 1));
	points.push_back(Point(1, 2));
	points.push_back(Point(2, 2));
*/
/*
	points.push_back(Point(0, 0));
	points.push_back(Point(1, 1));
	points.push_back(Point(1, -1));
*/
	points.push_back(Point(0, 0));
	points.push_back(Point(0, 0));
	points.push_back(Point(1, 0));

	Solution s;
	cout << s.maxPoints(points) << endl;
}
