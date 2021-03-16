#include<bits/stdc++.h>
using namespace std; 
const int maxn=510;
const int inf=0x3fffffff;
struct Node{
	int to,dis;
	Node(int a,int b):to(a),dis(b){}
};
int w[maxn],d[maxn],weight[maxn];
int cap,n,ed,m,u,v,dis,minneed=inf,minback=inf;
vector<Node> G[maxn];
set<int> pre[maxn];
bool vis[maxn];
vector<int> temp,ans;
void Dijkstra(int s){
	fill(vis,vis+maxn,false);
//	fill(w,w+maxn,0);
	fill(d,d+maxn,inf);
	d[s]=0;
	for(int i=0;i<=n;i++){
		int u=-1,min=inf;
		for(int j=i;j<=n;j++){
			if(d[j]<min&&vis[j]==false){
				min=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(auto i:G[u]){
			int v=i.to,dis=i.dis;
			if(vis[v]==true) continue;
			if(d[u]+dis<d[v]){
				d[v]=d[u]+dis;
				pre[v].clear();
				pre[v].insert(u);
			}else if(d[u]+dis==d[v]){
				pre[v].insert(u);
			}
		}
	}
}
void DFS(int s){
	if(s==0){
		temp.push_back(s);
		int need=0,back=0;
		for(int i=temp.size()-1;i>=0;i--){
			int id=temp[i];
			if(weight[id]>=0){
				back+=weight[id];
			}else{
				if(back>=abs(weight[id])){
					back-=abs(weight[id]);
				}else{
					need+=abs(back-abs(weight[id]));
					back=0;
				}
			}
		}
		if(need<minneed){
			ans=temp;
			minneed=need;
			minback=back;
		}else if(need==minneed&&back<minback){
			minback=back;
			ans=temp;
		}
		temp.pop_back();
		return;
	}
	temp.push_back(s);
	for(auto i:pre[s])
		DFS(i);
	temp.pop_back();
}
int main() {
	scanf("%d%d%d%d",&cap,&n,&ed,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&weight[i]);
		weight[i]-=cap/2;
	}
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&dis);
		G[u].push_back(Node(v,dis));
		G[v].push_back(Node(u,dis));
	}
	Dijkstra(0);
	DFS(ed);
	printf("%d ",minneed);
	for(int i=ans.size()-1;i>=0;i--)
		printf("%d%s",ans[i],i==0?"":"->");
	printf(" %d",minback);
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
