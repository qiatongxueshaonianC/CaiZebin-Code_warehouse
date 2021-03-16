#include<bits/stdc++.h>
using namespace std; 
const int maxn=60;
int a[maxn],dp[maxn][maxn],mark[maxn][maxn],idx=1;
int Dp(int i,int j){
	int& ans=dp[i][j];
	if(j-i<=1) ans=0;  //�м�û�п��еĵ� 
	if(ans<INT_MAX) return ans;
	for(int k=i+1;k<j;k++){
		int t=Dp(i,k)+Dp(k,j)+a[j]-a[i];
		if(t<ans)
			ans=t;
	}
	return ans;
}
int DP(int i,int j){
	if(j-i<=1)
		dp[i][j]=0;
	if(dp[i][j]!=INT_MAX)
		return dp[i][j];
	for(int k=i+1;k<j;k++){
		int t=DP(i,k)+DP(k,j)+a[j]-a[i];
		if(t<dp[i][j]){
			dp[i][j]=t;
			mark[i][j]=k;
		}
	}
	return dp[i][j];
} 
void print_ans(int i,int j){
	if(j-i<=1){
		return;
	}
	printf("Point%d| ",mark[i][j]);
	print_ans(i,mark[i][j]);
	print_ans(mark[i][j],j); 
}
int main() {
	int L,n;
	while(~scanf("%d",&L)&&L){
		idx=1;
		fill(dp[0],dp[0]+maxn*maxn,INT_MAX);
		fill(mark[0],mark[0]+maxn*maxn,0);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		a[0]=0;a[n+1]=L;
		int ans=Dp(0,n+1);
		printf("The minimum cutting is %d.\n",ans);
		fill(dp[0],dp[0]+maxn*maxn,INT_MAX);
		ans=DP(0,n+1);
		printf("The minimum cutting is %d.\n",ans);
		print_ans(0,n+1);puts("");
	}
	return 0;
}
/*
100
3
25 50 75
10
4
4 5 7 8
0
*/
