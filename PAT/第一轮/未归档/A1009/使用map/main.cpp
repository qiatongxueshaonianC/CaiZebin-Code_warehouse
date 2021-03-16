#include<bits/stdc++.h>
using namespace std; 
/*struct cmp{
	bool operator ()(const int &a,const int &b){
		return a>b; 
	}
};*/
int main() {
	int n,e;
	double v;
//	map<int,double,cmp> mp,ans; 
	map<int,double> mp,ans; 
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%lf",&e,&v);
	    if(v!=0) mp.insert({e,v});  //特殊情况处理2019/11/12/15：48 
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%lf",&e,&v);
		if(v==0) continue;   //特殊情况处理2019/11/12/15：48 
		for(auto i:mp){
			if(ans.find(e+i.first)!=ans.end()) ans[e+i.first]+=v*i.second;
			else ans.insert({e+i.first,v*i.second});
			if(ans[e+i.first]==0) ans.erase(e+i.first);   //删除 
		}
	}
	if(ans.size()>0){
		printf("%d",ans.size());
		for(auto i=--ans.end();;i--){
			printf(" %d %.1lf",(*i).first,(*i).second);
			if(i==ans.begin()) break;
		}	
	}else
		puts("0");
	return 0;
}
/*
2 1 2.4 0 3.2
2 2 1.5 1 0.5

2 1 2.4 0 3.2
1 1 0
*/
