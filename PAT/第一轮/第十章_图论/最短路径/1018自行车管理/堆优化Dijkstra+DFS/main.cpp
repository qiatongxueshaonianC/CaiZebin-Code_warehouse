#include<bits/stdc++.h>
using namespace std;
const int inf=0x3fffffff;
const int maxn=510;
typedef pair<int,int> P;
struct Node{
	int to,dis;
	Node(int a,int b){
		to=a;dis=b;
	}
	Node(){}
};
vector<Node>G[maxn];
set<int> pre[maxn];
vector<int> temp,ans;
int cmax,n,st,ed,m,minneed=inf,minback=inf; 
int d[maxn],weight[maxn];
bool vis[maxn]={false};
void Dijkstra(int s){
	fill(d,d+maxn,inf);
	d[s]=0;
	priority_queue<P,vector<P>,greater<P> >q;
	q.push(P(0,s));
	while(!q.empty()){
		P now=q.top();q.pop();
		int u=now.second;
		if(now.first>d[u]) continue;
		vis[u]=true; 
		for(auto i:G[u]){
			int v=i.to,dis=i.dis;
			if(vis[v]==false){

  				if(d[u]+dis<d[v]){
					d[v]=d[u]+dis;
					q.push(make_pair(d[v],v));
					pre[v].clear();
					pre[v].insert(u);
				}else if(d[u]+dis==d[v])
						pre[v].insert(u);
			}
		}
	}
}
void DFS(int s){
	if(s==st){
		temp.push_back(s);
		int need=0,remain=0;
		for(int i=temp.size()-1;i>=0;i--){
			int id=temp[i];
			if(weight[id]>0){
				remain+=weight[id];
			}else if(weight[id]<0){
				if(remain>=abs(weight[id])){
					remain+=weight[id];
				}else{
					need+=(abs(weight[id])-remain);
					remain=0;
				}
			}
		}
		if(need<minneed){
			minneed=need;
			minback=remain;
			ans=temp;
		}else if(need==minneed&&minback>remain){
			minback=remain;
			ans=temp;
		}
		temp.pop_back();
	}else{
		temp.push_back(s);
		for(auto i:pre[s])
			DFS(i);
		temp.pop_back();
	} 
}
int main() {
	int c1,c2,dis;
	scanf("%d%d%d%d",&cmax,&n,&ed,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&weight[i]);
		weight[i]-=cmax/2;
	}
	while(m--){
		scanf("%d%d%d",&c1,&c2,&dis);
		Node node(c2,dis);
		G[c1].push_back(node);
		node.to =c1;
		G[c2].push_back(node);
	}
	st=0;
	Dijkstra(st);
	DFS(ed);
	printf("%d ",minneed);
	reverse(ans.begin(),ans.end());
	for(auto i:ans){
		printf("%d",i);
		if(i!=*(ans.end()-1)) printf("->");
	}
	printf(" %d\n",minback);
	return 0;
}
/*
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
*/
