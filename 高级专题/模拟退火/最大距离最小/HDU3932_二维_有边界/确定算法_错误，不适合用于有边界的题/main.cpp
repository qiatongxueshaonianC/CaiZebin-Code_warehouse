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
double maxDisidx(Point a,double T) {
	int idx;
	double d = -1e80;
	for (int i = 0; i < M; i++) {
		double tp=dis(a,p[i]);
		if(tp>d){
			d=tp;
			idx=i;
		}
	}
	return idx;
}
void Solve(Point& ans, double T) {
	double E;
	double T_min=1e-10;
	while(T>T_min){
		int idx=maxDisidx(ans,T);
		E=dis(ans,p[idx]);
		ans.x+=T*((p[idx].x-ans.x)/E);  //T*cos(theta)
		ans.y+=T*((p[idx].y-ans.y)/E);
	/*	ans.x=min(X,max(ans.x,0.0));
		ans.y=min(Y,max(ans.y,0.0));*/
		T*=0.9; 
	} 
	printf("(%.1lf,%.1lf).\n", ans.x, ans.y);
	printf("%.1lf\n", E);
}
int main() {
	while (~scanf("%lf%lf%d", &X, &Y, &M)) {
		for (int i = 0; i < M; i++)
			scanf("%lf%lf", &p[i].x, &p[i].y);
		Point ans(X/2, Y/2);
		double T = sqrt(X*X + Y * Y)/2;
		Solve(ans, T);
/*		cout<<setiosflags(ios::fixed);
		cout<<'('<<setprecision(1)<<ans.x<<','<<setprecision(1)<<ans.y<<')'<<endl;
		cout<<setprecision(1)<<-E<<endl;	*/
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
