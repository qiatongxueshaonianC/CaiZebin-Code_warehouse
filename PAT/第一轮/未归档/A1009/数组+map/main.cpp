#include<bits/stdc++.h>
using namespace std; 
struct cmp{
	bool operator ()(int a,int b){
		return a>b;
	}
};
int main() {
	double A[2005]={0},v;
	map<int,double,cmp> mp; 
	int n,size=0,e;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%lf",&e,&v);
		A[e]=v;
	} 
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%lf",&e,&v);
		for(int j=0;j<1001;j++){
		//	if(A[j+e]==0||v==0) continue;    //这么写不行，第一个点过不了，2019/11/12/16：43发现 
			if(mp.find(j+e)!=mp.end()) mp[j+e]+=A[j]*v;
			else mp.insert({j+e,A[j]*v});
			if(mp[j+e]==0) mp.erase(j+e);
		}	
	} 
	printf("%d",mp.size());
	for(auto i:mp)
		printf(" %d %.1lf",i.first,i.second);
	return 0;
}
/*
2 1 2.4 0 3.2
2 2 1.5 1 0.5

2 1 2.4 0 3.2
1 1 0
*/
