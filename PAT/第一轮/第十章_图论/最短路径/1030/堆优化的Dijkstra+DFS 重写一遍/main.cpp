#include<bits/stdc++.h> 
using namespace std;
const int maxn=510;
const int inf=0x3fffffff;
typedef pair<int,int> P;
struct Node{
	int to,dis,me;
	Node(int a,int b,int c){
		to=a;dis=b;me=c;
	}
	Node(){}
};
int d[maxn],cost[maxn][maxn];
int n,m,st,ed,minvalue=inf; 
vector<Node> G[maxn];
vector<int> temp,ans,pre[maxn];
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
			if(d[u]+i.dis<d[i.to]){
				d[i.to]=d[u]+i.dis;
				q.push(P(d[i.to],i.to));
				pre[i.to].clear();
				pre[i.to].push_back(i.me);
			}else if(d[u]+i.dis==d[i.to]){
				//q.push(P(d[i.to],i.to));
				pre[i.to].push_back(i.me);
			}
		}
	}
}
void DFS(int s){
	if(s==st){
		int val=0;
		temp.push_back(s);
		for(int i=temp.size()-1;i>0;i--){
			int id=temp[i],nextid=temp[i-1];
			val+=cost[id][nextid];
		}
		if(val<minvalue){
			ans=temp;
			minvalue=val;
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
	int c1,c2,dis,cos;
	scanf("%d%d%d%d",&n,&m,&st,&ed);
	for(int i=0;i<m;i++){
		scanf("%d%d%d%d",&c1,&c2,&dis,&cos);
		cost[c1][c2]=cost[c2][c1]=cos;
		Node node(c2,dis,c1);
		G[c1].push_back(node);
		node.to=c1;
		node.me=c2;
		G[c2].push_back(node);
	}
	Dijkstra(st);
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
