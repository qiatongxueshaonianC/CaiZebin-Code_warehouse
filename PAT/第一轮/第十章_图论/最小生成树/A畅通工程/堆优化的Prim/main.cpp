#include<bits/stdc++.h> 
using namespace std;
const int inf=0x3fffffff;
const int maxn=110;
typedef pair<int,int> P; 
struct Node{
	int to,dis;
	Node(int a,int b):to(a),dis(b){}
};
int n,d[maxn];
vector<Node> G[maxn];
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
			if(dis<d[v]&&vis[v]==false){
				d[v]=dis;
				q.push(P(d[v],v));
			}
		}
	}
}
int main() {
	while(scanf("%d",&n)){
		if(n==0) break;
		int loop=n*(n-1)/2;
		int u,v,dis;
		for(int i=0;i<loop;i++){
			scanf("%d%d%d",&u,&v,&dis);
			Node node(v,dis);
			G[u].push_back(node);
			node.to=u;
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
