#pragma warning(disable:4996)
#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<iterator>
#include<ctime>
#include<iomanip>
using namespace std;
const double PI = acos(-1.0);
const double inf = 1e9;
double a, b, c, d, e, f;
struct Point {
	double x, y, z;
	Point() {}
	Point(double a, double b, double c) :x(a), y(b), z(c) {}
};
double randNum() {
	return (rand()*rand()) % 10001 / 10000.0;
}
double dis(double a, double b, double c) {
	return sqrt(a*a + b * b + c * c);
}
double F(double x, double y) {
	double A = c;
	double B = d * y + e * x;
	double C = a * x*x + b * y*y + f * x*y - 1;
	double deta = B*B-4*A*C;
	if (deta < 0)
		return inf + 10;
	double z1 = (-B + sqrt(deta)) / (2 * c);
	double z2 = (-B - sqrt(deta)) / (2 * c);
	if (z1*z1<z2*z2)
		return z1;
	return z2;
}
void Solve(Point ans, double T) {
	double E = dis(ans.x, ans.y, ans.z);
	int count = 50;
	double T_min = 1e-7;
	while (T > T_min) {
		double nE = 1e80;
		Point next;
		for (int i = 0; i < count; i++) {
			Point temp;
			double angle = 2 * PI*randNum();
			temp.x = ans.x + T * cos(angle);
			temp.y = ans.y + T * sin(angle);
			temp.z = F(temp.x, temp.y);
			if (temp.z > inf)  //非椭球面的点 
				continue;
			double tE = dis(temp.x, temp.y, temp.z);
			if (tE < nE) {
				nE = tE;
				next = temp;
			}
		}
		double dE = E - nE;
		if (dE >= 0 || exp(dE / T) > randNum()) {
			ans = next;
			E = nE;
		}
		T *= 0.95;
	}
	printf("%.7lf\n", E);
}
int main() {
	while (~scanf("%lf%lf%lf%lf%lf%lf", &a, &b, &c, &d, &e, &f)) {
		Point ans(0.0, 0.0, sqrt(1 / c));
		double T = dis(ans.x, ans.y, ans.z);
		Solve(ans, T);
	}
	return 0;
}
/*
1 0.04 0.01 0 0 0
*/