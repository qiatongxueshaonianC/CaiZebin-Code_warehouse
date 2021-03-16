#include<bits/stdc++.h>
using namespace std; 
const int inf=0x3fffffff;
struct Custom{
	int cometime,servetime;
	Custom(int come,int sev){
		cometime=come;
		servetime=sev;
	}
	bool operator <(const Custom &u){
		return cometime<u.cometime;
	}
};
int change(int h,int m,int s){
	return h*3600+m*60+s;
}
int endTime[110];
vector<Custom> A;
int main() {
	int stTime=change(8,0,0);
	int edTime=change(17,0,0);
	long long ans=0;
	int n,h,m,s,serve,w;
	scanf("%d%d",&n,&w);
	for(int i=0;i<w;i++){
		endTime[i]=stTime;
	}
	for(int i=0;i<n;i++){
		scanf("%d:%d:%d %d",&h,&m,&s,&serve);
		int cometime=change(h,m,s);
		if(cometime>edTime) continue;
		serve=serve<60?serve*60:3600;
		A.push_back(Custom(cometime,serve));
	}
	sort(A.begin(),A.end());
	for(int i=0;i<A.size();i++){
		int idx=-1,minEndtime=inf;
		for(int i=0;i<w;i++){
			if(endTime[i]<minEndtime){
				minEndtime=endTime[i];
				idx=i;
			}
		}
		if(minEndtime<A[i].cometime){
			endTime[idx]=A[i].cometime+A[i].servetime;
		}else{
			ans+=(minEndtime-A[i].cometime);
			endTime[idx]+=A[i].servetime;
		}
	}
	if(A.size()==0) printf("0.0\n");
	else printf("%.1lf\n",ans/60.0/A.size());
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
