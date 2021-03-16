#include<bits/stdc++.h> 
using namespace std;
const int maxn=1010;
const int inf=0x3fffffff;
int n,m,d[maxn],G[maxn][maxn]; 
bool vis[maxn];
void Prim(int s){
	fill(d,d+maxn,inf);
	fill(vis,vis+maxn,false);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=inf){
				if(G[u][v]<d[v]){
					d[v]=G[u][v];
				}
			}
		}
	}
}
int main() {
	fill(G[0],G[0]+maxn*maxn,inf);
	int u,v,dis;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&dis);
		G[u][v]=G[v][u]=dis;
	}
	Prim(0);
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=d[i];
	}
	printf("%d\n",ans);
	return 0;
}
/*
6 10
0 1 4
0 4 1
0 5 2
1 2 6
1 5 3
2 3 6
2 5 5
3 4 4
3 5 5
4 5 3
*/
