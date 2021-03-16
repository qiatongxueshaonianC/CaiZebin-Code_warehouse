#include<bits/stdc++.h>
using namespace std; 
typedef long long LL;
const int maxn=1010;
const int inf=1e9+7;
int N, dp[maxn][maxn],sum[maxn];
#define c(i,j) (sum[j]-sum[i-1]) 
void DP(){
	fill(dp[0],dp[0]+maxn*maxn,inf);
	for(int i=0;i<=N;i++)
		dp[i][i]=0;
	for(int len=1;len<N;len++){
		for(int i=1;i+len<=N;i++){
			int j=i+len;
			for(int k=1;k<j;k++){	//只能把相邻两个石堆合在一起 
				int temp=dp[i][k]+dp[k+1][j]+c(i,j);
				if(temp<dp[i][j]){
					dp[i][j]=temp;
				}
			}
		}
	}
	printf("%d\n",dp[1][N]);	//由于只能把相邻两个石堆合在一起，所以dp[1][N]表示1，N相邻，
								//即所有都合在一起了 
}
int main() {
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int x;scanf("%d",&x);
		sum[i]=sum[i-1]+x;
	}
	DP();
	return 0;
}
/*
5
1 3 4 2 5
*/
