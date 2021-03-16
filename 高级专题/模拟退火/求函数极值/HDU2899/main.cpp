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
const double PI=acos(-1.0);
#define F(x) 6*pow(x,7)+8*pow(x,6)+7*pow(x,3)+5*pow(x,2)-x*Y
double Y; 
double randNum(){
	return ((rand()*rand())%10001)/10000.0;
}
void Solve(double T){
	double T_min=1e-10,pos=50;
	int count=30;
	double E=1e80;  //无穷大 
	while(T>T_min){
		double nE=1e80,next;
		for(int i=0;i<count;i++){
			double angle=2*PI*randNum();
			double tx=pos+T*cos(angle);
			if(tx>100.0||tx<0.0)
				continue; 
			double tE=F(tx);
			if(tE<nE){
				next=tx;
				nE=tE;
			}
		} 
		double dE=E-nE;  //注意这里的变通，如果是求最大值，应该是nE-E; 
		if(dE>=0||exp(dE/T)>randNum()) {
			pos=next;
			E=nE;
		}
		T*=0.95;
	}
	printf("%.4lf\n",E);
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%lf",&Y);
		double T=100;
		Solve(T);
	}
	return 0;
}
/*
2
100
200
*/
