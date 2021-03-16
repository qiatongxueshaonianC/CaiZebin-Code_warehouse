#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<ctime>
#include<iomanip>
#define lowbit(x) x&(-x)
using namespace std;
const int maxn = 110;
const int inf = 0x3fffffff;
int N, sum[maxn], dp[maxn][maxn], f[maxn][maxn], g[maxn][maxn];
vector<int> A;
bool vis[maxn][maxn];
//dp[i][j]=sum[i][j]-min(dp[i+1][j]������dp[j][j],dp[i][j-1]����dp[i][i],0);
//f[i][j]=min(dp[i+1][j]������dp[j][j])
//g[i][j]=min(dp[i][j-1]������dp[i][i]) 
#define c(i,j) (sum[j]-sum[i-1])
void init() {
	memset(sum, 0, sizeof(sum));
	fill(dp[0], dp[0] + maxn * maxn, 0);
	fill(f[0], f[0] + maxn * maxn, 0);
	fill(g[0], g[0] + maxn * maxn, 0);
	memset(vis, false, sizeof(vis));
}
int DP() {		//���֮Դ�����������������˷��˺ü���Сʱ
	for (int i = 1; i <= N; i++)
		f[i][i] = g[i][i] = dp[i][i] = A[i];
	for (int len = 1; len <= N; len++) {
		for (int i = 1; i + len <= N + 1; i++) {
			int j = i + len - 1;
			int m = 0;
			m = min(m, f[i + 1][j]);
			m = min(m, g[i][j - 1]);
			dp[i][j] = sum[j] - sum[i - 1] - m;
			f[i][j] = min(dp[i][j], f[i + 1][j]);
			g[i][j] = min(dp[i][j], g[i][j - 1]);
		}
	}
	printf("%d\n", 2 * dp[1][N] - sum[N]);
	return 0;
}
int main() {
	while (~scanf("%d", &N) && N) {
		init();
		A.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			sum[i] = sum[i - 1] + A[i];
		}
		DP();
	}
	return 0;
}
/*
4
4 -10 -20 7
4
1 2 3 4
0
*/