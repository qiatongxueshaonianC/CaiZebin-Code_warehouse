#include<bits/stdc++.h>
using namespace std; 
int d[10],dp[10][10];
int DFS(int pos,int sum,bool ALL0,bool isLimit){
	if(pos==-1)
		return sum;
	if(!ALL0&&!isLimit&&dp[pos][sum]!=-1)
		return dp[pos][sum];
	int up=isLimit?d[pos]:9,ans=0;
	for(int i=0;i<=up;i++)
		ans+=DFS(pos-1,i==1?(sum+1):sum,ALL0&&i==0,isLimit&&i==d[pos]);
	if(!ALL0&&!isLimit)
		dp[pos][sum]=ans;
	return ans;
} 
int Solve(int k){
	int len=0;
	while(k!=0){
		d[len++]=k%10;
		k/=10;
	}
	return DFS(len-1,0,true,true);
}
int main() {
	int m;
	scanf("%d",&m);
	memset(dp,-1,sizeof(dp));
	printf("%d",Solve(m));
	return 0;
}
