#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std; 
typedef long long LL;
int d[80];
LL dp[80][2][80];
LL DFS(int pos,int sum,bool ALL0,bool isLimit){
	if(pos==-1){
		return sum>=100?1:0;
	}
	if(!isLimit&&dp[pos][ALL0][sum]!=-1)
		return dp[pos][ALL0][sum];		//sum初始不能取0，否则会越界 
	LL ans=0;
	int up=isLimit?d[pos]:1;
	for(int i=0;i<=up;i++){
		if(i==0&&ALL0)
			ans+=DFS(pos-1,sum,ALL0&&i==0,isLimit&&i==up);
		else if(i==0)
			ans+=DFS(pos-1,sum+1,ALL0&&i==0,isLimit&&i==up);
		else 
			ans+=DFS(pos-1,sum-1,ALL0&&i==0,isLimit&&i==up);
	}
	if(!isLimit)
		dp[pos][ALL0][sum]=ans;
	return ans;
}
LL Solve(LL n){
	int len=0;
	do{
		d[len++]=n%2;
		n/=2;
	}while(n!=0);
	return DFS(len-1,100,true,true);
}
int main() {
	LL m,n;
	scanf("%lld%lld",&m,&n);
	memset(dp,-1,sizeof(dp));
	printf("%lld",Solve(n)-Solve(m-1));
	return 0;
}
/*
2 12
*/
