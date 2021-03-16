#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=510;  //2020/2/5/21:00���֣�����Ҫ���һ��   ��100���ߣ�200�������ϣ� 
struct Edge{
	int from,to,cap,flow,cost;
	Edge(int a,int b,int c,int d,int e):from(a),to(b),cap(c),flow(d),cost(e){}
};
vector<vector<int>> G(maxn);
vector<Edge> edges;
void InsertEdge(int a,int b,int cap,int cost){
	G[a].push_back(edges.size());
	edges.push_back(Edge(a,b,cap,0,cost));
	G[b].push_back(edges.size());
	edges.push_back(Edge(b,a,0,0,-cost));
}
bool SPFA(int st,int ed,int& flow,ll& cost){
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
			//	q.push(e.to);
				if(!inq[e.to]){
					q.push(e.to);
					inq[e.to]=true;
				} 
			}
		}
	//	if(a[ed]) break; //��һ��ǧ���ܼӣ����˾ͳ�����ʱ����ѭ�� 
	}
	if(d[ed]==INT_MAX)  //���������ж϶����� 
		return false; 
//	cost+=a[ed]*1ll*d[ed];  
/*	if(!a[ed])
		return false;*/ 
	cost+=d[ed];//�����Ҿ��þ�ֱ��cost+=d[ed]Ҳ���ԣ���Ϊ��������Ϊ1����Ϊ���޽���Ļ������� 
	flow+=a[ed];    //����Ϊ����cost+=a[ed]*1ll*d[ed];������Ŀ�ı��� 
	for(int i=ed;i!=st;i=edges[p[i]].from){
		edges[p[i]].flow+=a[ed];
		edges[p[i]^1].flow-=a[ed];
	} 
	return true;
}
pair<ll,int> MinCostMaxFlow(int st,int ed){
	ll cost=0;
	int flow=0;
	while(SPFA(st,ed,flow,cost));
	return make_pair(cost,flow);
}
int main() {
	int n;
	while(scanf("%d",&n)!=EOF&&n!=0){
		int st=0,ed=2*n+1;
		for(int i=1;i<=n;i++){
			InsertEdge(st,i,1,0);
			InsertEdge(i+n,ed,1,0);
		//	InsertEdge(i,i+n,1,0);		//��������Ե�Ȩ�� 
			int v,cost;
			while(~scanf("%d",&v)&&v!=0){
				scanf("%d",&cost);
				InsertEdge(i,v+n,1,cost);	//������Ա�Ȩ�� 
			}
		}
		auto I=MinCostMaxFlow(st,ed);
		if(I.second==n) //����Ҫ�����еĵ㶼����ĳ������ÿ�����������Ϊ1����Դ��������н�����Ӧ��������Ϊn 
			printf("%lld\n",I.first);			
		else
			puts("N");
		edges.clear();
		fill(G.begin(),G.end(),vector<int>());
	} 
	return 0;
}

/*
3
2 2 3 1 0
1 1 3 2 0
1 3 2 7 0
8
2 3 3 1 0
3 3 1 1 4 4 0
1 2 2 7 0
5 4 6 7 0
4 4 3 9 0
7 4 8 5 0
6 2 5 8 8 1 0
6 6 7 2 0
3
2 1 0
3 1 0
2 1 0
0
*/
