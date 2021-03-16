#pragma warning(disable:4996)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int N, s[maxn][maxn], dp[maxn][maxn];
vector<int> A;
int main() {
	scanf("%d", &N);
	A.resize(N + 2);
	A[0] = A[N + 1] = 1;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 1; i <= N; i++) {
		s[i][i] = i;
	}
/*	1.考虑len的值是从1到N还是1到N-1，在不考虑平行四边形优化的时候，直接从1到N不容易错
		在本题中，当len从1~N-1时，导致j=i+len，这也在状态转移方程中产生的问题是dp[2][2]无法直接
		确定，所以要么len从1取到N，j=i+len-1,要么想办法确定dp[2][2]这种边界的值

	2.要使用平行四边形优化，最好是用len从1取到N-1的不容易出错。
	本题若用j=i+len-1会导致下面的k值变成0，导致第一个状态转移方程中
	A[i - 1] * A[k] * A[j + 1];算出来的值不正确，所以需要用j=i+len的表达方式，对应的需要
	在一开始做一些初始化，确定边界的dp[i][i]值。*/
	for (int i = 1; i <= N; i++) {
		dp[i][i] = A[i - 1] * A[i] * A[i + 1];//边界做单独处理初始化
	}
	for (int len = 1; len < N; len++) {
		for (int i = 1; i + len <= N ; i++) {
			int j = i + len;
			for (int k = s[i][j - 1]; k <= s[i + 1][j]; k++) {
				int tp = dp[i][k - 1] + dp[k + 1][j] + A[i - 1] * A[k] * A[j + 1];
				if (tp > dp[i][j]) {
					dp[i][j] = tp;
					s[i][j] = k;
				}
			}
		}
	}
	cout << dp[1][N];
	return 0;
}
/*
4
3 1 5 8
*/