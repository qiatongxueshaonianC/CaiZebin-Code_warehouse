#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int n,m,inDegree[maxn];
vector<int> G[maxn];
bool inq[maxn];
bool TopoSort(){
	fill(inq,inq+maxn,false);
	int num=0;
	queue<int> q;
	for(int i=0;i<n;i++){
		if(!inDegree[i]){
			q.push(i);
			inq[i]=true;
		}
	}
	while(!q.empty()){
		int u=q.front();q.pop();
		num++;
		for(auto i:G[u]){
			inDegree[i]--;
			if(inq[i]==false&&inDegree[i]==false)
				q.push(i);
		}
	}
	if(num!=n) return false;
	return true;
}
int main() {
	while(scanf("%d%d",&n,&m)){
		fill(inDegree,inDegree+maxn,0);
		if(n==0) break;
		int u,v;
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v); 
			inDegree[v]++;
		}
		if(TopoSort()) puts("YES");
		else puts("NO");
		for(int i=0;i<n;i++)
			G[i].clear();
	}
	return 0;
}
/*
4 3
0 1
1 2
2 3
3 3
0 1
1 2
2 0
0 1
*/
