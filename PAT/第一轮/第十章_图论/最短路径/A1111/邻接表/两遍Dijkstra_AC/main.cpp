#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int inf=0x3fffffff;
struct Node{
	int to,dis;
	Node(int a,int b):to(a),dis(b){}
	Node(){}
};
int n,m,st,ed,Time[maxn][maxn],pre_d[maxn],pre_t[maxn],num[maxn],d[maxn],t[maxn];
vector<int> ans[2];
vector<Node> G[maxn];
bool vis[maxn];
void Dijkstra_dis(int s){
	fill(d,d+maxn,inf);
	fill(t,t+maxn,inf);
	d[st]=0;t[st]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<min){
				u=j;
				min=d[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(auto i:G[u]){
			int v=i.to,dis=i.dis;
			if(vis[v]==false){
				if(d[u]+dis<d[v]){
					d[v]=d[u]+dis;
					t[v]=t[u]+Time[u][v];
					pre_d[v]=u;
				}else if(d[u]+dis==d[v]&&t[u]+Time[u][v]<t[v]){
					pre_d[v]=u;
					t[v]=t[u]+Time[u][v];
				}
			}
		}
	}
}
void Dijkstra_time(int s){
	fill(t,t+maxn,inf);
	fill(vis,vis+maxn,false);
	t[st]=0;num[st]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&t[j]<min){
				u=j;
				min=t[j];
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(auto i:G[u]){
			int v=i.to,time=Time[u][v];
			if(vis[v]==false){
				if(t[u]+time<t[v]){
					t[v]=t[u]+time;
					num[v]=num[u]+1;
					pre_t[v]=u;
				}else if(t[u]+time==t[v]&&num[u]+1<num[v]){
					pre_t[v]=u;
					num[v]=num[u]+1;
				}
			}
		}
	}
}
void DFS(int s,int flag){
	if(s==st){
		if(flag==0) ans[flag].push_back(s);
		else ans[flag].push_back(s);
		return;
	}
	DFS(flag==0?pre_d[s]:pre_t[s],flag);
	if(flag==0) ans[flag].push_back(s);
	else ans[flag].push_back(s);
}
void output(int k){
	for(int i=0;i<ans[k].size();i++)
		printf("%d%s",ans[k][i],i==ans[k].size()-1?"\n":" -> ");
}
int main() {
	scanf("%d%d",&n,&m);
	int a,b,c,x,e;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d%d",&a,&b,&c,&x,&e);
		G[a].push_back(Node(b,x));
		Time[a][b]=e;
		if(c==0) {
			G[b].push_back(Node(a,x));
			Time[b][a]=e;
		}
	}
	scanf("%d%d",&st,&ed);
	Dijkstra_dis(st);
	DFS(ed,0);
	Dijkstra_time(st);
	DFS(ed,1);
	if(ans[0]==ans[1]){
		printf("Distance = %d; Time = %d: ",d[ed],t[ed]);
		output(1);
	}else{
		printf("Distance = %d: ",d[ed]);
		output(0);
		printf("Time = %d: ",t[ed]);
		output(1);
	}
	return 0;
}
/*
10 15
0 1 0 1 1
8 0 0 1 1
4 8 1 1 1
3 4 0 3 2
3 9 1 4 1
0 6 0 1 1
7 5 1 2 1
8 5 1 2 1
2 3 0 2 2
2 1 1 1 1
1 3 0 3 1
1 4 0 1 1
9 7 1 3 1
5 1 0 5 2
6 5 1 1 2
3 5

7 9
0 4 1 1 1
1 6 1 1 3
2 6 1 1 1
2 5 1 2 2
3 0 0 1 1
3 1 1 1 3
3 2 1 1 2
4 5 0 2 2
6 5 1 1 2
3 5
*/
