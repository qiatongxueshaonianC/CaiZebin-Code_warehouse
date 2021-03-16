#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
string from,to,s;
struct Edge{
	int from,to,cap,flow;
	Edge(int a,int b,int c,int d):from(a),to(b),cap(c),flow(d){}
};
vector<vector<int>> G(maxn),ID(3);
map<string,int> trans;
vector<Edge> edges;
int Num[3][maxn];
int GetID(string s,int idx){
	if(trans.find(s)==trans.end())
		trans.insert(make_pair(s,trans.size()));
	ID[idx].push_back(trans[s]);
	Num[idx][trans[s]]++;
	return trans[s];
}
void InsertEdge(int u,int v,int cap){
	G[u].push_back(edges.size());
	edges.push_back(Edge(u,v,cap,0));
	G[v].push_back(edges.size());
	edges.push_back(Edge(v,u,0,0));
}
bool SPFA(int st,int ed,int& flow){
	int a[maxn]={0},p[maxn]={0};
	a[st]=INT_MAX;
	bool inq[maxn]={false};
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto i:G[u]){
			Edge e=edges[i];
			if(!a[e.to]&&e.cap>e.flow){
				a[e.to]=min(a[u],e.cap-e.flow);
				p[e.to]=i;
				if(!inq[e.to]){
					q.push(e.to);
					inq[e.to]=true;
				}
			}
		}
		if(a[ed]!=0) break;
	}
	if(a[ed]==0)
		return false;
	for(int i=ed;i!=st;i=edges[p[i]].from){
		edges[p[i]].flow+=a[ed];
		edges[p[i]^1].flow-=a[ed];
	}
	flow+=a[ed];
	return true;
}
int MaxFlow(int st,int ed){
	int flow=0;
	while(SPFA(st,ed,flow));
	return flow;
}
int main(){
	int N,k,m;
	scanf("%d",&N);
	for(int ii=1;ii<=N;ii++){
		printf("%s",ii>1?"\n":"");
		scanf("%d",&k);
		while(k--){
			cin>>s;
			GetID(s,0);
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){
			cin>>to>>s;
			GetID(s,1);
		}
		scanf("%d",&k);
		while(k--){
			cin>>from>>to;
			int u=GetID(from,2),v=GetID(to,2);
			InsertEdge(u,v,INT_MAX); 
		}
		int st=trans.size()+10,ed=trans.size()+20;
		for(auto i:ID[1])    //2020/2/4/16:12���֣�����һ��Ҫ��Ҫ��Դ�������ǲ�ͷ�����豸�� 
			InsertEdge(st,i,Num[1][i]); 
		for(auto i:ID[0])
			InsertEdge(i,ed,Num[0][i]);
		printf("%d\n",m-MaxFlow(st,ed));
		edges.clear();trans.clear();
		fill(G.begin(),G.end(),vector<int>());
		fill(ID.begin(),ID.end(),vector<int>());
		fill(Num[0],Num[0]+3*maxn,0);
	} 
    return 0;
}
/*
2
4
A
B
C
D
5
laptop B
phone C
pager B
clock B
comb X
3
B X
X A
X D

4
A
B
C
D
5
laptop B
phone C
pager B
clock B
comb X
3
B X
X A
X D
*/ 
