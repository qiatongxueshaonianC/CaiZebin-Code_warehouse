#include<bits/stdc++.h>
using namespace std; 
const int maxn=510;
int G[maxn][maxn],cost[maxn],vis[maxn],N,M; 
void DFS(int now,int occupyed,set<int>& st){
	st.insert(now);
	vis[now]=1;
	for(int i=1;i<=N;i++){
		if(vis[i]==0&&i!=occupyed&&G[now][i]>0)
			DFS(i,occupyed,st);
	}
}
int main() {
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b,c,d;
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(d==0)
			G[a][b]=G[b][a]=-c;
		else
			G[a][b]=G[b][a]=c;
	}
	for(int i=1;i<=N;i++){
		int block=0;
		memset(vis,false,sizeof(vis));
		set<int> st;
		for(int j=1;j<=N;j++){
			if(i!=j&&vis[j]==false){
				int Max=0;
				for(auto k:st){
					if(G[k][j]<0)
						Max=max(Max,abs(G[k][j]));
				}
				cost[i]+=Max;
				block++;
				DFS(j,i,st);
			}
		}
		if(block>1)
			cost[i]=INT_MAX;
	}
	int idx=max_element(cost,cost+N+1)-cost;
	if(cost[idx]==0)
		puts("0");
	else{
		set<int> ans;
		ans.insert(idx);
		for(int i=idx+1;i<=N;i++)
			if(cost[i]==cost[idx])
				ans.insert(i);
		for(auto i:ans)
			printf("%s%d",i==*ans.begin()?"":" ",i);
	}
}
/*
4 5
1 2 1 1
1 3 1 1
2 3 1 0
2 4 1 1
3 4 1 0

4 5
1 2 1 1
1 3 1 1
2 3 1 0
2 4 1 1
3 4 2 1
*/
