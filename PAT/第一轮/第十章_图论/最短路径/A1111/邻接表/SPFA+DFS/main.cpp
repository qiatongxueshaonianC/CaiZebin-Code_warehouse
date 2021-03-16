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
int n,m,st,ed,shortest=inf,fast=inf,d[2][maxn],num_inq[maxn];
bool inq[maxn];
vector<Node> G[maxn];
vector<int> temp,ans[2];
vector<unordered_set<int>> pre(maxn),ppre(maxn);
bool SPFA(int s,int flag){
	fill(d[flag],d[flag]+maxn,inf);
	d[flag][s]=0;
	queue<int> q;
	q.push(s);
	inq[s]=true;
	num_inq[s]++;
	while(q.size()){
		int u=q.front();q.pop();
		inq[u]=0;
		for(auto i:G[u]){
			int v=i.to,dis=i.dis[flag];
			if(d[flag][u]+dis<d[flag][v]){
				d[flag][v]=d[flag][u]+dis;
				pre[v].clear();
				pre[v].insert(u);
				if(!inq[v]){
					q.push(v);
					inq[v]=true;
					if(++num_inq[v]>=n) return false;
				}
			}else if(d[flag][u]+dis==d[flag][v]){
				pre[v].insert(u);
				if(!inq[v]){
					q.push(v);
					inq[v]=true;
					if(++num_inq[v]>=n) return false;
				}
			}
		}
	}
}
void DFS(int s,int flag){
	if(s==st){
		temp.push_back(s);
		int len=0,time=0;
		for(auto i:temp){
			len+=d[0][i];
			time+=d[1][i];
		}
		if(flag==0){
			if(len<shortest){
				fast=time;
				shortest=len;
				ans[0]=temp;
			}else if(len==shortest&&time<fast){
				fast=time;
				ans[0]=temp;
			}
		}else{
			if(time<fast){
				fast=time;
				ans[1]=temp;
			}else if(time==fast&&ans[1].size()>temp.size()){
				ans[1]=temp;
			}
		}
		temp.pop_back();
		return;
	}
	temp.push_back(s);
	for(auto i:pre[s])
		DFS(i,flag);
	temp.pop_back();
}
void output(int s){
	for(int i=ans[s].size()-1;i>=0;i--)
		printf("%d%s",ans[s][i],i==0?"\n":" -> ");
}
int main() {
	scanf("%d%d",&n,&m);
	int a,b,c,x,e;
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d%d",&a,&b,&c,&x,&e);
		G[a].push_back(Node(b,x,e));
		if(c==0) G[b].push_back(Node(a,x,e));
	}
	scanf("%d%d",&st,&ed);
	for(int i=0;i<2;i++){
		fast=shortest=inf;
		fill(num_inq,num_inq+maxn,0);
		fill(inq,inq+maxn,false);
		SPFA(st,i);
		DFS(ed,i);
	}
	if(ans[0]==ans[1]){
		printf("Distance = %d; Time = %d: ",d[0][ed],d[1][ed]);
		output(0);
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
