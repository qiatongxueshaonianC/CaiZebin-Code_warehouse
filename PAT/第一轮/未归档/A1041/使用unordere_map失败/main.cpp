#include<bits/stdc++.h>
using namespace std; 
int main() {
	unordered_map<int,int> mp;
	int n,v;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		if(mp.find(v)!=mp.end()) mp[v]++;
		else mp.insert({v,1});
	//	else mp[v]=1;
	}
	auto it=mp.begin();
	for(;it!=mp.end();it++){
		if(it->second==1){
			printf("%d\n",it->first);
			break;
		}
	}
	if(it==mp.end()) puts("None");
	return 0;
}
/*
7 5 31 5 88 67 88 17

5 888 666 666 888 888
*/
