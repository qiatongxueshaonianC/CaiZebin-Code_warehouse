#include<bits/stdc++.h>
using namespace std; 
const int maxn=110;
const int inf=0x3fffffff;
int N,sum[maxn],dp[maxn][maxn];
vector<int> A;
bool vis[maxn][maxn];
//dp[i][j]=sum[i][j]-min(dp[i+1][j]···dp[j][j],dp[i][j-1]··dp[i][i],0);
#define c(i,j) (sum[j]-sum[i-1])
void init(){
	memset(sum,0,sizeof(sum));
	fill(dp[0],dp[0]+maxn*maxn,0);
	memset(vis,false,sizeof(vis));
}
int DP(int i,int j){
	if(vis[i][j])
		return dp[i][j];
	vis[i][j]=true;
	if(i==j)
		return dp[i][j]=A[i];
	int m=0;	//代表i-j全部一次性全部拿走，此时剩下的就是0了 
	for(int k=i+1;k<=j;k++){
		m=min(m,DP(k,j));	//看一下有没有办法使得这次拿后，下一个人只能得到负数的分值 
	}
	for(int k=j-1;k>=i;k--){
		m=min(m,DP(i,k));
	}
	dp[i][j]=c(i,j)-m;
	return dp[i][j];
}
int main() {
	while(~scanf("%d",&N)&&N){
		init();
		A.resize(N+1);
		for(int i=1;i<=N;i++){
			scanf("%d",&A[i]);
			sum[i]=sum[i-1]+A[i];
		}
		printf("%d\n",2*DP(1,N)-sum[N]);
	}
	return 0;
}
/*
4
4 -10 -20 7
4
1 2 3 4
0
*/
