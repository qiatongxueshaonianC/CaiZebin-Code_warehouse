#include<bits/stdc++.h>
using namespace std; 
const int maxn=510;
int G[maxn][maxn],N,M; 
vector<unordered_set<int> > pre(maxn);
bool vis[maxn]={false};
int d[maxn];
void Prim(int s){
	fill(d,d+maxn,INT_MAX);
	d[s]=0;
	for(int ii=0;ii<N;ii++){	//循环N次 
		int Min=INT_MAX,u=-1;
		for(int i=1;i<=N;i++){		//找所有点中离当前集合最近的点 
			if(!vis[i]&&d[i]<Min){
				Min=d[i];
				u=i;
			}
		} 
		if(u==-1)
			return;
		vis[u]=true;
		for(int v=1;v<=N;v++){
			if(!vis[v]&&G[u][v]!=INT_MAX){
				if(G[u][v]<d[v]){
					d[v]=G[u][v];
					pre[v].clear();
					pre[v].insert(u);
				}else if(G[u][v]==d[v]){
					pre[v].insert(u);
				}
			}
		} 
	}
}
int main() {
	fill(G[0],G[0]+maxn*maxn,INT_MAX);
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		G[u][v]=G[v][u]=w;
	}
	int blocks=0;
	for(int i=1;i<=N;i++){
		if(!vis[i]){
			blocks++;
			Prim(i);		//若连通的话，设定i为起始点，即1 
		}
	}
	if(blocks>1){
		puts("No MST");
		printf("%d\n",blocks);
	}else{
		int Sum_weight=0,num_path=1;
		for(int i=2;i<=N;i++){
			num_path*=pre[i].size();
			Sum_weight+=G[*(pre[i].begin())][i];
		}
		printf("%d\n",Sum_weight);
		printf("%s\n",num_path==1?"Yes":"No");
	}
	return 0;
}
/*
5 7
1 2 6
5 1 1
2 3 4
3 4 3
4 1 7
2 4 2
4 5 5

4 5
1 2 1
2 3 1
3 4 2
4 1 2
3 1 3

5 5
1 2 1
2 3 1
3 4 2
4 1 2
3 1 3
*/
