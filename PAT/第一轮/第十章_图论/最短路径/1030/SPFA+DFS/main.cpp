#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
const int inf=0x3fffffff;
struct Node{
	int to,dis;
	Node(int a,int b){
		to=a;dis=b;
	}
};
int n,m,st,ed,num,numinq[maxn]; 
vector<Node> G[maxn];
vector<int>temp,ans;
set<int> pre[maxn];
int cost[maxn][maxn],d[maxn];
int minvalue=inf;
bool inq[maxn];
bool SPFA(int s){
	fill(d,d+maxn,inf);
	fill(inq,inq+maxn,false);
	d[s]=0;
	queue<int> q;
	q.push(s);
	numinq[s]++;
	inq[s]=true;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[s]=false;
		for(auto i:G[u]){
			int v=i.to,dis=i.dis;
			if(d[u]+dis<d[v]){
				d[v]=d[u]+dis;
				pre[v].clear();
				pre[v].insert(u);
				if(!inq[v]){
					q.push(v);
					inq[v]=true;
					numinq[v]++;
					if(numinq[v]>=n) return false;
				}
			}else if(d[u]+dis==d[v])
					pre[v].insert(u);
		}
	}
	return true;
}
void DFS(int s){
	if(s==st){
		int val=0;
		temp.push_back(st);
		for(int i=temp.size()-1;i>0;i--){
			int id=temp[i],nextid=temp[i-1];
			val+=cost[id][nextid];
		}
		if(val<minvalue){
			minvalue=val;
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
		cost[c1][c2]=cost[c2][c1]=cos;
		Node node(c2,dis);
		G[c1].push_back(node);
		node.to =c1;
		G[c2].push_back(node);
	}
	SPFA(st);
	DFS(ed);
	reverse(ans.begin(),ans.end());
	for(auto i:ans)
		printf("%d ",i);
	printf("%d %d\n",d[ed],minvalue);
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
