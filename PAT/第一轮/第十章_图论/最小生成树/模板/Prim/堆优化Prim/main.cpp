#include<bits/stdc++.h> 
using namespace std;
const int maxn=1010;
const int inf=0x3fffffff;
typedef pair<int,int> P;
struct Node{
	int to,dis;
	Node(int a,int b):to(a),dis(b){}
}; 
int n,m,d[maxn];
vector<Node> G[maxn];
bool vis[maxn]; 
void Prim(int s){
	fill(d,d+maxn,inf);
	d[s]=0;
	priority_queue<P,vector<P>,greater<P> >q;
	q.push(P(0,s));
	while(!q.empty()){
		P now=q.top();q.pop();
		int u=now.second;
		if(now.first>d[u]) continue;
	//	vis[u]=true;
		for(auto i:G[u]){
			int v=i.to,dis=i.dis;
		//	if(dis<d[v]&&vis[v]==false){
			if(dis<d[v]){
				d[v]=dis;
				q.push(P(d[v],v));
			}
		}
	}
}

int main() {
	int u,v,dis;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&dis);
		Node node(v,dis);
		G[u].push_back(node);
		node.to =u;
		G[v].push_back(node); 
	}
	Prim(1);
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=d[i];
	}
	printf("%d\n",ans);
	return 0;
}
/*
6 10
0 1 4
0 4 1
0 5 2
1 2 6
1 5 3
2 3 6
2 5 5
3 4 4
3 5 5
4 5 3
*/

/*
4 6
0 1 1
0 2 5
0 3 2
1 2 2
1 3 4 
2 3 3
*/ 
