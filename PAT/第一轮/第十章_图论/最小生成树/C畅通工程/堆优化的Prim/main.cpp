#include<bits/stdc++.h> 
using namespace std;
const int inf=0x3fffffff;
const int maxn=110;
typedef pair<int,int> P;
struct Node{
	int to,dis;
	Node(int a,int b):to(a),dis(b){}
}; 
vector<Node> G[maxn];
int n,m,d[maxn];
bool vis[maxn];
bool Prim(int s){
	fill(d,d+maxn,inf);
	fill(vis,vis+maxn,false);
	d[s]=0;
	priority_queue<P,vector<P>,greater<P> > q;
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
	if(count(vis+1,vis+n+1,false)==0) return true;
/*	for(int i=1;i<=n;i++)
		if(vis[i]==false) return false;*/
	return false;
}
int main() {
	while(scanf("%d%d",&m,&n)){
		if(m==0) break;
		int u,v,dis;
		for(int i=0;i<m;i++){
			scanf("%d%d%d",&u,&v,&dis);
			Node node(v,dis);
			G[u].push_back(node);
			node.to =u;
			G[v].push_back(node);
		}
		if(!Prim(1)) puts("?");
		else {
			int ans=0;
			for(int i=1;i<=n;i++)
				ans+=d[i];
			printf("%d\n",ans);
			
		}
		for(int i=1;i<=n;i++){
			G[i].clear();
		}
	}
	return 0;
}
/*
3 4
1 2 1
2 3 2
3 4 3
2 4
1 2 1
3 4 2
0 5
*/
