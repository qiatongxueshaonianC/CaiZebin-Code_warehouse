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
double X, Y;
int M;
struct Point {
	double x, y;
	Point(double a, double b) :x(a), y(b) {}
	Point() {}
}p[maxn];
double E;
double randNum() {
	return (rand()*rand()) % 10001 / 10000.0;
}
double dis(Point a, Point b) {
	return sqrt((a.x - b.x)*(a.x - b.x) + (a.y - b.y)*(a.y - b.y));
}
double maxDis(Point a) {
	double d = 1e-80;
	for (int i = 0; i < M; i++) {
		d = max(d, dis(a, p[i]));  //�����е�������
	}
	return -d;			//�㷨��������Ҫ������		�����������С��
}
void Solve(Point& ans, double T) {
	double E = maxDis(ans);
	int count = 40;
	double T_min = 1e-8;
	while (T > T_min) {
		Point next;
		double nE = -1e18;
		for (int i = 0; i < count; i++) {
			Point temp;
			double angle = 2 * PI*randNum();
			temp.x = ans.x + T * cos(angle);
			temp.y = ans.y + T * sin(angle);
			temp.x = min(X, max(temp.x, 0.0));	//�߽�Լ��������ȷ���㷨û���ﵽ��Ч���� 
			temp.y = min(Y, max(temp.y, 0.0));	//ȷ���㷨ÿ�ζ�������Զ���뷽�򿿽�һ�㣬��С��Զ���� 
			double tE = maxDis(temp);			//���ǣ�ȴû�취��֤�ڱ߽��� 
			if (tE > nE) {
				next = temp;
				nE = tE;
			}
		}
		double dE = nE - E;
		if (dE >= 0 || exp(dE / T) > randNum()) {
			ans = next;
			E = nE;
		}
		T *= 0.95;
	}
	printf("(%.1lf,%.1lf).\n", ans.x, ans.y);
	printf("%.1lf\n", -E);
}
int main() {
	while (~scanf("%lf%lf%d", &X, &Y, &M)) {
		for (int i = 0; i < M; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		Point ans(X / 2.0, Y / 2.0);
		double T = sqrt(X*X + Y * Y);
		Solve(ans, T);
	}
	return 0;
}
/*
1000 50 1
10 10
1000 50 4
0 0
1 0
0 1
1 1
*/
