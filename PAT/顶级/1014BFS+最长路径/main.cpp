#include<bits/stdc++.h>
using namespace std; 
const int maxn=1005;
vector<vector<int> >G(maxn);
int N,Max;
bool vis[maxn];
void BFS(int s){
	queue<pair<int,int> > q;
	q.push(make_pair(s,0));
	bool inq[N+5]={false};
	inq[s]=true;
	vis[s]=true;
	while(!q.empty()){
		pair<int,int> now=q.front();q.pop();
		int u=now.first;
		Max=max(Max,now.second);
		for(auto I:G[u]){
			if(!inq[I]){
				inq[I]=true;
				vis[I]=true;
				q.push(make_pair(I,now.second+1));
			}
		}
	}
}
int main() {
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int u,k;
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&u);
			G[i].push_back(u);
			G[u].push_back(i);
		}
	}
	int blocks=0;
	for(int i=1;i<=N;i++){
		if(!vis[i])
			blocks++;
		BFS(i);
	}
	printf("%d %d",blocks,max(Max-1,0));	//有可能就是一堆散点！！ 
	return 0; 
}
/*
17
2 15 12
1 17
2 16 9
1 8
4 10 13 15 14
0
2 11 14
1 4
2 2 3
2 13 11
2 15 7
2 1 14
2 5 15
0
0
1 3
1 2
*/
