#include<bits/stdc++.h>
using namespace std; 
const int maxn=310;
const int inf=0x3fffffff;
struct Edge{
	int from,to,open,close,t;
	Edge(int a,int b,int c,int d,int e):from(a),to(b),open(c),close(d),t(e){};
	Edge(){}
};
int N,M,s,t,d[maxn];
vector<Edge> edges;
vector<vector<int> >G(maxn);
void InsertEdge(int u,int v,int a,int b,int t){
	G[u].push_back(edges.size());
	edges.push_back(Edge(u,v,a,b,t));
}
int getArrive(int cur_time,Edge& e){
	int temp=cur_time%(e.open+e.close);
	if(temp+e.t<=e.open)
		return cur_time+e.t;
	return cur_time+e.open+e.close-temp+e.t;
}
bool SPFA(){
	fill(d,d+maxn,inf);
	d[s]=0;
	queue<int> q;
	q.push(s);
	bool inq[maxn]={false};
	int num_inq[maxn]={0};
	num_inq[s]++;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=false;
		for(int i=0;i<G[u].size();i++){
			int& idx=G[u][i];
			Edge& e=edges[idx];
			int arrive_time=getArrive(d[u],e);
			if(d[e.to]>arrive_time){
				d[e.to]=arrive_time;
				if(!inq[e.to]){
					inq[e.to]=true;
					q.push(e.to);
					if(++num_inq[e.to]>=N)
						return false;
				}
			}
		}
	}
	return true;
} 
int main() {
	int ii=1;
	while(~scanf("%d%d%d%d",&N,&M,&s,&t)){
		edges.clear();
		fill(G.begin(),G.end(),vector<int>());
		for(int i=0;i<M;i++){
			int u,v,a,b,t;
			scanf("%d%d%d%d%d",&u,&v,&a,&b,&t);
			if(t>a)		//如果通过需要的时间大于开放的时间直接跳过 
				continue;
			InsertEdge(u,v,a,b,t);
		}
		SPFA();
		printf("Case %d: %d\n",ii++,d[t]);
	}
	return 0;
}
/*
3 2 1 3
1 2 5 6 3
2 3 7 7 6
3 2 1 3
1 2 5 6 3
2 3 9 5 6
*/
