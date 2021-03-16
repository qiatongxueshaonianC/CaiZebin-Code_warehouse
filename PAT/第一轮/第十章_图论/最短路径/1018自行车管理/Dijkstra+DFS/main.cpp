#include<bits/stdc++.h>
using namespace std;
const int inf=0x3fffffff;
const int maxn=510;
int cmax,n,st,ed,m,minneed=inf,minback=inf;
vector<int> temp,ans;//pre[maxn];
unordered_set<int> pre[maxn];
int weight[maxn],d[maxn],G[maxn][maxn];
bool vis[maxn]={false};
void Dijkstra(int s){
	fill(d,d+maxn,inf);
	d[s]=0;
	for(int i=0;i<=n;i++){
		int u=-1,min=inf;
		for(int j=0;j<=n;j++)
			vis[j]==false&&d[j]<min?min=d[j],u=j:1;
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<=n;v++){
			if(vis[v]==false&&G[u][v]!=inf){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					pre[v].clear();
				//	pre[v].push_back(u);
					pre[v].insert(u);
				}else if(d[u]+G[u][v]==d[v])
					//	pre[v].push_back(u);
						pre[v].insert(u);
			}
		}
	}
}
void DFS(int s){
	if(s==st){
		temp.push_back(s);
		int need=0,remain=0;
		for(int i=temp.size()-1;i>=0;i--){
			int id=temp[i];
			if(weight[id]>0){
				remain+=weight[id];
			}else if(weight[id]<0){
				if(remain>abs(weight[id])){
					remain-=abs(weight[id]);
				}else{
					need=need+abs(weight[id])-remain;
					remain=0;
				}
			}
		}
		if(need<minneed){
			minneed=need;
			minback=remain;
			ans=temp;
		}else if(need==minneed&&remain<minback){
			minback=remain;
			ans=temp;
		}
		temp.pop_back();
	}
	temp.push_back(s);
	for(auto i:pre[s]){
		DFS(i);
	}
	temp.pop_back();
}
int main() {
	fill(G[0],G[0]+maxn*maxn,inf);
	scanf("%d%d%d%d",&cmax,&n,&ed,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&weight[i]);
		weight[i]-=cmax/2;
	}
	int c1,c2,dis;
	while(m--){
		scanf("%d%d%d",&c1,&c2,&dis);
		G[c1][c2]=G[c2][c1]=dis;
	}
	st=0;
	Dijkstra(st);
	DFS(ed);
	printf("%d ",minneed);
	reverse(ans.begin(),ans.end());
	for(auto i:ans){
		printf("%d",i);
		if(i!=*(ans.end()-1)) printf("->");
	}
	printf(" %d\n",minback); 
	return 0;
}
/*
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
*/
