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
#define lowbit(x) x&(-x)
using namespace std;
const int maxn = 2 * 1e5 + 10;
const int maxv = 1e5;
int n, q, d[maxn][40], num[maxn], Left[maxn], Right[maxn];
vector<int> A(maxn), harsh(maxn);
void RMQ_init(const vector<int>& A) {
	int n = A.size();
	for (int i = 0; i < n; i++)
		d[i][0] = A[i];
	for (int len = 1; (1 << len) <= n; len++) {
		for (int i = 0; i + (1 << len) <= n; i++) {
			d[i][len] = max(d[i][len - 1], d[i + (1 << (len - 1))][len - 1]);
		}
	}
	int k;
}
int RMQ(int L, int R) {
	if (L > R)
		return 0;
	int k = 0;
	while (1 << (k + 1) <= R - L + 1)
		k++;
	return  max(d[L][k], d[R - (1 << k) + 1][k]);
}
void init() {
	memset(d, 0, sizeof(d));
	memset(Right, 0, sizeof(Right));
	memset(Left, 0, sizeof(Left));
	memset(num, 0, sizeof(num));
	fill(A.begin(), A.end(), 0);
	fill(harsh.begin(), harsh.end(), 0);
}
int main() {
	while (scanf("%d", &n) && n) {
		scanf("%d", &q);
		init();
		A[0] = -INT_MAX;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &A[i]);
			A[i] += maxv;
			harsh[A[i]]++;
			num[i] = A[i];
			if (A[i] != A[i - 1]) {
				Left[A[i]] = i;
				if (A[i - 1] >= 0)
					Right[A[i - 1]] = i - 1;
			}
		}
		Right[A[n]] = n;
		RMQ_init(harsh);
		for (int i = 0; i < q; i++) {
			int l, r;
			scanf("%d%d", &l, &r);
			if (num[l] == num[r]) 
				printf("%d\n", r - l + 1);
			else {
				int sum1 = Right[num[l]] - l + 1;
				int sum3 = r - Left[num[r]] + 1;
				int sum2 = RMQ(num[Right[num[l]] + 1], num[Left[num[r]] - 1]);
				printf("%d\n", max(sum1, max(sum2, sum3)));
			}
		}
	}
	return 0;
}
/*
10 6
-1 -1 1 1 1 1 3 10 10 10
2 3
1 10
5 10
3 4
1 4
3 10
0
*/
