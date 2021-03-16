#include<bits/stdc++.h>
using namespace std; 
const int maxn=60;
int a[maxn],dp[maxn][maxn];
int Dp(int i,int j){
	int& ans=dp[i][j];
	if(j-i<=1) ans=0;  //中间没有可切的点 
	if(ans<INT_MAX) return ans;
	for(int k=i+1;k<j;k++){
		int t=Dp(i,k)+Dp(k,j)+a[j]-a[i];
		if(t<ans)
			ans=t;
	}
	return ans;
}
int main() {
	int L,n;
	while(~scanf("%d",&L)&&L){
		fill(dp[0],dp[0]+maxn*maxn,INT_MAX);
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i]);
		a[0]=0;a[n+1]=L;
		int ans=Dp(0,n+1);
		printf("The minimum cutting is %d.\n",ans);
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
