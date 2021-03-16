//三维，求最大距离最小 
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
const int maxn=35;
const double PI=acos(-1.0);
const double Hf_PI=PI/2;
struct Point{
	double x,y,z;
	Point(double a,double b,double c):x(a),y(b),z(c){}
	Point(){}
}p[maxn]; 
double X=0,Y,Z;
int N;
double randNum(){
	return (rand()*rand())%10001/10000.0;
}
double dis(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
int maxDisidx(Point a){
	double d=-1e80;
	int pos;
	for(int i=0;i<N;i++){
		double tp=dis(a,p[i]);
		if(tp>d){
			d=tp;
			pos=i;
		}	
	}
	return pos;
}
void Solve(Point& ans,double T){
	double nE;
	double T_min=1e-8;
	while(T>T_min){
		int idx=maxDisidx(ans);
		nE=dis(ans,p[idx]);
		ans.x+=T*((p[idx].x-ans.x)/nE);	//T*cos(theta)
		ans.y+=T*((p[idx].y-ans.y)/nE);
		ans.z+=T*((p[idx].z-ans.z)/nE);
		T*=0.98;
	}
	printf("%.5lf\n",nE);
}
int main() {
	while(~scanf("%d",&N)&&N!=0){
		for(int i=0;i<N;i++){
			scanf("%lf%lf%lf",&p[i].x,&p[i].y,&p[i].z);
			X=max(X,max(p[i].x,max(p[i].y,p[i].z)));
		}
		Point ans(0,0,0);
		Y=Z=X;
		double T=sqrt(X*X+Y*Y+Z*Z);
		Solve(ans,T);
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
