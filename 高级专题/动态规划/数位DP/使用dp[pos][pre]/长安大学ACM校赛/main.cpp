#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<bitset>
using namespace std;
typedef long long ll;
ll dp[100][3][3],d[100];
ll DFS(ll pos,ll sta_2,ll sta_1,bool ALL0,bool isLimit){
	if(pos==-1)
		return 1;
	if(!ALL0&&!isLimit&&dp[pos][sta_2][sta_1]!=-1)
		return dp[pos][sta_2][sta_1];
	int up=isLimit?d[pos]:1;
	ll ans=0;
	for(int i=0;i<=up;i++){
		if(i&&sta_2)
			continue;
		ans+=DFS(pos-1,sta_1,i,ALL0&&i==0,isLimit&&i==d[pos]);
	}
	if(!ALL0&&!isLimit)
		dp[pos][sta_2][sta_1]=ans;
	return ans;
}
ll Solve(ll k){
	ll len=0;
	while(k!=0){
		d[len++]=k%2;
		k/=2;
	}
	return DFS(len-1,0,0,true,true);
}
int main() {
	ll T,m,n;
	scanf("%lld",&T);
	while(T--){
		memset(dp,-1,sizeof(dp));
		scanf("%lld%lld",&m,&n);
		printf("%lld\n",Solve(n)-Solve(m-1));
	}
	return 0;
}
/*
2
2 6
1 109
*/
