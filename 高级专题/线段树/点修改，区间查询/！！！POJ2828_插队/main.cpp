#pragma warning(disable:4996)
#include <iostream>
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
#include<bitset>
#include<list> 
#define lowbit(x) x&(-x)
using namespace std;
const int maxn = 200010;
int N, val[maxn], pos[maxn], ans[maxn], sum[maxn << 2];
void build(int rt, int L, int R) {
	if (L == R) {
		sum[rt] = 1;
		return;
	}
	int Mid = (L + R) / 2;
	build(rt << 1, L, Mid);
	build(rt << 1 | 1, Mid + 1, R);
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void update(int rt, int l, int r, int pos, int v) {
	if (l == r) {
		sum[rt] = 0;
		ans[l] = v;
		return;
	}
	int Mid = (l + r) / 2;
	if (sum[rt * 2] >= pos)	//左边空有足够多的位置 
		update(rt << 1, l, Mid, pos, v);
	else
		update(rt << 1 | 1, Mid + 1, r, pos-sum[rt*2], v);	//往右找第一个符号条件的空位 
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
int main() {
	while (cin >> N) {
		build(1, 1, N);
		for (int i = 0; i < N; i++)
			scanf("%d%d", &pos[i], &val[i]);
		for (int i = N - 1; i >= 0; i--) {
			update(1, 1, N, pos[i] + 1, val[i]);
		}
		for (int i = 1; i <= N; i++)
			printf("%d%s", ans[i], i == N ? "\n" : " ");
	}
	return 0;
}
/*
4
0 77
1 51
1 33
2 69
4
0 20523
1 19243
1 3890
0 31492
*/
