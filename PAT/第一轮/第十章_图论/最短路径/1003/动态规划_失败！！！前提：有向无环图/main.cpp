/*失败原因：DAG动态规划求解时只能用于：有向无环图！！！！！！*/ 
#include<bits/stdc++.h> 
using namespace std;
const int inf=0x3fffffff;
const int maxn=510;
struct Node{
	int to,dis;
	Node(int a,int b):to(a),dis(b){}
}; 
int n,m,c1,c2,weight[maxn],d[maxn],ans_path,ans_num;
vector<int> temp,anspath;
vector<Node> G[maxn]; 
set<int> nex[maxn];
bool vis[maxn];
int DP(int u,int pre){
	if(vis[u]) return d[u];
	vis[u]=true;
	for(auto i:G[u]){
		if(i.to==pre) continue; //不回头 
		int v=i.to,dis=i.dis;
		int temp=dis+DP(v,u);
		if(temp<d[u]){
			d[u]=temp;
			nex[u].clear();
			nex[u].insert(v);
		}else if(temp==d[u]) nex[u].insert(v);
	}
	return d[u];
}
void DFS(int s){
	if(s==c2){
		ans_path++;
		temp.push_back(s);
		int num=0;
		for(auto i:temp)
			num+=weight[i];
		if(num>ans_num){
			ans_num=num;
			anspath=temp;
		}
		temp.pop_back();
	}
	temp.push_back(s);
	for(auto i:nex[s])
		DFS(i);
	temp.pop_back();
}
int main() {
	fill(d,d+maxn,inf);
	cin>>n>>m>>c1>>c2;
	d[c2]=0;
	for(int i=0;i<n;i++)
		scanf("%d",&weight[i]);
	int u,v,dis;
	for(int i=0;i<m;i++){
		cin>>u>>v>>dis;
		G[u].push_back(Node(v,dis));
		G[v].push_back(Node(u,dis));
	}
	DP(c1,-1);
	DFS(c1);
	printf("%d %d\n",ans_path,ans_num);
	return 0;
}
/*
5 6 0 2
1 2 1 5 3
0 1 1
0 2 2
0 3 1
1 2 1
2 4 1
3 4 1
*/
