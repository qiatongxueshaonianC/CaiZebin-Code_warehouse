#include<bits/stdc++.h>
using namespace std; 
const int maxn=510;
const int inf=0x3fffffff;
struct Node{
	int to,dis;
	Node(int a,int b):to(a),dis(b){}
};
int cmax,n,ed,m,st=0;
int d[maxn],numinq[maxn],weight[maxn];
int minback=inf,minneed=inf;
vector<Node> G[maxn];
unordered_set<int> pre[maxn];
vector<int>temp,ans;
bool inq[maxn];
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
				if(inq[v]==false){
					q.push(v);
					inq[v]=true;
					if(++numinq[v]>=n) return false;
				}
			}else if(d[u]+dis==d[v]){
					pre[v].insert(u);
			//!!!!!!!!!!!!!!!!一定要加
					if(!inq[v]){
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
	if(s==st){
		temp.push_back(s);
		int need=0,back=0;
		for(int i=temp.size()-1;i>=0;i--){
			int id=temp[i];
			if(weight[id]>0){
				back+=weight[id];
			}else if(weight[id]<0){
				if(back>abs(weight[id])) 
					back-=abs(weight[id]);
				else{
					need+=(abs(weight[id])-back);
					back=0;
				}
			}
		}
		if(need<minneed){
			minneed=need;
			minback=back;
			ans=temp;
		}else if(need==minneed&&back<minback){
			minback=back;
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
	scanf("%d%d%d%d",&cmax,&n,&ed,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&weight[i]);
		weight[i]-=cmax/2;
	}
	int c1,c2,dis;
	while(m--){
		scanf("%d%d%d",&c1,&c2,&dis);
		Node node(c2,dis);
		G[c1].push_back(node);
		node.to =c1;
		G[c2].push_back(node);
	}
	if(SPFA(st)){
		DFS(ed);
		printf("%d ",minneed);
		reverse(ans.begin(),ans.end());
		for(auto i:ans){
			printf("%d",i);
			if(i!=*(ans.end()-1)) printf("->");
		}
		printf(" %d\n",minback);
	}
	return 0;
}
/*
10 3 3 5
6 7 0
0 1 1
0 2 1
0 3 3
1 3 1
2 3 1
*/
