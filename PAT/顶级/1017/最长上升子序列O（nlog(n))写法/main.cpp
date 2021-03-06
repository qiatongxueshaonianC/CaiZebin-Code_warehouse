#include<bits/stdc++.h>
using namespace std; 
const int maxn=1e4+10;
int dp[maxn],l[maxn],r[maxn],A[maxn],Max,Diff=INT_MAX,idx; 
int main() {
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	fill(dp,dp+n,INT_MAX);
	for(int i=0;i<n;i++){
		l[i]=lower_bound(dp,dp+n,A[i])-dp;
		dp[l[i]]=A[i];
	}
	fill(dp,dp+n,INT_MAX);
	for(int i=n-1;i>=0;i--){
		r[i]=lower_bound(dp,dp+n,A[i])-dp;
		dp[r[i]]=A[i];
	}
	for(int i=0;i<n;i++){
		if(l[i]&&r[i]){
			int num=r[i]+l[i]+1,dif=abs(l[i]-r[i]);
			if(Max<num||(Max==num&&dif<Diff)){
				idx=i;
				Max=num;
				Diff=dif;
			}
		}
	}
	if(Max!=0)
		printf("%d %d %d",Max,idx+1,A[idx]);
	else puts("No peak shape");
	return 0;
}
/*
20
1 3 0 8 5 -2 29 20 20 4 10 4 7 25 18 6 17 16 2 -1
*/
