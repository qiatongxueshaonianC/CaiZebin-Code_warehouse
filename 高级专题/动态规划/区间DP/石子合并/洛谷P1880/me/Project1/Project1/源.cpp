#include<bits/stdc++.h>
using namespace std;
const int maxn = 210;
int A[maxn], sum[maxn], N;
int dp1[maxn][maxn], dp2[maxn][maxn];
//dp[i][j]=max(dp[i][k]+dp[k+1][j]+sum[j]-sum[i-1]);
void Read() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> A[i];
		A[i + N] = A[i];
		sum[i] = sum[i - 1] + A[i];
	}
	for (int i = N + 1; i < 2 * N; i++)
		sum[i] = sum[i - 1] + A[i%N];
	sum[2 * N] = sum[N * 2 - 1] + A[N];
}
void Solve() {
//	fill(dp2[0],dp2[0]+maxn*maxn,-1);	//��ʼ����-1���ã���Ϊ��dp[i][k]��ʱ�򣬸տ�ʼi==k���Ǹ�1
	for (int len = 1; len <= N; len++) {
		for (int i = 1; i + len <= 2 * N; i++) {
			int j = i + len - 1;
			for (int k = i; k < j; k++) {
				dp1[i][j] = max(dp1[i][j], dp1[i][k] + dp1[k + 1][j] + sum[j] - sum[i - 1]);
				int tp = dp2[i][k] + dp2[k + 1][j] + sum[j] - sum[i - 1];
				if (dp2[i][j] == 0 || dp2[i][j] > tp) {
					dp2[i][j] = tp;
				}
			}
		}
	}
	int Min = 0x3fffffff, Max = -1;
	for (int i = 1; i <= N; i++) {
		Max = max(Max, dp1[i][i + N - 1]);
		Min = min(Min, dp2[i][i + N - 1]);
	}
	cout << Min << endl << Max << endl;
}
int main() {
	std::ios::sync_with_stdio(false);
	Read();
	Solve();
	return 0;
}
/*
4
4 5 9 4
*/