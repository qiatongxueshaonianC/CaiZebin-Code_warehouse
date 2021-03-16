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
#include<list>
#include<ctime>
using namespace std;
const int maxn = 1000000 + 5;
int sum[maxn << 2], N, A[1000005], ans[1000005];
void build(int rt, int L, int R) {
	if (L == R) {
		sum[rt] = 1;
		return;
	}
	int Mid = (L + R) / 2;
	build(rt*2, L, Mid);
	build(rt*2+1, Mid + 1, R);
	sum[rt] = sum[rt*2] + sum[rt*2+1];
}
int query(int rt, int l, int r, int pos) {
	if (l == r) {
		sum[rt] = 0;
		return l;
	}
	int Mid = (l + r) / 2, idx = 0;
	if (sum[rt * 2] >= 1&&Mid>=pos)
		idx = query(rt << 1, l, Mid, pos);
	else
		idx = query(rt << 1 | 1, Mid + 1, r, pos);
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	return idx;
}
int main() {
	scanf("%d", &N);
	A[0] = 2;
	clock_t start, finish;
	start = clock();
	for (int i = 1; i <= N; i++)
		A[i] = (A[i - 1] + 2) % 10007 + 1;
	build(1, 1, maxn);
	for (int i = 0; i < N; i++) {
		ans[i] = query(1, 1, maxn, A[i]);
	}
	printf("%d", ans[0]);
	for (int i = 1; i < N; i++)
		printf(" %d", ans[i]);
	finish = clock();
	cout << endl << finish - start << "/" << CLOCKS_PER_SEC << "(s)" << endl;
	return 0;
}
/*
5
2 1 1 3 4
*/