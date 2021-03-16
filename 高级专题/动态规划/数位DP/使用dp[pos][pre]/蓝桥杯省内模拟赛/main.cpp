#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<sstream>
#include<string>
#include<algorithm>
#include<climits>
#include<cmath>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<fstream>
#define lowbit(x) x&(-x)
using namespace std;
const int MOD = 10000;
int M, N,dp[1010][1010];
int DFS(int pos,int idx, int pre) {
	if (pos == 0) {
		return 1;
	}
	if (dp[idx][pre] != -1)
		return dp[idx][pre];
	int ans = 0;
	if (idx % 2 == 1) { //ÆæÊý
		int up = pre + 1;
		for (int i = up; i <= N; i++) {
			ans += DFS(pos - 1,idx+1, i);
			ans %= MOD;
		}
	}
	else {
		int up = pre - 1;
		for (int i = 1; i <= up; i++) {
			ans += DFS(pos - 1,idx+1, i);
			ans %= MOD;
		}
	}
	ans = ans % MOD;
	if (dp[idx][pre] == -1)
		dp[idx][pre] = ans;
	return ans;
}
int Solve() {
	int ans = 0;
	memset(dp, -1, sizeof(dp));
	ans += DFS(M, 1,0);
	return ans;
}
int A[2][3] = { 1,2,3,4 };
int main() {
	memset(dp,-1,sizeof(dp));
	cin>>M>>N;
	cout<<Solve();
	ofstream output;
	output.open("output.txt");
	for (N= 1; N <= 100; N++) {
		for (M = 1; M <= 100; M++) {
			output << Solve() << ',';
		}
	}
/*	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++)
			cout << A[i][j] << ',';
	}*/
	return 0;
}
/*
3 4
*/
