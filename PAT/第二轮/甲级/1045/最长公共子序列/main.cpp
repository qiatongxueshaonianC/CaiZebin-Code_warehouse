#include<bits/stdc++.h>
using namespace std; 
int main() {
	int t,N;
	scanf("%d%d ",&t,&N);
	vector<int> A(N+1);
	for(int i=1;i<=N;i++)
		scanf("%d",&A[i]);
	scanf("%d",&N);
	vector<int> B(N+1);
	for(int i=1;i<=N;i++)
		scanf("%d",&B[i]);
	vector<vector<int>> dp(A.size(),vector<int>(B.size(),0)); 
	for(int i=1;i<A.size();i++){
		for(int j=1;j<B.size();j++){
			if(A[i]==B[j])
				dp[i][j]=max(dp[i-1][j],dp[i][j-1])+1;
			else
				dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
		}
	}
	printf("%d",dp[A.size()-1][B.size()-1]);
	return 0;
}
/*
6
5 2 3 1 5 6
12 2 2 4 1 5 5 6 3 1 1 5 6
*/
