#include<bits/stdc++.h>
using namespace std; 
int d[20],dp[20][10]; //这里可以这么写是因为，到最后“局部”的成立，最终也会成立，违反要求的根本进不了递归 
int DFS(int pos,int pre,bool ALL0,bool isLimit){
	if(pos==-1)
		return 1;
	if(!isLimit&&!ALL0&&dp[pos][pre]!=-1)
		return dp[pos][pre];
	int up=isLimit?d[pos]:9,ans=0;
	for(int i=0;i<=up;i++){
		if(i==4||(pre==6&&i==2))  //违法要求的不进入递归 
			continue;
		ans+=DFS(pos-1,i,ALL0&&i==0,isLimit&&i==d[pos]);
	}
	if(!ALL0&&!isLimit)
		dp[pos][pre]=ans;
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
	int n,m;
	while(scanf("%d%d",&m,&n)==2&&m!=0&&n!=0){
		memset(dp,-1,sizeof(dp));
		printf("%d\n",Solve(n)-Solve(m-1));
	}
	return 0;
}
