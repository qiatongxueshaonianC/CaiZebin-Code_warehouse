#include<bits/stdc++.h> 
using namespace std;
const int maxn=510;
const int inf=0x3fffffff;
struct Node{
	int to,dis;
	Node(int a,int b):to(a),dis(b){}
};
vector<Node> G[maxn];
int n,m,c1,c2,weight[maxn],ans_path,ans_weight;
int d[maxn],numinq[maxn];
vector<int> temp,ans;
bool inq[maxn];
set<int> pre[maxn];
bool SPFA(int s){
	fill(d,d+maxn,inf);
	d[s]=0;
	queue<int> q;
	q.push(s);
	inq[s]=true;
	numinq[s]++;
	while(q.size()){
		int u=q.front();q.pop();
		inq[u]=false;            //在这里犯错：2019年10月18日18：50发现 
		for(auto i:G[u]){
			int v=i.to,dis=i.dis;
			if(d[u]+dis<d[v]){
				d[v]=d[u]+dis;
				pre[v].clear();
				pre[v].insert(u);
				if(!inq[v]){
					q.push(v);
					inq[v]=true;
					if(++numinq[v]>=n) return false;
				}
			}else if(d[u]+dis==d[v]) {
				pre[v].insert(u);
				if(!inq[v]){   ////在这里犯错：2019年10月18日下午第三节课——人机交互卡了一节课 
					q.push(v);
					inq[v]=true;
					if(++numinq[v]>=n) return false;
				}
			}
		}
	}
	return true;
}
void DFS(int s){
	if(s==c1){
		ans_path++;
		temp.push_back(s);
		int num=0;
		for(auto i:temp)
			num+=weight[i];
		if(num>ans_weight){
			ans_weight=num;
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
	cin>>n>>m>>c1>>c2;
	for(int i=0;i<n;i++)
		scanf("%d",&weight[i]);
	int u,v,dis;
	for(int i=0;i<m;i++){
		cin>>u>>v>>dis;
		G[u].push_back(Node(v,dis));
		G[v].push_back(Node(u,dis)); 
	}
	SPFA(c1);
	DFS(c2);  //逆序，从尾节点开始 
	printf("%d %d",ans_path,ans_weight);
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
