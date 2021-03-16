#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<ctime>
#include<iomanip>
using namespace std; 
const int maxn=2*50*50+100;		//��ΪҪ��� 
const int maxm=1e6+10;
const int inf=0x3fffffff;
using LL=long long;
using pll=pair<LL,LL>;
int cnt=0;
struct Edge{
	int from,to,flow,dis,nex;
}edges[maxm*2];
int N,M,s,t,g[maxn][maxn],head[maxn];
void Add(int u,int v,int flow,int cost){
	edges[cnt].nex=head[u];
	head[u]=cnt;
	edges[cnt].from=u;
	edges[cnt].to=v;
	edges[cnt].flow=flow;
	edges[cnt].dis=cost;
	cnt++;
}
void InsertEdge(int u,int v,int flow,int cost){
	Add(u,v,flow,cost);
	Add(v,u,0,-cost);
}
int hashin(int x,int y){
	return M*x+y;
}
int hashout(int x,int y){
	return N*M+M*x+y;
}
bool SPFA(LL& flow,LL& cost){
	int d[maxn],MinF=inf,pre[maxn];
//	memset(pre,-1,sizeof(pre));
	fill(d,d+maxn,inf);
	d[s]=0;
	queue<int> q;
	q.push(s);
	bool inq[maxn]={false};
	inq[s]=true;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=false;
		for(int i=head[u];~i;i=edges[i].nex){
			Edge& e=edges[i];
			if(e.flow>0&&d[e.to]>d[e.from]+e.dis){
				d[e.to]=d[e.from]+e.dis;
				MinF=min(MinF,e.flow);
				pre[e.to]=i;
				if(!inq[e.to]){
					inq[e.to]=true;
					q.push(e.to);
				}
			}
		}
	}
	if(d[t]==inf)
		return false;
	flow+=MinF;
	cost+=MinF*1ll*d[t];
	for(int i=t;i!=s;i=edges[pre[i]].from){
		edges[pre[i]].flow-=MinF;
		edges[pre[i]^1].flow+=MinF; 
	}
	return true;
}
pll Maxflow_Mincost(){
	LL flow=0,cost=0;
	while(SPFA(flow,cost)){};
	return pll(flow,cost);
}
void clear(){
	cnt=0;
	memset(head,-1,sizeof(head));
}
int main() {
	clear();
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			scanf("%d",&g[i][j]);
		}
	}
	s=hashin(1,1)-1;
	t=hashout(N,M)+1;
	InsertEdge(s,hashin(1,1),2,0);	//����������Ͻǵĵ� 
	InsertEdge(hashout(N,M),t,2,0);	//���½ǵĵ������յ� 
	for(int i=1;i<=N;i++){
		for(int j=1;j<=M;j++){
			int from=hashin(i,j);
			int to=hashout(i,j);
			InsertEdge(from,to,1,-g[i][j]);		//��������㣬�������������������Ե�Ȩ�� 
			InsertEdge(from,to,1,0);		//�п��ܵڶ���ͨ�� 
			if(i!=N)
				InsertEdge(hashout(i,j),hashin(i+1,j),2,0);
			if(j!=M)
				InsertEdge(hashout(i,j),hashin(i,j+1),2,0); 
		}
	}
	pll ans=Maxflow_Mincost(); 
	printf("%lld\n",-ans.second);
	return 0;
}
/*
3 3
0 3 9
2 8 5
5 7 0
*/
