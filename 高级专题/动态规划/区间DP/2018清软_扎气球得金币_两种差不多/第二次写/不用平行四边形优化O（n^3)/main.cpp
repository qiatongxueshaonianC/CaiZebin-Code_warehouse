//2020/8/19大发现！！！！这里只能是取len到N，j=len-1 
//原因：因为dp[i][i]是没办法直接得到的，dp[i][i]也需要一次计算才能得到，以后还是
//写成：1<=len<=N   j=i+len-1比较好 

#include<bits/stdc++.h>
using namespace std; 
const int maxn=1e3+5;
int N,dp[maxn][maxn];
vector<int> A;
int main() {
	scanf("%d",&N);
	A.resize(N+2);
	A[0]=A[N+1]=1;
	for(int i=1;i<=N;i++){
		scanf("%d",&A[i]);
	}
/*	for(int i=1;i<=N;i++)
		dp[i][i]=A[i]; */		//别加 
	for(int len=1;len<=N;len++){		//2020/8/19大发现！！！！这里只能是取len到N，j=len-1 
		for(int i=1;i+len<=N+1;i++){
			int j=i+len-1;
			for(int k=i;k<=j;k++){
			//	dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+A[k-1]*A[k]*A[k+1]);//2020/8/9/01：50发现
			//	这里注意，是对“i~j这个区间做处理”，所以，这里是A[i-1]、A[j]+1
				dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+A[i-1]*A[k]*A[j+1]); 
			}
		}
	}
	cout<<dp[1][N];
	return 0;
}
/*
4
3 1 5 8
*/
