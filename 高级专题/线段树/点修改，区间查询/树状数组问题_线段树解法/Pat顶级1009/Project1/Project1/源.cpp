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
#include<bitset>
#define lowbit(x) x&(-x)
using namespace std;
typedef long long LL;
const LL maxn = 1e5 + 10;
LL sum[maxn*4],N,Left[maxn],Right[maxn],A[maxn];
void build(int rt, int L, int R) {
	int Mid = (L + R) / 2;
	if (L == R) //到达叶子节点
		scanf("%d", &sum[rt]);
	else {
		build(rt * 2, L, Mid);
		build(rt * 2 + 1, Mid + 1, R);
		sum[rt] = sum[rt * 2] + sum[rt * 2 + 1];
	}
}
void update(LL rt, LL L, LL R, LL pos, LL num) {
	LL Mid = (L + R) / 2;
	if (L == R && L == pos) {
		sum[rt] += num;
	}
	else {
		if (pos <= Mid)
			update(rt * 2, L, Mid, pos, num);
		else
			update(rt * 2 + 1, Mid + 1, R, pos, num);
		sum[rt] = sum[rt * 2] + sum[rt * 2 + 1];
	}
}
LL query(LL rt, LL l, LL r, LL L, LL R) {
	if (L > R)
		return 0;
	if (L <= l && r <= R)
		return sum[rt];
	else {
		LL Mid = (l + r) / 2,temp=0;
		if (L <= Mid)
			temp += query(rt * 2, l, Mid, L, R);
		if (R > Mid)
			temp += query(rt * 2 + 1, Mid + 1, r, L, R);
		return temp;
	}
}
int main() {
	cin >> N;
//	build(1, 1, N);
//	cout << query(1, 1, N, 1, N) << endl;  //区间求的是输入的“第一个值”即数字1出现了几次
	memset(sum, 0, sizeof(sum));
	for (LL i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		update(1, 1, N, A[i], 1);
		Left[i] = query(1, 1, N, 1, A[i]-1);
	}
	memset(sum, 0, sizeof(sum));
	for (LL i = N - 1; i >= 0; i--) {
		update(1, 1, N, A[i], 1);
		Right[i] = query(1, 1, N, 1, A[i]-1);
	}
	LL ans = 0;
	for (LL i = 1; i < N-1; i++) {
		ans += (i - Left[i])*Right[i];
	}
//	cout << query(1, 1, N, 1, 1)<<endl;  //区间【1，1】即数字1出现了几次
	cout << ans;
	return 0;
}
/*
5
5 1 4 3 2
22
1 2 3 4 5 16 6 7 8 9 10 19 11 12 14 15 17 18 21 22 20 13
*/