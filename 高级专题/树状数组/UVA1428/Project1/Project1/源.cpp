#pragma warning(disable:4996)
#include<iostream>
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
#include<list>
#include<bitset>
#define lowbit(x) x&(-x);
using namespace std;
const int maxn = 1e5 + 10;
int T,A[maxn],n;
long long l[maxn], r[maxn], c[maxn];
void Add(int x, int v) {
	while (x < maxn) {
		c[x] += v;
		x += lowbit(x);
	}
}
long long sum(int x) {
	long long sum = 0;
	while (x > 0) {
		sum += c[x];
		x -= lowbit(x);
	}
	return sum;
}
long long Solve(int n) {
	memset(c, 0, sizeof(c));
	memset(l, 0, sizeof(l));
	memset(r, 0, sizeof(r));
	for (int i = 1; i <= n; i++) {
		Add(A[i], 1);
		l[i] = sum(A[i] - 1);  //l[i]:左边比它小的数
	}
	memset(c, 0, sizeof(c));
	for (int i = n; i >= 1; i--) {
		Add(A[i], 1);
		r[i] = sum(A[i] - 1);  //r[i]:右边比它小的数
	}
	long long ans = 0;
	for (int i = 2; i < n; i++)
		ans += l[i] * (n - i - r[i]) + r[i] * (i - 1 - l[i]);
	return ans;
}
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &A[i]);
		printf("%lld\n", Solve(n));
	}
	return 0;
}
/*
1
3 1 2 3
*/