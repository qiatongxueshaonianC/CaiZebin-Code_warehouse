#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n,u;
	double v;
	map<int,double> mp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%lf",&u,&v);
		mp.insert({u,v});
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%lf",&u,&v);
		if(mp.find(u)!=mp.end()) {
			mp[u]+=v;
			if(mp[u]==0) 
				mp.erase(mp.find(u));
		}
		else mp[u]=v; 
	}
	printf("%d",mp.size());
	if(mp.size()!=0)  //2019/11/9/23:24发现，0的特殊情况 
		for(auto i=--mp.end();;i--){
			printf(" %d %.1lf",i->first,i->second);
			if(i==mp.begin()) break;
		}
	return 0;
}
/*
2 1 2.4 0 3.2
2 2 1.5 1 0.5

4 4 0.5 2 5.6 1 -2.7 0 3.6
3 3 -2.1 2 -5.6 1 2.7
*/
