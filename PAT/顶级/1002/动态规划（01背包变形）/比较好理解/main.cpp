#include<bits/stdc++.h>
using namespace std; 
struct Node{
	int profit,need,deadline;
	bool friend operator<(const Node& a,const Node& b){
		return a.deadline<b.deadline;
	}
};
int N;
void Solve(int D,vector<Node> A){
	vector<vector<int>> dp(N+1,vector<int>(D+1,0));
	for(int i=1;i<=N;i++){
		for(int j=1;j<=D;j++){
			if(j<A[i].need)  //选不了 
				dp[i][j]=dp[i-1][j];
			else if(A[i].need<=j&&j<=A[i].deadline)  //在上一件(i-1)的基础上，选或者不选 
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-A[i].need]+A[i].profit);
			else
				dp[i][j]=max(dp[i-1][j],dp[i][A[i].deadline]);
			//	dp[i][j]=max(dp[i-1][j],dp[i-1][A[i].deadline-A[i].need]+A[i].profit);  //不选或者选，选的话就从d[i][A[i].deadline]开始 
		}  //理解：在选第i件物品的前提下，在天数j大于A[i].deadline以后，dp[i][j]的值都应该相同 
	}		//要么就是不选第i件物品，二者选一 
	printf("%d",dp[N][D]);
}
int main() {
	scanf("%d",&N);
	vector<Node> A(N+1);
	for(int i=1;i<=N;i++)
		scanf("%d%d%d",&A[i].profit,&A[i].need,&A[i].deadline);
	sort(A.begin(),A.end());
	Solve(A.back().deadline,A);
	return 0;
}
/*
5
7 1 3
10 2 3
6 1 2
5 1 1
2 2 1000 

3
6 3 3
3 2 2
4 1 3
*/
