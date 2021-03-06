#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int inf=0x3fffffff;
typedef pair<int,int> P;
struct Node{
	int to,dis;
	Node(int a,int b){
		to=a;dis=b;
	}
	Node(){}
}; 
vector<Node> G[maxn]; 
int n,m,st,ed,cost[maxn][maxn]; 
int d[maxn],c[maxn],pre[maxn];
bool vis[maxn]; 
void Dijkstra(int s){
	fill(d,d+maxn,inf);
	fill(c,c+maxn,inf);
	fill(vis,vis+maxn,false);
//	fill(w,w+maxn,0);
//	w[s]=weight[s]; 
	d[s]=0;
	c[s]=0; 
	priority_queue<P,vector<P>,greater<P> >q;
	q.push(P(0,s));
	while(!q.empty()){
		P now=q.top();q.pop();
		int u=now.second;
		if(now.first>d[u]) continue;
		vis[u]=true;
		for(auto i:G[u]){
			int v=i.to,dis=i.dis ;
			if(vis[v]==false){
				if(d[u]+dis<d[v]){
					d[v]=d[u]+dis;
					c[v]=c[u]+cost[u][v];
				//	w[v]=w[u]+weight[v];
					q.push(P(d[v],v));      //将原点距离本节点的距离及本节点的编号入队列 
					pre[v]=u;
				}else if(d[u]+dis==d[v]){
					if(c[u]+cost[u][v]<c[v]){
						c[v]=c[u]+cost[u][v];
						pre[v]=u;		
					//	w[v]=w[u]+weight[v];			
					}
				}
			}
		}
	} 
}
void DFS(int v){
	if(v==st){
		printf("%d ",v);
		return;
	}
	DFS(pre[v]);
	printf("%d ",v);
}
int main() {
	int c1,c2,dis,cos;
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&c1,&c2,&dis,&cos);
		cost[c1][c2]=cost[c2][c1]=cos;
		Node node(c2,dis);
		G[c1].push_back(node);
		node.to=c1;
		G[c2].push_back(node);
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
