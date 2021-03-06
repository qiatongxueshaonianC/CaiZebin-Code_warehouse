#include<bits/stdc++.h>
using namespace std;
const int maxn=2010;  //1000条边，最多2000个点 
typedef long long ll;
struct Edge{
	int from,to,cap,flow,cost;
	Edge(int a,int b,int c,int d,int e):from(a),to(b),cap(c),flow(d),cost(e){}
};
vector<vector<int>> G(maxn);
vector<Edge> edges;
void InsertEdge(int f,int t,int cap,int cost){
	G[f].push_back(edges.size());
	edges.push_back(Edge(f,t,cap,0,cost));
	G[t].push_back(edges.size());
	edges.push_back(Edge(t,f,0,0,-cost));
} 
bool SPFA(int st,int ed,ll& cost,int& flow){
	int a[maxn]={0},p[maxn]={0},d[maxn];
	a[st]=INT_MAX;
	fill(d,d+maxn,INT_MAX);
	d[st]=0;
	bool inq[maxn]={false};
	queue<int> q;
	q.push(st);
	inq[st]=true;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=false;
		for(auto i:G[u]){
			Edge e=edges[i];
			if(e.cap>e.flow&&d[e.to]>d[u]+e.cost){
				d[e.to]=d[u]+e.cost;
				a[e.to]=min(a[u],e.cap-e.flow);
				p[e.to]=i;
				if(inq[e.to]==false){
					q.push(e.to);
					inq[e.to]=true;
				}
			}
		}
	}
	if(d[ed]==INT_MAX)
		return false;
	flow+=a[ed];
	cost+=d[ed]; 
//	cost+=a[ed]*1ll*d[ed]; 
	for(int i=ed;i!=st;i=edges[p[i]].from){
		edges[p[i]].flow+=a[ed];
		edges[p[i]^1].flow-=a[ed];
	}
	return true;
}
pair<ll,int> MinCostMaxFlow(int st,int ed){
	ll cost=0;
	int flow=0;
	while(SPFA(st,ed,cost,flow));
	return pair<ll,int>(cost,flow);
} 
int main() {
	int v,M;
	while(~scanf("%d%d",&v,&M)){
		InsertEdge(1,1+v,2,0);
		InsertEdge(v,v+v,2,0);
		for(int i=2;i<v;i++)
			InsertEdge(i,i+v,1,0);	//控制每个点只能使用一次 
		while(M--){
			int f,t,cost;
			scanf("%d%d%d",&f,&t,&cost);  //在这条边上，单位流量是cost； 
			InsertEdge(f+v,t,1,cost);  //2020/2/5/16:40发现，这里只能是f+v到t不然会出错 
		}  //2->(2+v),流量为1，费用为0，只有 从(2+v)出来的才能算是真的经过了这个点 
		auto I=MinCostMaxFlow(1,v+v);
		printf("%lld\n",I.first);
		fill(G.begin(),G.end(),vector<int>());
		edges.clear();
	}
	return 0;
}

/*
6 11
1 2 23
1 3 12
1 4 99
2 5 17
2 6 73
3 5 3
3 6 21
4 6 8
5 2 33
5 4 5
6 5 20

6 11
1 2 23
1 3 12
1 4 99
2 5 17
2 6 73
3 5 3
3 6 21
4 6 8
5 2 33
5 4 5
6 5 20
*/
