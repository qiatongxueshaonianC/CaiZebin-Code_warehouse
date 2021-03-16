#include<bits/stdc++.h>
const int maxn=1010;
using namespace std; 
int n,father[maxn],isRoot[maxn];
vector<vector<int>> hobby(maxn);   //以hobby为单位 
priority_queue<pair<int,int>> ans;
int findFather(int s){
	if(father[s]==s) return s;
	int temp=findFather(father[s]);
	father[s]=temp;
	return temp;
}
int main() {
	scanf("%d",&n);
	int k,u,v;
	for(int i=1;i<=n;i++){
		scanf("%d:",&k);
		while(k--){
			scanf("%d",&v);
			hobby[v].push_back(i);
		}
	}
	iota(father,father+maxn,0);
	for(int i=0;i<hobby.size();i++) {
		if(hobby[i].empty()) continue;  //并不是每一个编号的爱好都有人喜欢 
		for(int j=0;j<hobby[i].size()-1;j++){
			int fa=findFather(hobby[i][j]);
			int fb=findFather(hobby[i][j+1]);
			if(fa!=fb){
				father[fa]=fb;
			}
		}
	}
	for(int i=1;i<=n;i++)
		isRoot[findFather(i)]++;
	for(int i=1;i<=n;i++){
		if(isRoot[i]>0) ans.push({isRoot[i],i});
	}
	printf("%d\n",ans.size());
	while(ans.size()){
		printf("%d%s",ans.top().first,ans.size()>1?" ":"");
		ans.pop();
	}
}
/*
8
3: 2 7 10
1: 4
2: 5 3
1: 4
1: 3
1: 4
4: 6 8 1 5
1: 4
*/
