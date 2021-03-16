#include<bits/stdc++.h>
using namespace std; 
typedef long long LL;
const int maxn=1010;
const int inf=1e9+7;
int N;
LL sum[maxn],dp[maxn][maxn],s[maxn][maxn]; 
#define c(i,j) (sum[j]-sum[i-1])
void DP(){
	fill(dp[0],dp[0]+maxn*maxn,inf);
	for(int i=0;i<=N;i++){
		dp[i][i]=0;
		s[i][i]=i;
	}
	for(int len=1;len<=N;len++){
		for(int i=1;i+len<=N+1;i++){
			int j=i+len-1;
			for(int k=s[i][j-1];k<=s[i+1][j];k++){
				int temp=dp[i][k]+dp[k+1][j]+c(i,j);
				if(temp<dp[i][j]){
					dp[i][j]=temp;
					s[i][j]=k;
				}
			}
		}
	}
	cout<<dp[1][N];
}
int main() {
	std::ios::sync_with_stdio(false);
	cin>>N;
	for(int i=1;i<=N;i++){
		LL x;cin>>x;
		sum[i]=sum[i-1]+x;
	}
	DP();
	return 0;
}
/*
5
1 3 4 2 5
*/
