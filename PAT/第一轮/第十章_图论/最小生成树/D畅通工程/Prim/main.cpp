#include<bits/stdc++.h> 
using namespace std;
const int maxn=110;
const int inf=0x3fffffff;
int n,d[maxn],G[maxn][maxn];
bool vis[maxn];
void Prim(int s){
	fill(d,d+maxn,inf);
	fill(vis,vis+maxn,false);
	d[s]=0;
	for(int i=1;i<=n;i++){
		int u=-1,min=inf;
		for(int j=1;j<=n;j++){
			if(vis[j]==false&&d[j]<min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=1;v<=n;v++){
			if(vis[v]==false&&G[u][v]!=inf){
				if(G[u][v]<d[v])
					d[v]=G[u][v];
			}
		} 
	}
}
int main() {
	while(scanf("%d",&n)){
		if(n==0) break;
		fill(G[0],G[0]+maxn*maxn,inf);
		int loop=n*(n-1)/2,u,v,dis,flag;
		for(int i=0;i<loop;i++){
			scanf("%d%d%d%d",&u,&v,&dis,&flag);
			if(flag==1) dis=0;
			G[u][v]=G[v][u]=dis;
		}
		Prim(1);
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=d[i];
		printf("%d\n",ans);
	}
	return 0;
}
/*
4
1 2 1 1
1 3 6 0
1 4 2 1
2 3 3 0
2 4 5 0
3 4 4 0
3
1 2 1 1
2 3 2 1
1 3 1 0
0
*/
