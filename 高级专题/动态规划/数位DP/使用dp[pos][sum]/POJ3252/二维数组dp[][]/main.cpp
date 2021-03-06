#include<iostream> 
#include<cstring>
#include<cstdio>
using namespace std; 
const int init=100;
int d[100],dp[100][init];
int DFS(int pos,int sum,bool ALL0,bool isLimit){
	if(pos==-1)
		return sum>=init?1:0;
	if(!ALL0&&!isLimit&&dp[pos][sum]!=-1)
		return dp[pos][sum]; //用dp[pos][sum]的原因：因为0的个数多还是1的个数多是要看“总体”的局部的多少 
	int up=isLimit?d[pos]:1;	//不能决定最终这个数是0多还是1多 
	int ans=0;
	for(int i=0;i<=up;i++){
		if(i==0){
			if(ALL0)  //全是前导零 
				ans+=DFS(pos-1,sum,ALL0&&i==0,isLimit&&i==d[pos]);
			else
				ans+=DFS(pos-1,sum+1,ALL0&&i==0,isLimit&&i==d[pos]);
		}else
			ans+=DFS(pos-1,sum-1,ALL0&&i==0,isLimit&&i==d[pos]);
	}
	if(!ALL0&&!isLimit)
		dp[pos][sum]=ans;
	return ans;
}
int Solve(int k){
	memset(dp,-1,sizeof(dp));
	int len=0;
	while(k!=0){
		d[len++]=k%2;
		k/=2;
	}
	return DFS(len-1,init,true,true);
}
int main() {
	long long n,m;
	scanf("%lld%lld",&m,&n);
	printf("%d\n",Solve(n)-Solve(m-1));
	return 0;
}
/*
2 12
*/ 
