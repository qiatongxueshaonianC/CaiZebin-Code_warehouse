#include<bits/stdc++.h>
using namespace std; 
const int maxn=1e4+10;
int dp[maxn],l[maxn],idx=0;
vector<int> A;
map<int,int> trans; 
int main() {
	int t,N;
	scanf("%d%d",&t,&N);
	for(int i=0;i<N;i++){
		scanf("%d",&t);
		trans[t]=idx++;
	}
	scanf("%d",&N);
	/*
	for(int i=0;i<N;i++){  //这里会出错，所以干脆不要加进来的好 
		int tp;
		scanf("%d",&tp);
		A[i]=trans[tp];
	}*/ 
	for(int i=0;i<N;i++){
		scanf("%d",&t);
		if(trans.find(t)!=trans.end())  //2020/2/12/16：45发现 
			A.push_back(trans[t]);
	}
	fill(dp,dp+N,INT_MAX);
	for(int i=0;i<A.size();i++){
		l[i]=upper_bound(dp,dp+N,A[i])-dp;
		dp[l[i]]=A[i];
	}
	printf("%d",*max_element(l,l+N)+1);
	return 0;
}
/*
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6

2
1 1 
6 2 2 2 2 2 1 
*/
