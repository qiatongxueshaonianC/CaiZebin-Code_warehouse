#include<bits/stdc++.h>
using namespace std; 
int dp[210][10010];
vector<int> A,B;
int main() {
	int n,m,v;
	scanf("%d%d",&n,&m);
	A.resize(m+1);
	for(int i=1;i<=m;i++)
		scanf("%d",&A[i]);
	scanf("%d",&n);
	B.resize(n+1);
	for(int i=1;i<=n;i++)
		scanf("%d",&B[i]);
	for(int i=1;i<A.size();i++){
		for(int j=1;j<B.size();j++){
			if(A[i]==B[j])
				dp[i][j]=max(dp[i][j-1],dp[i-1][j])+1;
			else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
		}
	}
	printf("%d\n",dp[A.size()-1][B.size()-1]);
	return 0;
}
/*
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
*/
