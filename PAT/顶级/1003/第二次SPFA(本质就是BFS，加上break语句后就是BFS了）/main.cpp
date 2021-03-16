#include<bits/stdc++.h>
using namespace std; 
const int maxn=1010;
struct Edge{
	int from,to,cap,flow;
	Edge(int a,int b,int c,int d):from(a),to(b),cap(c),flow(d){}
};
vector<vector<int>> G(maxn);
vector<Edge> edges;
map<string,int> trans;
int GetID(string s){
	if(trans.find(s)==trans.end())
		trans.insert(make_pair(s,trans.size()));
	return trans[s];
}
void InsertEdge(string a,string b,int cap){
	int from=GetID(a),to=GetID(b);
	G[from].push_back(edges.size());
	edges.push_back(Edge(from,to,cap,0));
	G[to].push_back(edges.size());
	edges.push_back(Edge(to,from,0,0));
}
bool SPFA(int st,int ed,int& flow){
	int a[maxn]={0},p[maxn]={0};
	a[st]=INT_MAX;
	queue<int> q;
	q.push(st);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(auto i:G[u]){
			Edge e=edges[i];
			if(!a[e.to]&&e.cap>e.flow){  //矩阵a同时实现了inq矩阵的作用 
				a[e.to]=min(a[u],e.cap-e.flow);  //2020/2/5/23:32发现，这是第二次了，这里写成 
				p[e.to]=i;                     	//e.cap-e.to 
				q.push(e.to);
			}
		}
		if(a[ed]) break;  //可以加速 
	}
	if(a[ed]==0)
		return false;
	for(auto i=ed;i!=st;i=edges[p[i]].from){
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
int main() {
	string st,ed;
	int n,cap;
	cin>>st>>ed>>n;
	while(n--){
		string a,b;
		cin>>a>>b>>cap;
		InsertEdge(a,b,cap);
	} 
	printf("%d\n",MaxFlow(GetID(st),GetID(ed)));
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
