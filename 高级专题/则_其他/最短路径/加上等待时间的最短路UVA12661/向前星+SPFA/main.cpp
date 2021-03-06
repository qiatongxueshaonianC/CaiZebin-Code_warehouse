#include<bits/stdc++.h>
using namespace std;
const int maxn=310;
const int maxm=50000*2+10;
const int inf=0x3fffffff;
int cnt=0;
struct Edge{
	int from,to,open,close,t,nex;
}edges[maxm];
int N,M,s,t,head[maxn],d[maxn]; 
inline void InsertEdge(int u,int v,int a,int b,int t){
	edges[cnt].nex=head[u];
	head[u]=cnt;
	edges[cnt].from=u;
	edges[cnt].to=v;
	edges[cnt].open=a;
	edges[cnt].close=b;
	edges[cnt].t=t;
	cnt++;
}
int getArrive(int cur_time,const Edge& e){
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
	inq[s]=true;
	int num_inq[maxn]={0};
	num_inq[s]++;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=false;
		for(int i=head[u];i!=-1;i=edges[i].nex){
			Edge& e=edges[i];
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
void clear(){
	memset(head,-1,sizeof(head));cnt=0;
}
int main() {
	int ii=1;
	while(~scanf("%d%d%d%d",&N,&M,&s,&t)){
		clear();
		for(int i=0;i<M;i++){
			int u,v,a,b,t;
			if(t>a)
				continue;
			scanf("%d%d%d%d%d",&u,&v,&a,&b,&t);
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
