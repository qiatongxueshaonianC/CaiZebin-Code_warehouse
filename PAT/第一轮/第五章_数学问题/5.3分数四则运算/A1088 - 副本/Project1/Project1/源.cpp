#pragma warning(disable:4996)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 50001;
double dp[maxn],DP1[maxn];
int main() {
	for (int i = 1; i <= maxn; i++) {
		DP1[i] = DP1[i - 1] + 1.0 / i;
	}
	int Max = 0, n;
	while (~scanf("%d", &n) && n != 0) {
		for (int i = Max + 1; i <= n; i++) {
			dp[i] = DP1[i] + DP1[i] - 1.0 + dp[i - 1];
		}
		printf("%.2lf\n",dp[n]);
		Max = max(Max, n);
	}
	return 0;
}
/*
2/3 -4/2
*/