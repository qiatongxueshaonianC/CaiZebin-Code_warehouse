#include<bits/stdc++.h>
using namespace std; 
const int maxn=110;
const int inf=0x3fffffff;
typedef pair<int,int>P;
struct Node{
	int to,dis;
	Node(int a,int b):to(a),dis(b){}
};
vector<Node> G[maxn];
int n,d[maxn];
bool vis[maxn];
void Prim(int s){
	fill(d,d+maxn,inf);
	fill(vis,vis+maxn,false);
	d[s]=0;
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
				if(dis<d[v]){
					d[v]=dis;
					q.push(P(d[v],v));
				}
			}
		}
	}
}
int main() {
	while(scanf("%d",&n)){
		if(n==0) break;
		int u,v,dis,flag;
		int loop=n*(n-1)/2;
		for(int i=0;i<loop;i++){
			scanf("%d%d%d%d",&u,&v,&dis,&flag);
			if(flag==1) dis=0;
			Node node(v,dis);
			G[u].push_back(node);
			node.to =u;
			G[v].push_back(node);
		}
		Prim(1);
		int ans=0;
		for(int i=1;i<=n;i++)
			ans+=d[i];
		printf("%d\n",ans);
		for(int i=0;i<=n;i++)
			G[i].clear(); 
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
