#include<bits/stdc++.h>
using namespace std;
const int inf=0x3fffffff;
const int maxn=10010;
vector<int> G[maxn];
int d[maxn],st,ed,Range;
vector<int> temp,ans;
unordered_set<int> pre[maxn];
map<pair<int,int>,int> line; 
bool vis[maxn];
void SPFA(int s){
	fill(d,d+maxn,inf);
	fill(vis,vis+maxn,false);
	d[s]=0;
	queue<int> q;
	q.push(s);
	while(q.size()){
		int u=q.front();q.pop();
		vis[u]=true;
		for(auto i:G[u]){
			int v=i,dis=1;
			if(vis[v]==false){
				if(d[u]+dis<d[v]){
					d[v]=d[u]+dis;
					pre[v].clear();
					pre[v].insert(u);
					q.push(v);
				}else if(d[u]+dis==d[v]){
					pre[v].insert(u);
					q.push(v);
				}
			}
		}
	}
}
void DFS(int s){
	if(s==st){
		temp.push_back(s);
		unordered_set<int> st;
		for(auto i=--temp.end();i!=temp.begin();)
			st.insert(line[{*i,*--i}]);
		if(st.size()<Range){
			ans=temp;
			Range=st.size();
		}
		temp.pop_back();
		return;
	}
	temp.push_back(s);
	for(auto i:pre[s])
		DFS(i);
	temp.pop_back();
}
void output(){
	int st=*--ans.end(),r=line[{*--ans.end(),ans[ans.size()-2]}]; //r存储出发时的路线 
	for(int i=ans.size()-1;i>0;i--){
		int u=ans[i],v=ans[i-1];
		if(line[{u,v}]!=r){  //换乘 
			printf("Take Line#%d from %04d to %04d.\n",r,st,u);  //输出的问题2019/11/8/19：05改正 %04d 
			r=line[{u,v}];
			st=u;  //下一站起始点 
		}
	}
	printf("Take Line#%d from %04d to %04d.\n",r,st,ans[0]);
}
int main() {
	int T,index=0,u,v,n,m;
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		scanf("%d%d",&n,&u);
		vector<int> A(n);
		A[0]=u;
		for(int j=1;j<n;j++){
			scanf("%d",&A[j]);
			G[A[j-1]].push_back(A[j]);
			G[A[j]].push_back(A[j-1]);
			line.insert({{A[j-1],A[j]},i});
			line.insert({{A[j],A[j-1]},i});
		}
	}
	scanf("%d",&m);
	while(m--){
		Range=inf;
		scanf("%d%d",&st,&ed);
		SPFA(st);
		DFS(ed);
		printf("%d\n",ans.size()-1);
		output();
		ans.clear();
	}
	return 0;
}
/*
4
7 1001 3212 1003 1204 1005 1306 7797
9 9988 2333 1204 2006 2005 2004 2003 2302 2001
13 3011 3812 3013 3001 1306 3003 2333 3066 3212 3008 2302 3010 3011
4 6666 8432 4011 1306
2
6666 2001
2004 3001


4
7 1001 3212 1003 1204 1005 1306 7797
9 9988 2333 1204 2006 2005 2004 2003 2302 2001
13 3011 3812 3013 3001 1306 3003 2333 3066 3212 3008 2302 3010 3011
4 6666 8432 4011 1306
3
3011 3013
6666 2001
2004 3001
*/
