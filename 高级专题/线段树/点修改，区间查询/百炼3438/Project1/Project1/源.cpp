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
#include<iterator>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<bitset>
#define lowbit(x) x&(-x);
using namespace std;
const int maxn = 50010;
int Max[maxn * 4], Min[maxn * 4];
int N, Q,ans1,ans2;
void build(int rt, int L, int R) {
	int Mid = (L + R) / 2;
	if (L == R) {
		scanf("%d", &Max[rt]);
		Min[rt] = Max[rt];
	}
	else {
		build(rt * 2, L, Mid);
		build(rt * 2 + 1, Mid + 1, R);
		Max[rt] = max(Max[rt * 2], Max[rt * 2 + 1]);
		Min[rt] = min(Min[rt * 2], Min[rt * 2 + 1]);
	}
}
void update(int rt, int l, int r, int pos, int num) {
	int Mid = (l + r) / 2;
	if (l == r && r == pos) {
		Max[rt] = num;
		Min[rt] = num;
	}
	else {
		if (pos <= Mid)
			update(rt * 2, l, Mid, pos, num);
		else
			update(rt * 2 + 1, Mid + 1, r, pos, num);
		Max[rt] = max(Max[rt * 2], Max[rt * 2 + 1]);
		Min[rt] = min(Min[rt * 2], Min[rt * 2 + 1]);
	}
}
void query(int rt, int l, int r, int L, int R) {
	int Mid = (l + r) / 2;
	if (L <= l && r <= R) {
		ans1 = max(ans1, Max[rt]);
		ans2 = min(ans2, Min[rt]);
	}
	else {
		if (L <= Mid)
			query(rt * 2, l, Mid, L, R);
		if (R > Mid)
			query(rt * 2 + 1, Mid + 1, r, L, R);
	}
}
int main() {
	cin >> N >> Q;
//	build(1, 1, N);
	for (int i = 1; i <= N; i++) {
		int x;
		scanf("%d", &x);
		update(1, 1, N, i, x);
	}
	while (Q--) {
		int L, R;
		ans1 = -INT_MAX; ans2 = INT_MAX;
		scanf("%d%d", &L, &R);
		query(1,1,N,L,R);
		printf("%d\n", ans1-ans2);
	}
	return 0;
}
/*
6 3
1
7
3
4
2
5
1 5
4 6
2 2
*/