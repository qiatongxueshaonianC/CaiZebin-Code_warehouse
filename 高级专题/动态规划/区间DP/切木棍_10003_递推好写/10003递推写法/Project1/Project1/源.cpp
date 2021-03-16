#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<bitset>
#define lowbit(x) x&(-x)
using namespace std;
const int maxn = 60;
int L, n,dp[maxn][maxn];
int Solve(const vector<int>& A) {
	//fill(dp[0], dp[0] + maxn * maxn, INT_MAX);
	memset(dp, -1, sizeof(dp));
	for (int len = 1; len < A.size(); len++) {
		for (int left = 0; left + len <A.size(); left++) {
			int right = left + len;
			if (left + 1 == right)   //没有可切的地方
				dp[left][right] = 0;
			for (int k = left+1; k <= right-1; k++) {
				int t = dp[left][k] + dp[k][right] + A[right] - A[left];
				if (t < dp[left][right]||dp[left][right]<0) {
					dp[left][right] = t;
				}
			}
		}
	}
	return dp[0][A.size()-1];
}
int main() {
	while (~scanf("%d", &L) && L) {
		scanf("%d", &n);
		vector<int> A(n + 2);
		A[0] = 0; A[n + 1] = L;
		for (int i = 1; i <= n; i++)
			scanf("%d", &A[i]);
		printf("The minimum cutting is %d.\n", Solve(A));
	}
	return 0;
}
/*
100
3
25 50 75
10
4
4 5 7 8
0
*/