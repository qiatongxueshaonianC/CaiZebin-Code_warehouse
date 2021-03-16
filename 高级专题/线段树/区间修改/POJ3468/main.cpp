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
using namespace std;
typedef long long LL;
const int maxn = 100000 + 5;
LL sum[maxn << 2], Set[maxn << 2], add[maxn << 2];
int N, M;
void build(int rt, int L, int R) {
	if (L == R) {
		scanf("%lld", &sum[rt]);
		return;
	}
	int Mid = (L + R) >> 1;
	build(rt << 1, L, Mid);
	build(rt << 1 | 1, Mid + 1, R);
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void pushdown_add(int rt, int len) {
	add[rt << 1] += add[rt];
	add[rt << 1 | 1] += add[rt];
	sum[rt << 1] += (len - (len >> 1))*add[rt];  //2020/5/2/1:29发现，移位的优先级很低！！！
	sum[rt << 1 | 1] += (len >> 1)*add[rt];
	add[rt] = 0;
}
void update(int rt, int l, int r, int L, int R, int val, int op) {
	if (L<=l && r <= R) {
		add[rt] += val;
		sum[rt] += (r - l + 1)*val;
		return;
	}
	int Mid = (l + r) >> 1;
	if (add[rt])
		pushdown_add(rt, r - l + 1);
	if (L <= Mid)
		update(rt << 1, l, Mid, L, R, val, op);
	if (R > Mid)
		update(rt << 1 | 1, Mid + 1, r, L, R, val, op);
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
LL query(int rt, int l, int r, int L, int R) {
	if (L<=l && r <= R)
		return sum[rt];
	if (add[rt])
		pushdown_add(rt, r - l + 1);
	int Mid = (l + r) >> 1 ;
	LL temp = 0;
	if (L <= Mid)
		temp += query(rt << 1, l, Mid, L, R);
	if (R > Mid)
		temp += query(rt << 1 | 1, Mid + 1, r, L, R);
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	return temp;
}
int main() {
	scanf("%d%d", &N, &M);
	build(1, 1, N); getchar();
	while (M--) {
		int L, R, v;
		char op;
		scanf("%c", &op);
		if (op == 'Q') {
			scanf("%d%d%*c", &L, &R);
			printf("%lld\n", query(1, 1, N, L, R));
		}
		else {
			scanf("%d%d%d%*c", &L, &R, &v);
			update(1, 1, N, L, R, v, 1);
		}
	};
	return 0;
}
/*
10 5
1 2 3 4 5 6 7 8 9 10
Q 4 4
Q 1 10
Q 2 4
C 3 6 3
Q 2 4
*/
