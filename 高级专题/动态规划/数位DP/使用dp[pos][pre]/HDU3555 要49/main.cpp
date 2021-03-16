#include<bits/stdc++.h>
using namespace std; 
typedef long long LL;
int d[20];
LL dp[20][2][20];
LL DFS(int pos,int pre,bool ok49,bool isLimit){
	if(pos==-1)
		return ok49?1:0;
	if(!isLimit&&dp[pos][ok49][pre]!=-1)
		return dp[pos][ok49][pre];
	LL ans=0;
	int up=isLimit?d[pos]:9;
	for(int i=0;i<=up;i++){
			ans+=DFS(pos-1,i,ok49||(pre==4&&i==9),isLimit&&i==up);
	}
	if(!isLimit){
		dp[pos][ok49][pre]=ans;
	}
	return ans;
}
LL Solve(LL N){
	int len=0;
	do{
		d[len++]=(N%10);
		N/=10;
	}while(N!=0);
	return DFS(len-1,0,false,true);	
}
int main() {
	LL t,N;
	scanf("%lld",&t);
	while(t--){
		memset(dp,-1,sizeof(dp));
		scanf("%lld",&N);
		printf("%lld\n",Solve(N));
	}
	return 0;
}
/*
3
1
50
500
*/
