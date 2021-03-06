#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
vector<int> G[maxn];
set<int> temp,ans;
bool vis[maxn]={false};
int n,maxhigh=0;
void DFS(int now,int high,int pre){
	if(high>maxhigh){
			temp.clear();
			temp.insert(now);
			maxhigh=high;
		}else if(high==maxhigh) temp.insert(now);
	for(auto i:G[now]){
		if(i==pre) continue;
		DFS(i,high+1,now);
	}
}
void DFS2(int now){
	vis[now]=true;
	for(auto i:G[now]){
		if(vis[i]==false)
			DFS2(i);
	}
}
int DFSTrave(){
	int block=0;
	for(int i=1;i<=n;i++){
		if(vis[i]==false) {
			block++;
			DFS2(i);
		}
	}
	return block;
} 
int main() {
	int id1,id2;
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		scanf("%d%d",&id1,&id2);
		G[id1].push_back(id2);
		G[id2].push_back(id1);
	}
	int block=DFSTrave();
	if(block>1) printf("Error: %d components",block);
	else{
		DFS(1,0,-1);
		ans=temp;
		DFS(*ans.begin(),0,-1);
		for(auto i:temp)
			ans.insert(i);
		set<int>::iterator it=ans.begin();
		for(;it!=ans.end();it++){
			printf("%d\n",*it);
		}
	}
	return 0;
}
/*
5
1 3
1 4
2 5
3 4
*/
