#include<bits/stdc++.h>
using namespace std; 
const int inf=0x3fffffff;
typedef long long ll;
vector<ll> dp;
ll sum,lose=inf;
vector<pair<int,int>>ans;
int main() {
	int N,M,v,index=0;
	scanf("%d%d",&N,&M);
	dp.resize(N+2);
	for(int i=1;i<=N;i++){
		scanf("%d",&v);
		dp[i]=sum;
		if(index==0&&dp[i]>=M)
			index=i;
		sum+=v;
	}
	dp[N+1]=sum; 
	for(int i=1;i<=N+1;i++){
		int v=M+dp[i];
		int j=lower_bound(dp.begin()+i+1,dp.begin()+N+2,v)-dp.begin();  //左闭右开所以是N+2 
		if(dp[j]-dp[i]<M) continue;
		if(dp[j]-dp[i]-M<lose){
			lose=dp[j]-dp[i]-M;
			ans.clear();
			ans.push_back({i,j-1});
		}else if(dp[j]-dp[i]-M==lose)
			ans.push_back({i,j-1});
	}
	sort(ans.begin(),ans.end());
	for(auto i:ans)
		printf("%d-%d\n",i.first,i.second);	
	return 0;
}
/*
16 15
3 2 1 5 4 6 8 7 16 10 15 11 9 12 14 13

5 13
2 4 5 7 9
*/
