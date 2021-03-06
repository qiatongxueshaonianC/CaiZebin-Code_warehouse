#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
int G[maxn][maxn]={0};
bool vis[maxn]={false};
	int n,m,k,query;
void DFS(int now){
	vis[now]=1;
	for(int i=1;i<=n;i++){
		if(G[now][i]>0&&vis[i]==false&&i!=query){
			DFS(i);
		}
	}
}
int main() {
	int c1,c2;
	scanf("%d%d%d%*c",&n,&m,&k);
	for(int i=0;i<m;i++){
		scanf("%d%d",&c1,&c2);
		G[c1][c2]=1;
		G[c2][c1]=1;
	}
	int ans;
	while(k--){
		ans=0;
		scanf("%d",&query);
		memset(vis,false,sizeof(vis));
		for(int i=1;i<=n;i++){
			if(vis[i]==false&&i!=query){
				ans++;
				DFS(i);
			}
		}
		puts(to_string(ans-1).c_str());
		//printf("%d\n",ans-1);
	}
	return 0;
}
/*
3 2 3
1 2
1 3
1 2 3
*/
