#include<bits/stdc++.h> 
using namespace std;
const int maxn=510;
const int inf=0x3fffffff;
struct Node{
	int to,dis;
	Node(int a,int b){
		to=a;dis=b;
	}
	Node(){};
};
typedef pair<int,int> P;
int n,m,st,ed,tolvalue=inf; 
int d[maxn],cost[maxn][maxn];
vector<Node> G[maxn];
bool vis[maxn]={false};
vector<int> temp,ans,pre[maxn];
int w[maxn],weight[maxn];
void Dijkstra(int s){
	priority_queue<P,vector<P>,greater<P> >q;
	fill(d,d+maxn,inf);
	d[s]=0;
	q.push(P(0,s));
	while(!q.empty()){
		P now=q.top();q.pop();
		int u=now.second;
		if(now.first>d[u]) continue;
		for(auto i:G[u]){
			int v=i.to,dis=i.dis;
				if(d[u]+dis<d[v]){
					d[v]=d[u]+dis;
					q.push(P(d[v],v));
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+dis==d[v]){
					pre[v].push_back(u);
				}
			}
	}
}
void DFS(int s){
	if(s==st){
		int val=0;
		//int weit=0;
		temp.push_back(st);
		for(int i=temp.size()-1;i>0;i--){
			int id=temp[i],nextid=temp[i-1];
			val+=cost[id][nextid];
		}
	/*	for(int i=temp.size()-1;i>=0;i--){
			weit+=weight[i];
		}*/
		if(val<tolvalue){
			tolvalue=val;
			ans=temp;
		}
		temp.pop_back();
	}else{
		temp.push_back(s);
		for(auto i:pre[s]){
			DFS(i);
		}
		temp.pop_back();
	}
}

int main() {
	int c1,c2,dis,cos;
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&c1,&c2,&dis,&cos);
		Node node(c2,dis);
		G[c1].push_back(node);
		node.to =c1;
		G[c2].push_back(node);
		cost[c1][c2]=cost[c2][c1]=cos; 
	}
	Dijkstra(st);
	DFS(ed);
	reverse(ans.begin(),ans.end());
	for(auto i:ans)
		printf("%d ",i);
	printf("%d %d\n",d[ed],tolvalue);
	return 0;
}
/*
4 5 0 3
0 1 1 20
1 3 2 30
0 3 4 10
0 2 2 20
2 3 1 20
*/
