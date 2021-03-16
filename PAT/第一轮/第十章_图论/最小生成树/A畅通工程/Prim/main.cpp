#include<bits/stdc++.h> 
using namespace std;
const int inf=0x3fffffff;
const int maxn=110;
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
		int loop=n*(n-1)/2,u,v,dis;
		for(int i=0;i<loop;i++){
			scanf("%d%d%d",&u,&v,&dis);
			G[u][v]=G[v][u]=dis;
		}
		Prim(1);
		int ans=0;
		for(int i=1;i<=n;i++){
			ans+=d[i];
		}
		printf("%d\n",ans);
	}
	return 0;
}
/*
8
1 2 42
1 3 68
1 4 35
1 5 1
1 6 70
1 7 25
1 8 79
2 3 59
2 4 63
2 5 65
2 6 6
2 7 46
2 8 82
3 4 28
3 5 62
3 6 92
3 7 96
3 8 43
4 5 28
4 6 37
4 7 92
4 8 5
5 6 3
5 7 54
5 8 93
6 7 83
6 8 22
7 8 17
0
*/
