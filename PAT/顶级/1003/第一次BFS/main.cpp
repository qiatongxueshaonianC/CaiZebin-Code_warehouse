#include<bits/stdc++.h>
using namespace std; 
const int maxn=1010;  //500�У����1000���� 
map<string,int> trans;
int N,cap;
string st,ed,f,t;
struct Edge{
	int from,to,cap,flow;
	Edge(int a,int b,int c,int d):from(a),to(b),cap(c),flow(d){}
};
vector<vector<int>> G(maxn);
vector<Edge> edge;
int GetID(string s){
	if(trans.find(s)==trans.end()){
		int temp=trans.size();
		trans[s]=temp;
	}
	return trans[s];
}
void InsertEdge(int cap){
	int u1=GetID(f);
	int v1=GetID(t);
	G[u1].push_back(edge.size());
	edge.push_back(Edge(u1,v1,cap,0));
	G[v1].push_back(edge.size());
	edge.push_back(Edge(v1,u1,0,0));
}
int Max_Flow(int st,int ed){
	int a[maxn]={0},p[maxn]={0},flow=0;
	while(true){
		memset(a,0,sizeof(a));
		queue<int> q;
		q.push(st);
		a[st]=INT_MAX;
		while(!q.empty()){
			int u=q.front();q.pop();
			for(auto i:G[u]){
				Edge e=edge[i];
				if(!a[e.to]&&e.cap>e.flow){
					p[e.to]=i;
					a[e.to]=min(a[u],e.cap-e.flow);
					q.push(e.to);
				}
			}
			if(a[ed])
				break;
		}
		if(!a[ed])
			break;
		for(int i=ed;i!=st;i=edge[p[i]].from){
			edge[p[i]].flow+=a[ed];
			edge[p[i]^1].flow-=a[ed];
		}
		flow+=a[ed];
	}
	return flow;
}
int main() {
	cin>>st>>ed>>N;
	for(int i=0;i<N;i++){
		cin>>f>>t>>cap;
		InsertEdge(cap);
	}
	printf("%d",Max_Flow(GetID(st),GetID(ed)));
	return 0;
}
/*
EAR MAR 11
EAR AAA 300
EAR BBB 400
AAA BBB 100
AAA CCC 400
AAA MAR 300
BBB DDD 400
AAA DDD 400
DDD AAA 100
CCC MAR 400
DDD CCC 200
DDD MAR 300
*/
