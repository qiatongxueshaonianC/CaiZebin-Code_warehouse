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
const int maxn = 1010;
int N;
vector<int> A;
long long l[maxn], c[maxn];
void Add(int x, int v) {
	while (x < maxn) {
		c[x] += v;
		x += lowbit(x);
	}
}
int getsum(int x) {
	int sum = 0;
	while (x > 0) {
		sum += c[x];
		x -= lowbit(x);
	}
	return sum;
}
void Solve() {
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			memset(c, 0, sizeof(c));
			memset(l, 0, sizeof(l));
			reverse(A.begin() + i, A.begin() + j + 1);
			for (int k = 1; k <= N; k++) {
				Add(A[k], 1);
				l[k] = getsum(A[k] - 1);
			}
			long long ans = 0;
			for (int k = 2; k <= N; k++)
				ans += (k - 1 - l[k]);
			printf("%lld%s", ans,i==N&&j==N?"":" ");
			reverse(A.begin() + i, A.begin() + j + 1);
		}
	}
}
int main() {
	cin >> N;
	A.resize(N + 1);
	for (int i = 1; i <= N; i++)
		scanf("%d", &A[i]);
	Solve();
	return 0;
}
/*
3
2 1 3
*/
