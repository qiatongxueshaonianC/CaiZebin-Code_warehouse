#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
const int maxv=110;
int n,sum,w[maxn],dp[maxn][maxv]; 
bool cmp(int a,int b){
	return a>b;
}
int main() {
	scanf("%d%d",&n,&sum);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	sort(w+1,w+n+1,cmp);  //因为要倒着从小到大输出 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			dp[i][j]=dp[i-1][j];
			if(j>=w[i])
				dp[i][j]=max(dp[i][j],dp[i-1][j-w[i]]+w[i]);		
		} 
	}
	if(dp[n][sum]!=sum) puts("No Solution");
	else{
		while(n>0&&sum>0){
			if(dp[n][sum]==dp[n-1][sum-w[n]]+w[n]){  //要从“包满”的状态开始逆序判断
			//如果正序判断，无法知道某件物品是否在包里面 
				sum-=w[n];
				printf("%d%s",w[n],sum>0?" ":"");   //因为是倒着输出，所以初始要逆序排列 
			}
			n--;			
		}
	}
	return 0;
}
/*
8 9
5 9 8 7 2 3 4 1

4 8
7 2 4 3
*/
