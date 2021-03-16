#include<bits/stdc++.h>
using namespace std;
const int inf=0x3fffffff;
const int maxn=1010;
struct Node{
	int to;
	double rat,cost;
	Node(int a,double b,double c):to(a),rat(b),cost(c){}
};
vector<Node> G[maxn];
int n,m,s,numinq[maxn]; 
double v,d[maxn];
bool inq[maxn];
bool SPFA(int s){
	fill(d,d+maxn,-1.0*inf);
	fill(inq,inq+maxn,false);
	fill(numinq,numinq+maxn,0);
	d[s]=v;
	queue<int> q;
	q.push(s);
	inq[s]=true;
	numinq[s]++;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=false;
		for(auto i:G[u]){
			int v=i.to;
			double rat=i.rat,cost=i.cost;
			if((d[u]-cost)*rat>d[v]){
				d[v]=(d[u]-cost)*rat;
				if(!inq[v]){
					q.push(v);
					inq[v]=true;
					if(++numinq[v]>=n) return true;
				}
			}
		}
	}
	return false;
}
int main() {
	scanf("%d%d%d%lf",&n,&m,&s,&v);
	for(int i=0;i<m;i++){
		int u,v;
		double rab,cab,rba,cba;
		scanf("%d%d%lf%lf%lf%lf",&u,&v,&rab,&cab,&rba,&cba);
		Node node(v,rab,cab);
		G[u].push_back(node);
		node.to =u;
		node.rat =rba;
		node.cost=cba;
		G[v].push_back(node);
	}
	if(SPFA(s))puts("YES");
	else puts("NO");
	return 0;
}


/*
//poj²»Ö§³ÖC++11 
#include<stdio.h>
#include<vector>
#include<queue>
using namespace std;
const int inf=0x3fffffff;
const int maxn=1010;
struct Node{
	int to;
	double rat,cost;
	Node(int a,double b,double c):to(a),rat(b),cost(c){}
};
vector<Node> G[maxn];
int n,m,s,numinq[maxn]; 
double v,d[maxn];
bool inq[maxn];
bool SPFA(int s){
	fill(d,d+maxn,-1.0*inf);
	fill(inq,inq+maxn,false);
	fill(numinq,numinq+maxn,0);
	d[s]=v;
	queue<int> q;
	q.push(s);
	inq[s]=true;
	numinq[s]++;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=false;
		for(int j=0;j<G[u].size();j++){
                        Node i=G[u][j];			
                        int v=i.to;
			double rat=i.rat,cost=i.cost;
			if((d[u]-cost)*rat>d[v]){
				d[v]=(d[u]-cost)*rat;
				if(!inq[v]){
					q.push(v);
					inq[v]=true;
					if(++numinq[v]>=n) return true;
				}
			}
		}
	}
	return false;
}
int main() {
	scanf("%d%d%d%lf",&n,&m,&s,&v);
	for(int i=0;i<m;i++){
		int u,v;
		double rab,cab,rba,cba;
		scanf("%d%d%lf%lf%lf%lf",&u,&v,&rab,&cab,&rba,&cba);
		Node node(v,rab,cab);
		G[u].push_back(node);
		node.to =u;
		node.rat =rba;
		node.cost=cba;
		G[v].push_back(node);
	}
	if(SPFA(s))puts("YES");
	else puts("NO");
	return 0;
}
*/
