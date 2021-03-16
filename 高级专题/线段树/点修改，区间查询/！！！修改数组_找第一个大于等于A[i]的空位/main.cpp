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
const int maxn = 1000000 + 5;
int sum[maxn << 2], N, A[100005], ans[100005];
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
		sum[rt] = 0;	//这个query也做了修改，有点特殊 
		return l;
	}
	int Mid = (l + r) / 2, idx = 0;
	if (sum[rt * 2] >= 1&&Mid>=pos)	//寻找第一个>=pos的空位 
		idx = query(rt << 1, l, Mid, pos);
	else
		idx = query(rt << 1 | 1, Mid + 1, r, pos);
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
	return idx;
}
int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	build(1, 1, maxn);
	for (int i = 0; i < N; i++) {
		ans[i] = query(1, 1, maxn, A[i]);		//找第一个大于等于A[i]的空位 
	}
	printf("%d", ans[0]);
	for (int i = 1; i < N; i++)
		printf(" %d", ans[i]);
	return 0;
}
/*
5
2 1 1 3 4
*/
