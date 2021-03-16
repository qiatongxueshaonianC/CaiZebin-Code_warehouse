#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxc=210;
const int maxn=10010;
int HarshTable[maxc];
int A[maxn],dp[maxn]; 
int main() {
	int n,m,x;
	scanf("%d%d",&n,&m);
	memset(HarshTable,-1,sizeof(HarshTable));
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		HarshTable[x]=i;
	}
	int num=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&x);
		if(HarshTable[x]>=0)
			A[num++]=HarshTable[x];
	//	else A[num++]=-1;
	}
	int ans=0;
	for(int i=0;i<num;i++){
	//	if(A[i]<0) continue;
		dp[i]=1;
		for(int j=0;j<i;j++){
			if(A[i]>=A[j]&&dp[i]<=dp[j])
				dp[i]=dp[j]+1;
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
	return 0;
}
/*
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
*/
