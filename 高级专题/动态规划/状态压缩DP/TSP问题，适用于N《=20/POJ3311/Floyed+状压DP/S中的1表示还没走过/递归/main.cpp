#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
const int maxn=17;
const int inf=0x3fffffff;
int dp[maxn][1<<maxn],N; 
vector<vector<int> >G;
bool vis[maxn][1<<maxn];
void init(){
	G.resize(N),fill(G.begin(),G.end(),vector<int>(N));
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
		scanf("%d",&G[i][j]);
}
void Floyed(){
	for(int k=0;k<N;k++)
	for(int i=0;i<N;i++)
	for(int j=0;j<N;j++)
		G[i][j]=min(G[i][j],G[i][k]+G[k][j]);
}
void DP(){
	fill(dp[0],dp[0]+maxn*(1<<maxn),inf);	//2020/5/27���֣�������(1<<maxn) 
	for(int i=0;i<N;i++) //�߽磬S�еĵ��Ѿ�ȫ���߹�һ�飬�ִ�i��������ص����k��ʱ�򣬾�����G[i][k] 
		dp[i][0]=G[i][0];	//��������������1 
	for(int S=0;S<(1<<N);S++){
		for(int i=0;i<N;i++){
			for(int j=0;j<N;j++){
				if(S&(1<<j)){
					dp[i][S]=min(dp[i][S],dp[j][S^(1<<i)]+G[i][j]);
				}
			}
		}
	}
} 
int DP(int u,int S){
	if(vis[u][S])
		return dp[u][S];
	vis[u][S]=true;
	if(S==0&&u==1)		//��㶨��Ϊ1 
		return dp[u][S]=0;
	dp[u][S]=inf;
	for(int v=0;v<N;v++){
		if(S&(1<<v)){
			dp[u][S]=min(dp[u][S],DP(v,S^(1<<v))+G[u][v]);
		}
	}
	return dp[u][S];
}
void Solve(){
	N++;
	init();
	Floyed();
	DP();		//����д����֪���Ĵ��ˣ����� 
	printf("%d\n",dp[0][(1<<N)-1]);
	memset(vis,false,sizeof(vis));
	printf("%d\n",DP(1,(1<<N)-1));
}
int main(){
	while(scanf("%d",&N)==1&&N){
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
