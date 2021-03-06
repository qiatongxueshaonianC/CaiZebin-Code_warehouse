#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int inf=0x3fffffff;
struct Node{
	int to,dis[2];
	Node(int a,int b,int c){
		to=a;
		dis[0]=b;dis[1]=c;
	}
	Node(){}
};
int n,m,st,ed,shortest=inf,fast=inf,d[2][maxn];
bool vis[maxn];
vector<Node> G[maxn];
vector<int> temp,ans[2];
vector<vector<int>>pre(maxn),ppre(maxn);
int harsh[maxn][maxn];
void Dijkstra(int s,int flag){
	d[0][st]=d[1][st]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=inf; 
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[flag][j]<min){
				min=d[flag][j];
				u=j;
			}
		}
		if(u==-1) return;
		vis[u]=1;
		for(auto i:G[u]){
			int v=i.to,dis=i.dis[flag];
			if(vis[v]==false){
				if(d[flag][u]+dis<d[flag][v]){
					d[flag][v]=d[flag][u]+dis;
					if(flag==0){
						d[1][v]=d[1][u]+i.dis[1];
					}
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[flag][u]+dis==d[flag][v]){
					pre[v].push_back(u);
					if(flag==0){
						d[1][v]=d[1][u]+i.dis[1];
					}
				}
			}
		}
	} 
}
void DFS(int s,int flag){
	if(s==st){
		temp.push_back(s);
		int length=0,time=0;
		for(int i=temp.size()-1;i>=0;i--){
			int id=temp[i],next=temp[i-1];
			length+=d[0][temp[i]];
			time=i-1>=0?time+harsh[id][next]:time;
		}
		if(flag==0){  //ѡ???? 
			if(length<shortest){
				time=fast; 
				shortest=length;
				ans[0]=temp;
			}else if(length==shortest&&time<fast){
				fast=time;
				ans[0]=temp;
			}
		}else{  //?ȿ? 
			if(time<fast){
				fast=time;
				ans[1]=temp;
			}else if(time==fast&&temp.size()<ans[1].size()){
				ans[1]=temp;
			}
		}
		temp.pop_back();
		return;
	}
	temp.push_back(s);
	for(auto i:pre[s]){
		DFS(i,flag);
	}
	temp.pop_back();
}
void output(int k){
	for(int i=ans[k].size()-1;i>=0;i--)
		printf("%d%s",ans[k][i],i==0?"\n":" -> ");
}
int main() {
	scanf("%d%d",&n,&m);
	int a,b,c,x,e;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d%d",&a,&b,&c,&x,&e);
		G[a].push_back(Node(b,x,e));
		harsh[a][b]=e;
		if(c==0){
			G[b].push_back(Node(a,x,e));
			harsh[b][a]=e;
		}
	}
	scanf("%d%d",&st,&ed);
	for(int i=0;i<2;i++){
		pre=ppre;
		shortest=inf;fast=inf;
		fill(vis,vis+maxn,false);
		fill(d[i],d[i]+maxn,inf);
		Dijkstra(st,i);
		DFS(ed,i);		
	}
	if(ans[0]==ans[1]){
		printf("Distance = %d; Time = %d: ",d[0][ed],d[1][ed]);
		output(1);
	}else{
		printf("Distance = %d: ",d[0][ed]);
		output(0);
		printf("Time = %d: ",d[1][ed]);
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
