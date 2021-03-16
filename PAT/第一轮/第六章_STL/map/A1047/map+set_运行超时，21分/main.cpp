#include<bits/stdc++.h>
using namespace std;
unordered_map<int,set<string>> mp;
int main() {
	int n,k;
	string name;
	scanf("%d%d",&n,&k);
	for(int i=0;i<n;i++){
		int num,v;
		cin>>name>>num;
		while(num--){
			scanf("%d",&v);
			if(mp.find(v)==mp.end()){
				set<string> temp;
				temp.insert(name);
				mp[v]=temp;
			}else
				mp[v].insert(name);
		}
	}
	for(int i=1;i<=k;i++){
		printf("%d %d\n",i,mp[i].size());
		for(auto j:mp[i])
			printf("%s\n",j.c_str());
	}
	return 0;
}
/*
10 5
ZOE1 2 4 5
ANN0 3 5 2 1
BOB5 5 3 4 2 1 5
JOE4 1 2
JAY9 4 1 2 5 4
FRA8 3 4 2 5
DON2 2 4 5
AMY7 1 5
KAT3 3 5 4 2
LOR6 4 2 4 1 5
*/
