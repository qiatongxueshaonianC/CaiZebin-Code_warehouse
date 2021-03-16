#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<bitset>
using namespace std;
const int maxn = 10240;
int d[20], dp[20][maxn], E[31]; //如果是pre类型的话，用的是dp[20][10],但现在是dp[pos][sum],sum需要计算 
void init() {
	E[0] = 1;
	for (int i = 1; i <= 30; i++)
		E[i] = E[i - 1] * 2;
}
int Cnt(int k) {
	int len = 0, result = 0, D[20];
	while (k != 0) {
		D[len++] = k % 10;
		k /= 10;
	}
	for (int i = 0; i < len; i++)
		result += D[i] * E[i];
	return result;
}
int DFS(int pos, int sum, bool ALL0, bool isLimit) {
	if (pos == -1)
		return sum >= 0 ? 1 : 0;
	if (sum < 0)		//剪枝 
		return 0;
	if (!ALL0 && !isLimit&&dp[pos][sum] != -1)
		return dp[pos][sum];
	int up = isLimit ? d[pos] : 9;
	int ans = 0;
	for (int i = 0; i <= up; i++)
		ans += DFS(pos - 1, sum - i * E[pos], ALL0&&i == 0, isLimit&&i == d[pos]);
	if (!ALL0 && !isLimit)
		dp[pos][sum] = ans;
	return ans;
}
int Solve(int A, int B) {
	int len = 0;
	while (B != 0) {
		d[len++] = B % 10;
		B /= 10;
	}
	return DFS(len - 1, Cnt(A), true, true);
}
int main() {
	init();
	int T, m, n;
	scanf("%d", &T);
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= T; i++) {
		scanf("%d%d", &m, &n);
		printf("Case #%d: %d\n", i, Solve(m, n));
	}
	return 0;
}
/*
3
0 100
1 10
5 100
0 1000000000
*/