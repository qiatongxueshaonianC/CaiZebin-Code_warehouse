#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int inf=0x3fffffff;
struct Node{
	int to,dis;
	Node(int a,int b){
		to=a;dis=b;
	}
	Node(){}
}; 
vector<Node> G[maxn]; 
int n,m,st,ed,cost[maxn][maxn]; 
int d[maxn],c[maxn],numinq[maxn],weight[maxn],w[maxn];
//set<int> pre[maxn];
int pre[maxn];
bool inq[maxn]; 
bool SPFA(int s){
	fill(d,d+maxn,inf);
	fill(c,c+maxn,inf);
	fill(inq,inq+maxn,false);
//	fill(w,w+maxn,0);
//	w[s]=weight[s];
	d[s]=0;
	c[s]=0;
	queue<int> q;
	q.push(s);
	inq[s]=true;
	numinq[s]++;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]==false;
		for(auto i:G[u]){
			int v=i.to,dis=i.dis;
			if(d[u]+dis<d[v]){
				d[v]=d[u]+dis;
				c[v]=c[u]+cost[u][v];
				pre[v]=u;
			//	pre[v].clear();
			//	pre[v].insert(u); 
				if(!inq[v]){
					q.push(v);
					inq[v]=false;
					numinq[v]++;
					if(numinq[v]>=n) return false;
				}
			}else if(d[u]+dis==d[v]){
				if(c[u]+cost[u][v]<c[v]){
				//  pre[v].clear(); 
				//	pre[v].insert(u);
					c[v]=c[u]+cost[u][v];
					pre[v]=u;
				}
			}
		}
	}
	return true;
}
/*bool Dijkstra(int s){
	fill(d,d+maxn,inf);
	fill(c,c+maxn,0);
	fill(inq,inq+maxn,false);
	d[s]=0;
	c[s]=0;
	priority_queue<P,vector<P>,greater<P> >q;
	q.push(P(0,s));
	inq[s]=true;
	numinq[s]++;
	while(!q.empty()){
		P now=q.top();q.pop();
		int u=now.second;
		inq[u]=false;
		for(auto i:G[u]){
			if(d[u]+i.dis<d[i.to]){
				d[i.to]=d[u]+i.dis;
				c[i.to]=c[i.me]+cost[i.me][i.to];
				pre[i.to]=i.me;
				if(!inq[i.to]){
					q.push(P(d[i.to],i.to));
					inq[i.to]=true;
					numinq[i.to]++;
					if(numinq[i.to]>=n) return false;
				}
			}else if(d[u]+i.dis==d[i.to]){
				if(c[i.me]+cost[i.me][i.to]<c[i.to]){
					c[i.to]=c[i.me]+cost[i.me][i.to];
					pre[i.to]=i.me;					
				}

			}
		}
	} 
	return true;
}*/
void DFS(int v){
	if(v==st){
		printf("%d ",v);
		return;
	}
//	DFS(*pre[v].begin());
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
	if(SPFA(st)){
		DFS(ed);
		printf("%d %d\n",d[ed],c[ed]);
	}
	
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
