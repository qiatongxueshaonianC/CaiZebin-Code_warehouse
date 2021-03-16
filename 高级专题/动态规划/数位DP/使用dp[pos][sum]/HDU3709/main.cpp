#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#define lowbit(x) x&(-x);
#define me(a,b) memset(a,-1,sizeof(a));
using namespace std;
const int maxn=1e4+10;
typedef long long ll;
ll d[20],dp[20][20][maxn]; 
ll DFS(ll pos,ll pivot,ll sum,bool ALL0,bool isLimit){
	if(pos==-1)
		return sum==0?1:0;
	if(!ALL0&&!isLimit&&dp[pos][pivot][sum]!=-1)
		return dp[pos][pivot][sum];//这种问题，是否平衡是要看“总体”的，局部成立，到总体那里就不一定成立了 
	ll up=isLimit?d[pos]:9;			//所以这里要传入一个sum 
	ll ans=0;
	for(ll i=0;i<=up;i++)
		ans+=DFS(pos-1,pivot,sum+(pos-pivot)*i,ALL0&&i==0,isLimit&&i==d[pos]);
	if(!ALL0&&!isLimit)
		dp[pos][pivot][sum]=ans;
	return ans;
}
ll Solve(ll k){
	ll len=0,ans=0;
	while(k!=0){
		d[len++]=k%10;
		k/=10;
	}
	for(ll i=0;i<len;i++)
		ans+=DFS(len-1,i,0,true,true);
	return ans-len+1;
}
int main() {
	ll n,m,T;
	scanf("%lld",&T);
	while(T--){
		me(dp,-1);
		scanf("%lld%lld",&m,&n);
		printf("%lld\n",Solve(n)-Solve(m-1));
	} 
	return 0;
}
/*
2
0 9
7604 24324
*/
