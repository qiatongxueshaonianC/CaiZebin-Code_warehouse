#include<bits/stdc++.h>
using namespace std; 
const int maxn=1005;
int vis[maxn][maxn];
char s[maxn];
int is_palindrome(int l,int r){
	if(l>=r) return 1;
	if(s[l]!=s[r]) vis[l][r]=0;
	if(vis[l][r]>=0) return vis[l][r];
	vis[l][r]=is_palindrome(l+1,r-1);
	return vis[l][r];
}
int main() {
	int T;
	scanf("%d%*c",&T);
	for(int ii=1;ii<=T;ii++){
		scanf("%s",s+1);
		int n=strlen(s+1);
		int dp[n+1]={0};
		fill(vis[0],vis[0]+maxn*maxn,-1);
		for(int i=1;i<=n;i++){
			dp[i]=i;
			for(int j=1;j<=i;j++){
				if(is_palindrome(j,i))
					dp[i]=min(dp[i],dp[j-1]+1);
			}
		}
		printf("%d\n",dp[n]);
	}
	return 0;
}
/*
3
racecar
fastcar
aaadbccb
*/
