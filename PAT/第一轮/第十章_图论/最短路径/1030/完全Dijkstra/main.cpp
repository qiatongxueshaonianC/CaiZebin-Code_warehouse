#include<bits/stdc++.h> 
using namespace std;
const int maxn=510;
const int inf=0x3fffffff;
int weight[maxn]={0};
int cost[maxn][maxn],G[maxn][maxn];
int n,m,st,ed; 
int num[maxn],d[maxn],c[maxn],pr[maxn];
bool vis[maxn]={false};
vector<int> pre[maxn];
void Dijkstra(int s){
	fill(d,d+maxn,inf);
	fill(c,c+maxn,inf);
	d[s]=0;
	c[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<min){
				u=j;
				min=d[j];
			}
		}
		if(u==-1) return ;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=inf){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
					pr[v]=u;
					c[v]=c[u]+cost[u][v];
					num[v]=num[u];
				}else if(d[u]+G[u][v]==d[v]){
					num[v]+=num[u];
					if(c[u]+cost[u][v]<c[v]) {
						pre[v].clear();
						pre[v].push_back(u);
						c[v]=c[u]+cost[u][v];
						pr[v]=u;
					}
				}
			}
		}
	}
}
void DFS(int a){
	if(a==st){
		printf("%d ",a);
		return;
	}	
    //DFS(pr[a]);
    DFS(*pre[a].begin());
    printf("%d ",a);
}
int main() {
	fill(G[0],G[0]+maxn*maxn,inf);
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	int c1,c2,dis,cos;
	while(m--){
		scanf("%d%d%d%d",&c1,&c2,&dis,&cos);
		G[c1][c2]=G[c2][c1]=dis;
		cost[c1][c2]=cost[c2][c1]=cos;
	}
	Dijkstra(st);
	DFS(ed);
	printf("%d %d\n",d[ed],c[ed]);
	return 0;
}
/*
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
*/
