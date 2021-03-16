#include<bits/stdc++.h>
using namespace std; 
const int maxn=10005;
vector<vector<int> >G(maxn);
vector<unordered_set<int> > components(maxn);
int N,M; 
bool vis[maxn][maxn];
void BFS(int s){
//	bool vis[N+1]={false};
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();q.pop();
		vis[s][u]=true;
		for(int i=0;i<G[u].size();i++){
			if(vis[s][G[u][i]]==false){
				components[s].insert(G[u][i]);
				q.push(G[u][i]);	
			}
		}
	}
}
int main() {
	scanf("%d%d",&N,&M);
	int u,v;
	for(int i=0;i<M;i++){
		scanf("%d%d",&u,&v);
		G[u].push_back(v);
	}
	for(int i=1;i<=N;i++)
		BFS(i);
	int k;
	scanf("%d",&k);
	while(k--){
		scanf("%d%d",&u,&v);
		if(components[u].find(v)!=components[u].end()&&(components[v].find(u)!=components[v].end()))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
/*
12 19
3 4
1 3
12 11
5 9
6 2
3 2
10 7
9 1
7 12
2 4
9 5
2 6
12 4
11 10
4 8
8 12
11 8
12 7
1 5
20
11 4
12 7
3 6
2 3
5 3
3 9
4 3
8 3
8 10
10 11
7 8
7 1
9 5
1 9
2 6
3 1
3 12
7 3
6 9
6 8
*/
