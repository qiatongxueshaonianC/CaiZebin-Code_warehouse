#include<bits/stdc++.h> 
using namespace std;
const int maxn=510;
const int inf=0x3fffffff;
int n,m,st,ed,d[maxn],w[maxn],weight[maxn]; 
int G[maxn][maxn],num[maxn],vis[maxn]={false};
void Dijkstra(int s){
	fill(d,d+maxn,inf);
	fill(w,w+maxn,0);   //具体设0还是设1要看求得是weight的值是大好还是小好，越大越好则设为0 
	fill(num,num+maxn,0);
	d[s]=0;
	w[s]=weight[s];
	num[s]=1;
	for(int i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++)
			if(vis[j]==false&&d[j]<min){
				min=d[j];
				u=j;
			}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=inf){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					w[v]=w[u]+weight[v];
					num[v]=num[u];
				}else if(d[u]+G[u][v]==d[v]){
					num[v]+=num[u];
					if(w[v]<w[u]+weight[v]){
						w[v]=w[u]+weight[v];
					}
				}
			}
		}
	}
}
int main() {
	fill(G[0],G[0]+maxn*maxn,inf); 
	int c1,c2,dis;
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	for(int i=0;i<n;i++)
		scanf("%d",&weight[i]);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&c1,&c2,&dis);
		G[c1][c2]=G[c2][c1]=dis;
	}
	Dijkstra(st);
	printf("%d %d\n",num[ed],w[ed]);
	return 0;
}
/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
*/
