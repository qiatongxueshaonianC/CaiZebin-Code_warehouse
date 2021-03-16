#include<bits/stdc++.h>
using namespace std;
const int inf=0x3fffffff; 
const int maxn=110;
struct Node{
	int to,dis;
	Node(int a,int b):to(a),dis(b){}
}; 
vector<Node> G[maxn];
int n,m,numinq[maxn],d[maxn];
bool inq[maxn];
bool SPFA(int s){
	fill(d,d+maxn,inf);
	fill(inq,inq+maxn,false);
	fill(numinq,numinq+maxn,0);
	queue<int> q;
	d[s]=0; 
	q.push(s);
	inq[s]=true;
	numinq[s]++;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=false;
		for(auto i:G[u]){
			int v=i.to,dis=i.dis;
			if(d[u]+dis<d[v]){
				d[v]=d[u]+dis;
				if(!inq[v]){
					q.push(v);
					inq[v]=true;
					numinq[v]++;
					if(numinq[v]>=n) return false;
				}
			}
			
		}
	}
	return true;
}
int main() {
	while(scanf("%d%d",&n,&m)){
		if(n==0) break;
		int u,v;
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			Node node(v,-1);
			G[u].push_back(node);
		}
		if(SPFA(0)) puts("YES");
		else puts("NO");
		for(int i=0;i<=n;i++)
			G[i].clear();
	}
	return 0;
}
/*
4 3
0 1
1 2
2 3
3 3
0 1
1 2
2 0
0 1
*/
