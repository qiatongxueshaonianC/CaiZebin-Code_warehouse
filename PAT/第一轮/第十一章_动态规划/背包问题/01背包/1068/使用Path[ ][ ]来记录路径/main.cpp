#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
const int maxv=110;
int n,sum,dp[maxn][maxv],w[max]; 
bool flag[maxn],choice[maxn][maxv];
bool cmp(int a,int b){
	return a>b;
}
int main() {
	scanf("%d%d",&n,&sum);
	for(int i=1;i<=n;i++)
		scanf("%d",&w[i]);
	sort(w+1,w+n+1,cmp);
	for(int i=0;i<=sum;i++)
		dp[0][i]=0;
	for(int i=1;i<=n;i++){
		for(int j=sum;j>=w[i];j--){
			if(dp[i-1][j-w[i]]+w[i]>=dp[i-1][j]){
				dp[i][j]=dp[i-1][j-w[i]]+w[i];
				choice[i][j]=true;
			}else{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	if(dp[n][sum]!=sum){
		puts("No Solution");
		return 0;
	}
	int k=n,num=0;
	while(k>0){
		if(choice[k][sum]==true){
			flag[k]=true;
			sum-=w[k];
			num++;
		}else flag[k]=false;
		k--;
	}
	for(int i=n;i>=1;i--){
		if(flag[i]){
			printf("%d",w[i]);
			if(--num>0) printf(" ");
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
