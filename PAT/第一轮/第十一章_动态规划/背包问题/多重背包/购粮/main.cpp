#include<bits/stdc++.h>
using namespace std;
const int maxn=110;
int T,dp[maxn][maxn],w[maxn],c[maxn],num[maxn]; 
int main() {
	scanf("%d",&T);
	int sum,m;
	while(T--){
		memset(dp,0,sizeof(dp));
		scanf("%d%d",&sum,&m);
		for(int i=1;i<=m;i++){
			scanf("%d%d%d",&c[i],&w[i],&num[i]);
		}
		for(int i=1;i<=m;i++){
			for(int j=1;j<=num[i];j++){
				for(int v=c[i];v<=sum;v++){
					dp[i][v]=max(dp[i-1][v],dp[i][v-c[i]]+w[i]); //不放就跳到下一件物品，放则继续 
					//停留在这件物品 
				}	
			}
		}
		printf("%d\n",dp[m][sum]);
	}
	return 0;
}
/*
1
8 2
2 100 4
4 100 2
*/
