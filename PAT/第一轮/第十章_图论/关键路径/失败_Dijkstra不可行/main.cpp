#include<bits/stdc++.h>
using namespace std;
const int maxn=20;
const int inf=0x3fffffff;
int loop,n,m,inDegree[maxn],outDegree[maxn],d[maxn],G[maxn][maxn];
int st,ed;
vector<int> ans;
unordered_map<char,int> mp;
unordered_map<int,char> itoc;
set<int> pre[maxn];
bool vis[maxn];
void Dijkstra(int s){
	fill(d,d+maxn,-inf);
	fill(vis,vis+maxn,false);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,max=-inf;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]>max){
				max=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=-inf){
				if(d[u]+G[u][v]>d[v]){
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].insert(u);
				}
			}
		}
	}
}
void DFS(int s){
	if(s==st){
		ans.push_back(s);
		return;
	}
	DFS(*pre[s].begin());
	ans.push_back(s);
}
int main() {
	scanf("%d",&loop);
	while(loop--){
		fill(G[0],G[0]+maxn*maxn,-inf);
		scanf("%d%d",&n,&m);
		string s1,s2;
		cin>>s1;
		for(int i=0;s1.size();i++){
			mp[s1[0]]=i;
			itoc[i]=s1[0];
			s1.erase(s1.begin());
		}
		int u,v,dis;
		while(m--){
			cin>>s1>>s2>>dis;
			u=mp[s1[0]];
			v=mp[s2[0]];
			G[u][v]=dis;
		}
		for(int i=0;i<n;i++){
			if(inDegree[i]==0) st=i;
			if(outDegree[i]==0) ed=i;
		}
		Dijkstra(st);
		DFS(ed);
	//	reverse(ans.begin(),ans.end());
		for(int i=0;i<ans.size()-1;i++){
			printf("(%c,%c) ",itoc[ans[i]],itoc[ans[i+1]]);
		}
		puts(to_string(d[ed]).c_str());
		mp.clear();
		itoc.clear();
		ans.clear();
		memset(inDegree,0,sizeof(inDegree));
		memset(outDegree,0,sizeof(outDegree));
		for(auto i:pre) i.clear();
	}
	return 0;
}
/*
2
5 6
abcde 
a b 3 
a c 2 
b d 5 
c d 7 
c e 4 
d e 6 
4 5 
abcd 
a b 2 
a c 3 
a d 4 
b d 1 
c d 3 
*/
