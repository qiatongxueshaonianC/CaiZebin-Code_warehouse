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
const int maxn = 105;
const double PI=acos(-1.0);
struct Point{
	double x,y;
	Point(double a,double b):x(a),y(b){}
	Point(){}
}p[maxn]; 
int N;
double E;
double randNum(){
	return (rand()*3)%10000/10000.0;
}
double dis(Point a,Point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double minDis(Point a){
	double d=0;
	for(int i=0;i<N;i++)
		d+=dis(a,p[i]);
	return -d;	//��������ֵ��������������Сֵ 
}
void Solve(Point& ans,double T){  
	E=minDis(ans);
	double T_min=1e-8;
	int count=40;
	while(T>T_min){
		Point next;
		double nE=-1e80;
		for(int i=0;i<count;i++){
			Point temp;
			double angle=randNum()*2*PI;
			temp.x=ans.x+T*cos(angle);
			temp.y=ans.y+T*sin(angle);
			temp.x=min(10000.0,max(temp.x,0.0));
			temp.y=min(10000.0,max(temp.y,0.0));
			double tE=minDis(temp);
			if(tE>nE){
				next=temp;
				nE=tE;
			}
		}
		double dE=nE-E;
		if(dE>=0||exp(dE/T)>randNum()){
			ans=next;
			E=nE;
		}
		T*=0.8;
	} 
}
int main() {
	srand(time(NULL));
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		scanf("%lf%lf",&p[i].x,&p[i].y);
	Point ans(10000/2.0,10000/2.0);
	double T=sqrt(5000*5000*2.0)/2.0;
	Solve(ans,T);
	printf("%.0lf",-E);
	return 0;
}
/*
4
0 0
0 10000
10000 10000
10000 0
*/
