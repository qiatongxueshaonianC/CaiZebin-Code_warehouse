#include<bits/stdc++.h> 
using namespace std;
const int maxn=510;
const int inf=0x3fffffff;
int n,m,st,ed,tolvalue=inf; 
int G[maxn][maxn],cost[maxn][maxn],d[maxn];
bool vis[maxn]={false};
vector<int> temp,ans,pre[maxn];
void Dijkstra(int s){
	fill(d,d+maxn,inf);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++){
			vis[j]==false&&d[j]<min?min=d[j],u=j:1;
		/*	if(d[j]<min){
				min=d[j];u=j;
			}*/
		}
		if(u==-1) return;
		vis[u]=true;
		for(int v=0;v<n;v++){
			if(vis[v]==false&&G[u][v]!=inf){
				if(d[u]+G[u][v]<d[v]){
					d[v]=d[u]+G[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+G[u][v]==d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
void DFS(int s){
	if(s==st){
		int val=0;
		temp.push_back(st);
	/*	vector<int> tp=temp; 
		reverse(tp.begin(),tp.end());  ////如果想要反转需要再建一个备份，否则后面的递归会受影响； 
		for(int i=0;i<tp.size()-1;i++){
			int star=tp[i],end=tp[i+1];
			val+=cost[star][end];
		}*/
		for(int i=temp.size()-1;i>0;i--){
			int id=temp[i],nextid=temp[i-1];
			val+=cost[id][nextid];
		}
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
	fill(G[0],G[0]+maxn*maxn,inf);
//	fill(cost[0],cost[0]+maxn*maxn,inf);
	int c1,c2,dis,cos;
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&c1,&c2,&dis,&cos);
		G[c2][c1]=G[c1][c2]=dis;
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
