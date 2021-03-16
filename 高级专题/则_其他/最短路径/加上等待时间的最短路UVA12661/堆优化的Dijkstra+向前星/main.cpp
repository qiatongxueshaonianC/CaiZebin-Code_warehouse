#include<bits/stdc++.h>
using namespace std;
const int maxn=310;
const int maxm=50000*2+10;
const int inf=0x3fffffff;
int cnt=0;
struct Edge{
	int from,to,open,close,time,nex;
}edges[maxm];
int N,M,s,t,head[maxn],d[maxn]; 
inline void InsertEdge(int u,int v,int a,int b,int t){
	edges[cnt].nex=head[u]; 
	head[u]=cnt;
	edges[cnt].from=u;
	edges[cnt].to=v;
	edges[cnt].open=a;
	edges[cnt].close=b;
	edges[cnt].time=t;
	cnt++;
}
void clear(){
	cnt=0;
	memset(head,-1,sizeof(head));
}
int getArrive(int cur_time,const Edge& e){
	int temp=cur_time%(e.open+e.close);
	if(temp+e.time<=e.open)
		return cur_time+e.time;
	return cur_time+e.open+e.close-temp+e.time;
}
void Dijkstra(){
	fill(d,d+maxn,inf);
	d[s]=0;
	using pii=pair<int,int>;
	priority_queue<pii,vector<pii>,greater<pii>> q;
	q.push(pii(d[s],s));
	while(!q.empty()){
		pii now=q.top();q.pop();
		int& u=now.second;
		if(d[u]!=now.first)
			continue;
		for(int i=head[u];~i;i=edges[i].nex){
			Edge& e=edges[i];
			int arrive_time=getArrive(d[u],e);
			if(d[e.to]>arrive_time){
				d[e.to]=arrive_time;
				q.push(pii(d[e.to],e.to));
			}
		}
	}
}
int main() {
	int ii=1;
	while(~scanf("%d%d%d%d",&N,&M,&s,&t)){
		clear();
		for(int i=0;i<M;i++){
			int u,v,a,b,t;
			scanf("%d%d%d%d%d",&u,&v,&a,&b,&t);
			if(t>a)
				continue;
			InsertEdge(u,v,a,b,t);
		}
		Dijkstra();
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
