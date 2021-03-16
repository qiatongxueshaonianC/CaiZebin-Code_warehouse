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
int DP(int i,int j){
	if(i>j) return 0;
	int& ans=dp[i][j];
	if(i==j)  //扎i 
		ans=num[i-1]*num[i]*num[j+1];
	if(ans>-INT_MAX)
		return dp[i][j];
	for(int k=i;k<=j;k++){
		int t=DP(i,k-1)+DP(k+1,j)+num[i-1]*num[k]*num[j+1]; //这一次扎k，且i~j之间的所有气球都扎掉 
		if(ans<t){
			ans=t;
			mark[i][j]=k;
		}
	}
	return ans;
}
int main() {
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&num[i]);
	num[0]=num[n+1]=1;
	fill(dp[0],dp[0]+maxn*maxn,-INT_MAX);
	DP(1,n);
	printf("%d",DP(1,n));
	return 0;
}
/*
4
3 1 5 8
*/
