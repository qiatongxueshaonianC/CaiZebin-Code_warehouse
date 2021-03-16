#include<bits/stdc++.h> 
using namespace std;
const int maxn=210;
const int inf=0x3fffffff;
struct Node{
	int to,dis;
	Node(int a,int b):to(a),dis(b){}
}; 
int n,k,d[maxn],weight[maxn];
int path_num=0,sum_weight,node_num=inf;
bool vis[maxn];
vector<Node> G[maxn];
unordered_map<string,int> mp;
unordered_map<int,string> itos;
unordered_set<int> pre[maxn];
vector<int> temp,ans;
void Dijkstra(int s){
	fill(d,d+maxn,inf);
	fill(vis,vis+maxn,false);
	d[s]=0;
	for(int i=0;i<n;i++){
		int u=-1,min=inf;
		for(int j=0;j<n;j++){
			if(vis[j]==false&&d[j]<min){
				min=d[j];
				u=j;
			}
		}
		if(u==-1) return;
		vis[u]=true;
		for(auto i:G[u]){
			int v=i.to,dis=i.dis;
			if(d[u]+dis<d[v]){
				d[v]=d[u]+dis;
				pre[v].clear();
				pre[v].insert(u);
			}else if(d[u]+dis==d[v])
					pre[v].insert(u);
		}
	}
}
void DFS(int s){
	if(s==0){
		path_num++;
		int sum=0;
		temp.push_back(s);
		for(int i=temp.size()-1;i>=0;i--){
			int id=temp[i];
			sum+=weight[id];
		}
		if(sum>sum_weight){
			sum_weight=sum;
			node_num=temp.size();
			ans=temp;
		}else if(sum==sum_weight&&temp.size()<node_num){
			node_num=temp.size();
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
	string s0,c1,c2;
	int u,v,dis;
	cin>>n>>k>>s0;
	mp[s0]=0;
	itos[0]=s0;
	for(int i=1;i<n;i++){
		cin>>c1>>dis;
		mp[c1]=i;
		itos[i]=c1;
		weight[i]=dis;
	}
	for(int i=0;i<k;i++){
		cin>>c1>>c2>>dis;
		u=mp[c1];
		v=mp[c2];
		Node node(v,dis);
		G[u].push_back(node);
		node.to =u;
		G[v].push_back(node);
	}
	Dijkstra(0);
	DFS(mp["ROM"]);
	printf("%d %d %d %d\n",path_num,d[mp["ROM"]],sum_weight,sum_weight/(node_num-1));
	reverse(ans.begin(),ans.end());
	for(auto i:ans){
		printf("%s",itos[i].c_str());
		if(i!=*(ans.end()-1)) printf("->");
	}
	return 0;
}
/*
6 7 HZH
ROM 100
PKN 40
GDN 55
PRS 95
BLN 80
ROM GDN 1
BLN ROM 1
HZH PKN 1
PRS ROM 2
BLN HZH 2
PKN GDN 1
HZH PRS 1
*/

