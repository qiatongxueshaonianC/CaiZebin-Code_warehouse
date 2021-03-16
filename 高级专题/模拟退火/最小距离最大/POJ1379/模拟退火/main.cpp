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
const int maxn = 1010;
const double PI = acos(-1.0);
struct Point {
	double x, y;
	Point(double a, double b) :x(a), y(b) {};
	Point() {}
}p[maxn];
double X, Y;
int M;
/*
double dis(Point a, Point b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}*/
double minDis(Point cur) {
	double d = 1e18;
	for (int i = 0; i < M; i++) {
		double temp = sqrt((cur.x - p[i].x)*(cur.x - p[i].x) + (cur.y - p[i].y)*(cur.y - p[i].y));
		d = min(d,temp );
	}
	return d;
}
double randnum() {
	return rand() % 10000 / 10000.0; //����0-1�ڵ������ 
}
void Solve(Point& ans, double T) {
	double T_min = 1e-8;
	double E = minDis(ans);
	int count = 40;
	while (T > T_min) {
		Point next;
		double nE = 0.0;
		for (int i = 0; i < count; i++) {
			Point temp;
			double angle = randnum() * 2 * PI;
			temp.x = ans.x + T * cos(angle);
			temp.y = ans.y + T * sin(angle);
			temp.x = min(X, max(0.0, temp.x));
			temp.y = min(Y, max(0.0, temp.y));
			double tE = minDis(temp);
			if (tE > nE) {  //����Χ�ĵ��������ŵ� 
				nE = tE;
				next = temp;
			}
		}
		double dE = nE - E;
		if (dE >= 0 || exp(dE / T) > randnum()) {
			ans = next;
			E = nE;
		}
		T = T * 0.8;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	srand(time(NULL));
	int t;
	cin >> t;
	while (t--) {
		cin >> X >> Y >> M;
		for (int i = 0; i < M; i++) {
			cin >> p[i].x >> p[i].y;
		//	scanf("%lf%lf", &p[i].x, &p[i].y);
		}
		Point ans(X / 2, Y / 2);
		double T = sqrt((X*X + Y * Y))/2.0;
		Solve(ans, T);
		cout << setiosflags(ios::fixed);	//������һ���Ժ�����setprecision����С�����λ���� 
	//	printf("The safest point is (%.1lf, %.1lf).\n", ans.x, ans.y);
			cout<<"The safest point is ("<<setprecision(1)<<ans.x<<", "<<setprecision(1)<<ans.y<<")."<<endl;
	}																//���ˣ����ﻹ��һ���ո�
	return 0;
}
/*
100
1000 50 1
10 10
100 100 4
10 10
10 90
90 10
90 90
3000 3000 4
1200 85
63 2500
2700 2650
2990 100
*/
