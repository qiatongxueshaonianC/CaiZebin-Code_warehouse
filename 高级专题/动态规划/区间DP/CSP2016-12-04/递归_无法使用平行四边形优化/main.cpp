#include<bits/stdc++.h>
using namespace std; 
typedef long long LL;
const int maxn=1010;
const int inf=1e9+7;
int N, dp[maxn][maxn],sum[maxn];
bool vis[maxn][maxn];
#define c(i,j) (sum[j]-sum[i-1]) 
void DP(){		//����д�� 
	fill(dp[0],dp[0]+maxn*maxn,inf);
	for(int i=0;i<=N;i++)
		dp[i][i]=0;
	for(int len=1;len<=N;len++){
		for(int i=1;i+len<=N+1;i++){
			int j=i+len-1;
			for(int k=1;k<j;k++){	//ֻ�ܰ���������ʯ�Ѻ���һ�� 
				int temp=dp[i][k]+dp[k+1][j]+c(i,j);
				if(temp<dp[i][j]){
					dp[i][j]=temp;
				}
			}
		}
	}
	printf("%d\n",dp[1][N]);	//����ֻ�ܰ���������ʯ�Ѻ���һ������dp[1][N]��ʾ1��N���ڣ�
								//�����ж�����һ���� 
}
int DP(int i,int j){
	if(vis[i][j])
		return dp[i][j];
	vis[i][j]=true;
	dp[i][j]=(i==j)?0:inf;
	int cost=c(i,j); 
	for(int k=i;k<j;k++){
		dp[i][j]=min(dp[i][j],DP(i,k)+DP(k+1,j)+cost);
	}
	return dp[i][j];
}
int main() {
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int x;scanf("%d",&x);
		sum[i]=sum[i-1]+x;
	}
	printf("%d\n",DP(1,N));
	return 0;
}
/*
5
1 3 4 2 5
*/
