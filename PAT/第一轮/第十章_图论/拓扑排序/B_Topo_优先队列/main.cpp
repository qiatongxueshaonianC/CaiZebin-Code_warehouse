#include<bits/stdc++.h>
using namespace std;
const int maxn=510;
int n,m,inDegree[maxn];
vector<int> G[maxn],ans; 
bool inq[maxn];
bool TopoSort(){
	int num=0;
	priority_queue<int,vector<int>,greater<int> >q;
	for(int i=1;i<=n;i++){
		if(!inDegree[i]){
			q.push(i);
			inq[i]=true;
		}
	}
	while(!q.empty()){
		int u=q.top();q.pop();
		num++;
		ans.push_back(u);
		for(auto i:G[u]){
			inDegree[i]--;
			if(inDegree[i]==0){
				q.push(i);
			}
		}
	}
	if(num!=n) return false;
	return true;
}
int main() {
	while(scanf("%d%d",&n,&m)){
		if(n==0) break;
		int u,v;
		for(int i=0;i<m;i++){
			scanf("%d%d",&u,&v);
			G[u].push_back(v);
			inDegree[v]++;
		}
		if(TopoSort()){
			for(auto i:ans){
				printf("%d",i);
				if(i!=*(ans.end()-1))printf(" ");
			}
			puts("");
		}else puts("ERROR");
		for(int i=1;i<=n;i++)
			G[i].clear();
		ans.clear();
	}
	return 0;
}
/*
3 2
3 1
3 2
17 16
16 1
13 2
7 3
12 4
12 5
17 6
10 7
11 8
11 9
16 10
13 11
15 12
15 13
17 14
17 15
17 16
0 0
*/
