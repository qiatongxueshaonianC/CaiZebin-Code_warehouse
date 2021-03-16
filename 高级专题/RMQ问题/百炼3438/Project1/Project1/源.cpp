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
#define lowbit(x) x&(-x)
using namespace std;
const int maxn = 50010;
int Max[maxn][30], Min[maxn][30];
int N, Q;
vector<int> A;
void RMQ_init(vector<int> A) {
	int n = A.size();
	for (int i = 0; i < n; i++) {
		Max[i][0] = Min[i][0] = A[i];
	}
	for (int len = 1; (1 << len) <= n; len++) {
		for (int i = 0; i + (1 << len) <= n; i++) {
			Max[i][len] = max(Max[i][len - 1], Max[i + (1 << (len - 1))][len - 1]);
			Min[i][len] = min(Min[i][len - 1], Min[i + (1 << (len - 1))][len - 1]);
		}
	}
}
pair<int, int> RMQ(int L, int R) {
	int k = 0;
	while (1 << (k + 1) <= R - L + 1)
		k++;
	return make_pair(max(Max[L][k], Max[R - (1 << k) + 1][k]), min(Min[L][k], Min[R - (1 << k) + 1][k]));
}
int main() {
	cin >> N >> Q;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
	RMQ_init(A);
	while (Q--) {
		int L, R;
		scanf("%d%d", &L, &R);
		L--; R--;
		pair<int, int> ans = RMQ(L, R);
		printf("%d\n", ans.first - ans.second);
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