#include <iostream>
#include <vector>
using namespace std;
/*
class Solution {
public:
	double pow(double x, int n) {
		int n1 = n;
		double p = 0;
		if (n < 0) n1 = -n;
		if (n < 0) return 1/pow(x, n1, p);
		return pow(x, n1, p);	
	}
	double pow(double x, int n, double &p) {
		if (n == 0) {
			p = 1;
			return p;
		}
		
		if (n%2 == 0) {
			p = pow(x, n/2);
			p = p*p;
		}
		else {
			p = pow(x, n/2);
			p = p*p*x;
		}
		return p;
	}
};*/

class Solution {
public:
	double pow(double x, int n) {
		if (n < 0) return 1/pow2(x, -n);
		return pow2(x, n);	
	}
	double pow2(double x, int n) {
		if (n == 0) return 1;
		
		double p = pow2(x, n/2);
		if (n%2 == 0) p = p*p;
		else p = p*p*x;
		return p;
	}
};

int main()
{
	Solution s;
	//cout << s.pow(3, -3) << endl;
	cout << s.pow(8.88023, 3) << endl;
	//cout << s.pow(0.00001, 2147483647) << endl;
}
