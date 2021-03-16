#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
vector<int> G[maxn];
set<int> temp,ans;
bool vis[maxn]={false};
int n,maxhigh=0;
int father[maxn],isroot[maxn]={0};
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
int findFather(int a){
	if(father[a]==a) return a;
	int temp=findFather(father[a]);
	father[a]=temp;
	return temp;
}
void Union(int a,int b){
	int fa=findFather(a);
	int fb=findFather(b);
	if(fa!=fb) father[fa]=fb;
}
void init(){
	for(int i=1;i<=n;i++){
		father[i]=i;
	}
}
int calblock(){
	int ans=0;
	for(int i=1;i<=n;i++){
		isroot[findFather(i)]++;
	}
	for(int i=1;i<=n;i++)
		if(isroot[i]>0) ans++;
	return ans;
}
int main() {
	int id1,id2;
	scanf("%d",&n);
	init();
	for(int i=1;i<n;i++){
		scanf("%d%d",&id1,&id2);
		G[id1].push_back(id2);
		G[id2].push_back(id1);
		Union(id1,id2);
	}
	int block=calblock();
	if(block>1) printf("Error: %d components",block);
	else{
		DFS(1,0,-1);
		ans=temp;
		DFS(*ans.begin(),0,-1);
		for(auto i:temp)
			ans.insert(i);
		for(auto i:ans){
			printf("%d\n",i);
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
