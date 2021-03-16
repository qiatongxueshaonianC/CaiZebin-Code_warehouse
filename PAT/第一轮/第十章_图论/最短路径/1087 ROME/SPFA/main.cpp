#include<bits/stdc++.h> 
using namespace std;
const int maxn=210;
const int inf=0x3fffffff;
struct Node{
	int to,dis;
	Node(int a,int b):to(a),dis(b){}
};
unordered_map<string,int >mp;
unordered_map<int,string> itos;
vector<Node> G[maxn];
int n,k,d[maxn],num_path=0,numinq[maxn],Weight[maxn],ans_weight,num_node;
bool inq[maxn]={false};
set<int> pre[maxn];
vector<int> temp,ans;
bool SPFA(int s){
	fill(d,d+maxn,inf);
	fill(inq,inq+maxn,false);
	d[s]=0;
	queue<int> q;
	q.push(s);
	inq[s]=true;
	numinq[s]++;
	while(!q.empty()){
		int u=q.front();q.pop();
		inq[u]=false;
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
	if(s==0){
		num_path++;
		temp.push_back(s);
		int weight=0;
		for(int i=temp.size()-1;i>=0;i--){
			int id=temp[i];
			weight+=Weight[id];
		}
		if(weight>ans_weight){
			ans_weight=weight;
			ans=temp;
			num_node=temp.size();
		}else if(weight==ans_weight&&num_node>temp.size()){
			ans=temp;
			num_node=temp.size();
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
	int u,v,dis;
	string s,c1,c2;
	scanf("%d%d",&n,&k);
	cin>>s;
	mp.insert(make_pair(s,0));
	itos[0]=s;
	for(int i=1;i<n;i++){
		cin>>s>>dis;
		mp.insert(make_pair(s,i));
		Weight[i]=dis;
		itos[i]=s;
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
	SPFA(0);
	DFS(mp["ROM"]);
	printf("%d %d %d %d\n",num_path,d[mp["ROM"]],ans_weight,ans_weight/(num_node-1));
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

