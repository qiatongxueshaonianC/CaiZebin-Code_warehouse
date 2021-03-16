#include<bits/stdc++.h> 
using namespace std;
const int maxn=510;
const int inf=0x3fffffff;
typedef pair<int,int> P;
struct Node{
	int to,dis,me;
	Node(int a,int b,int c){
		to=a;dis=b;me=c;
	}
};
int n,m,st,ed,weight[maxn]; 
int d[maxn],w[maxn],num[maxn],numinq[maxn];
vector<Node> G[maxn];
set<int> pre[maxn];
bool vis[maxn];
void Dijkstra(int s){
	fill(d,d+maxn,inf);
	fill(w,w+maxn,0);
	fill(num,num+maxn,0);
	fill(vis,vis+maxn,false);
	d[s]=0;
	w[s]=weight[s];
	num[s]=1;
	priority_queue<P,vector<P>,greater<P> >q;
	q.push(P(0,s));
	while(!q.empty()){
		P now=q.top();q.pop();
		int u=now.second;
		if(now.first>d[u]) continue;
		vis[u]=true; 
		for(auto i:G[u]){
			int v=i.to,dis=i.dis;
			if(vis[v]==false){
			
			if(d[u]+dis<d[v]){
				d[v]=d[u]+dis;
				w[v]=w[u]+weight[v];
				q.push(P(d[v],v));
				num[v]=num[u];
				pre[v].clear();
				pre[v].insert(u);
			}else if(d[u]+dis==d[v]){
				pre[v].insert(u);
				if(w[u]+weight[v]>w[v]){
					w[v]=w[u]+weight[v];
				}
				num[v]=0;
				for(auto k:pre[v])
					num[v]+=num[k];
			}
		}
		}
	}
}
int main() {
	int c1,c2,dis;
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&c1,&c2,&dis);
		Node node(c2,dis,c1);
		G[c1].push_back(node);
		node.to =c1;
		node.me =c2;
		G[c2].push_back(node);
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
