#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
const int maxn=510; 
int n,num[maxn],dp[maxn][maxn],mark[maxn][maxn];
void DP(int l,int r){
	for(int len=1;len<=n;len++){
		for(int left=1;left+len-1<=n;left++){
			int right=left+len-1;
			for(int k=left;k<=right;k++){
				int t=num[left-1]*num[k]*num[right+1]+dp[left][k-1]+dp[k+1][right];
				if(t>dp[left][right]){
					dp[left][right]=t;
					mark[left][right]=k;
				}
			}
		}
	}
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	num[0]=num[n+1]=1;
	fill(dp[0],dp[0]+maxn*maxn,0);  //使用递推式，必须初始化为0 
	DP(1,n);
	printf("%d",dp[1][n]);
	return 0;
}
/*
4
3 1 5 8
*/
