#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n,m,v;
	pair<int,int> p(0,0);
	scanf("%d%d",&n,&m);
	unordered_map<int,int> mp;
	while(m--){
		for(int i=0;i<n;i++){
			scanf("%d",&v);
			if(mp.find(v)!=mp.end()) mp[v]++;
			else mp[v]=1;
			if(mp[v]>p.second) p.first=v;
		}
	}
	printf("%d\n",p.first);
	return 0;
}
/*
5 3
0 0 255 16777215 24
24 24 0 0 24
24 0 24 24 24
*/ 
