#pragma GCC optimize(2)
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
const int maxn = 35;
const double PI = acos(-1.0);
const double Hf_PI = PI / 2;
struct Point {
	double x, y, z;
	Point(double a, double b, double c) :x(a), y(b), z(c) {}
	Point() {}
}p[maxn];
double X = 0, Y, Z;
int N;
double randNum() {
	return (rand()*rand()) % 10001 / 10000.0;
}
double dis(Point a, Point b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y) + (a.z - b.z)*(a.z - b.z));
}
double maxDis(Point a) {
	double d = -1e80;
	for (int i = 0; i < N; i++)
		d = max(d, dis(a, p[i]));
	return -d;
}
void Solve(Point& ans, double T) {
	double E = maxDis(ans);
	int count = 7;
	double T_min = 1e-5;
	while (T > T_min) {
		Point next;
		double nE = -1e80;
		for (int i = 0; i < N; i++) {
			Point temp;
			double gama = 2*PI * randNum();
			double angle = 2 * PI*randNum();
			temp.x = ans.x + T * cos(gama)*sin(angle);
			temp.y = ans.y + T * cos(gama)*cos(angle);
			temp.z = ans.z + T * sin(gama);
			double tE = maxDis(temp);
			if (tE > nE) {
				nE = tE;
				next = temp;
			}
		}
		double dE = nE - E;
		double gv = exp(dE / T),rd= randNum();
		if (dE >= 0 ||  gv> rd) {
			ans = next;
			E = nE;
		}
		if (T > 1e-3)
			T *= 0.8;
		else 
			T *= 0.9999;
	//	else
		//	T *= 0.99995;
	}
//	cout << setiosflags(ios::fixed);
//	cout << setprecision(5) << -E << endl;
	printf("%.5lf\n", -E);
}
int main() {
	while (~scanf("%d", &N) && N != 0) {
		clock_t start, finish;
		start = clock();
		for (int i = 0; i < N; i++) {
			scanf("%lf%lf%lf", &p[i].x, &p[i].y, &p[i].z);
			X = max(X, max(p[i].x, max(p[i].y, p[i].z)));
		}
		Point ans (0.0,0.0,0.0);
		Y = Z = X;
		double T = sqrt(X*X + Y * Y + Z * Z);
		Solve(ans, T);
		finish = clock();
		cout << finish - start << '/' << CLOCKS_PER_SEC << "(s)" << endl;
	}
	return 0;
}
/*
4
10.00000 10.00000 10.00000
20.00000 10.00000 10.00000
20.00000 20.00000 10.00000
10.00000 20.00000 10.00000
4
10.00000 10.00000 10.00000
10.00000 50.00000 50.00000
50.00000 10.00000 50.00000
50.00000 50.00000 10.00000
0
*/