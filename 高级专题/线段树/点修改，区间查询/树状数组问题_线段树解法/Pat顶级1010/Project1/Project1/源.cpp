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
#include<set>
#include<map>
#include<queue>
#include<list>
#include<iterator>
#define lowbit(x) x&(-x);
#define lson rt<<2,L,Mid
#define rson (rt<<2)|1,Mid+1,R
using namespace std;
const int maxn = 1e5 + 10;
int N, A[maxn], sum[maxn << 2], right_lessthan[maxn];
vector<pair<double, int> > ipt;
void update(int rt, int L, int R, int pos, int num) {
	if (L == R && pos == L) {
		sum[rt] += num;
	}
	else {
		int Mid = (L + R) / 2;
		if (pos <= Mid)
			update(rt * 2, L, Mid, pos, num);
		else
			update(rt * 2 + 1, Mid + 1, R, pos, num);
		sum[rt] = sum[rt * 2] + sum[rt * 2 + 1];
	}
}
int query(int rt, int l, int r, int L, int R) {
	if (L > R)
		return 0;
	if (L <= l && r <= R)
		return sum[rt];
	int Mid = (l + r) / 2, temp = 0;
	if (L <= Mid)
		temp += query(rt * 2, l, Mid, L, R);
	if (R > Mid)
		temp += query(rt * 2 + 1, Mid + 1, r, L, R);
	return temp;
}
void Solve(int n) {
	ipt.resize(n);
	for (int i = 0; i < n; i++) {
		scanf("%lf", &ipt[i].first);
		ipt[i].second = i;
	}
	sort(ipt.begin(), ipt.end());
	int rank = 1;
	A[ipt[0].second] = rank;
	for (int i = 1; i < ipt.size(); i++) { //ÀëÉ¢»¯
		rank = ipt[i].first == ipt[i - 1].first ? rank : i + 1;
		A[ipt[i].second] = rank;
	}
	for (int i = n - 1; i >= 0; i--) {
		update(1, 1, n, A[i], 1);
		right_lessthan[i] = query(1, 1, n, 1, A[i] - 1);
	}
	for (int i = 0; i < n; i++)
		printf("%d%s", right_lessthan[i], i == n - 1 ? "" : " ");
}
int main() {
	scanf("%d", &N);
	Solve(N);
	return 0;
}
/*
6
24 35 12 1 56 23
*/