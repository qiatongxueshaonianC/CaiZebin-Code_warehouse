#include<bits/stdc++.h>
using namespace std; 
int dp[100010];
int main() {
	int n,u,v,sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&u);
		dp[i]=sum;   //各个点到1节点的距离 
		sum+=u;
	}
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&u,&v);
		if(u>v) swap(u,v);
		int temp=dp[v]-dp[u];
		printf("%d\n",min(temp,sum-temp));
	}
	return 0;
}
/*
5 1 2 4 14 9
3
1 3
2 5
4 1
*/
