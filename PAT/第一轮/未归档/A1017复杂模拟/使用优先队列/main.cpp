#include<bits/stdc++.h>
using namespace std; 
struct Custom{
	int comeTime,serveTime;
	Custom(int a,int b):comeTime(a),serveTime(b){}
	bool operator <(const Custom &u){
		return comeTime<u.comeTime;
	}
};
int change(int h,int m,int s){
	return h*3600+m*60+s;
}
priority_queue<int,vector<int>,greater<int>> win;
int main() {
	int stTime=change(8,0,0);
	int edTime=change(17,0,0);
	int n,w,h,m,s,serve;
	scanf("%d%d",&n,&w);
	for(int i=0;i<w;i++)
		win.push(stTime);  //ģ����w������ 
	vector<Custom> A;
	for(int i=0;i<n;i++){
		scanf("%d:%d:%d %d",&h,&m,&s,&serve);
		int come=change(h,m,s);
		if(come>edTime) continue;
		serve=serve<60?serve*60:3600;
		A.push_back(Custom(come,serve));
	}
	sort(A.begin(),A.end());
	long long ans=0;
	for(int i=0;i<A.size();i++){
		int minEndtime=win.top();win.pop();
		if(minEndtime<A[i].comeTime){
			win.push(A[i].comeTime+A[i].serveTime);
		}else{
			ans+=(minEndtime-A[i].comeTime);
			win.push(minEndtime+A[i].serveTime);
		}
	}
	if(A.size()==0) printf("0.0\n");
	else printf("%.1lf",ans/60.0/A.size());
	return 0;
}
/*
7 3
07:55:00 16
17:00:01 2
07:59:59 15
08:01:00 60
08:00:00 30
08:00:02 2
08:03:00 10
*/
