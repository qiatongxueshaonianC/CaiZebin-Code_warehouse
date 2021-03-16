#include<bits/stdc++.h>
using namespace std;
const int maxn=17;
const int inf=1e9+7;
int dp[1<<maxn][maxn],N; 
bool vis[1<<maxn][maxn];
vector<vector<int> >G;
void init(){
	G.resize(N+1);
	fill(G.begin(),G.end(),vector<int>(N+1));
	for(int i=0;i<=N;i++){
		for(int j=0;j<=N;j++)
			cin>>G[i][j];
	}
}
void Floyed(){
	for(int k=0;k<=N;k++){
		for(int i=0;i<=N;i++){
			for(int j=0;j<=N;j++)
				G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
		}
	}
}
int DP(int S,int v){
	if(vis[S][v])
		return dp[S][v];
	vis[S][v]=true;
	if(S==(1<<N)-1&&v==0)
		return dp[S][v]=0;
//	int res=INT_MAX;		//2020/5/25/20:57发现，这里会溢出变成负数，出错；
	int res=inf; 
	for(int u=0;u<N;u++){
		if(!((S>>u)&1))
			res=min(res,DP(S|(1<<u),u)+G[v][u]);
	}
	return dp[S][v]=res;
}
void Solve(){
	memset(vis,false,sizeof(vis));
	init();
	Floyed();
	N++;
	cout<<DP(0,0)<<endl;
}
int main(){
	std::ios::sync_with_stdio(false);
	while(cin>>N&&N){
		Solve();
	}
	return 0;
}
/*
3
0 1 10 10
1 0 1 2
10 1 0 10
10 2 10 0
0
*/ 
