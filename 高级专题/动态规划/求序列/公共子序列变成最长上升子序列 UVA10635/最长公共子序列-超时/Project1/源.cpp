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
#include<iterator>
#include<bitset>
#define lowbit(x) x&(-x)
using namespace std;
const int maxn = 250 + 10;
int N, p, q;
vector<int> A, B;
vector<vector<int> >dp;
int DP() {
	int sz = max(p, q)+5;
	dp.resize(sz);
	fill(dp.begin(), dp.end(), vector<int>(sz,0));
	int ans = 0;
	for (int i = 1; i < A.size(); i++) {
		for (int j = 1; j < B.size(); j++) {
			if (A[i] == B[j]) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
				ans = max(ans, dp[i][j]);
			}
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return ans;
}
int main() {
	int t;
	scanf("%d", &t);
	for (int ii = 1; ii <= t; ii++) {
		scanf("%d%d%d", &N, &p, &q);
		A.resize(p+2); B.resize(q + 2);
		for (int i = 1; i <= p+1; i++)
			scanf("%d", &A[i]);
		for (int i = 1; i <= q+1; i++)
			scanf("%d", &B[i]);
		printf("Case %d: %d\n", ii, DP());
	}
	return 0;
}
/*
1
3 6 7
1 7 5 4 8 3 9
1 4 3 5 6 2 8 9
*/