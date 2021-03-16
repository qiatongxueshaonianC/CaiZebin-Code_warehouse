#include<bits/stdc++.h> 
using namespace std;
const int maxn=1010;
const int inf=0x3fffffff;
struct Node{
	int to,dis;
	Node(int a,int b):to(a),dis(b){}
};
vector<Node> G[maxn];
int n,m,d[maxn];
bool inq[maxn]; 
void Prim(int s){
	fill(d,d+maxn,inf);
	fill(inq,inq+maxn,false);
	d[s]=0;
	queue<int> q;
	q.push(s);
	inq[s]=true;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=false;
		for(auto i:G[u]){
			int v=i.to,dis=i.dis;
			if(dis<d[v]){
				d[v]=dis;
				if(!inq[v]){
					q.push(v);
					inq[v]=true;
				}
			}
		}
	}
}
int main() {
	int u,v,dis;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++){
		scanf("%d%d%d",&u,&v,&dis);
		Node node(v,dis);
		G[u].push_back(node);
		node.to=u;
		G[v].push_back(node);
	}
	Prim(2);
	int ans=0;
	for(int i=0;i<n;i++){
		ans+=d[i];
	}
	printf("%d\n",ans);
	return 0;
}
/*
6 10
0 1 4
0 4 1
0 5 2
1 2 6
1 5 3
2 3 6
2 5 5
3 4 4
3 5 5
4 5 3
*/

/*
4 6
0 1 1
0 2 5
0 3 2
1 2 2
1 3 4 
2 3 3
*/ 
