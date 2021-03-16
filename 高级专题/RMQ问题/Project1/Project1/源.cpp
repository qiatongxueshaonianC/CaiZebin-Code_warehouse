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
const int maxn = 1e5 + 10;
int d[maxn][40];
void RMQ_init(const vector<int>& A) {
	int n = A.size();
	for (int i = 0; i < n; i++)
		d[i][0] = A[i];
	for (int len = 1; (1 << len) <= n; len++) {
		for (int i = 0; i + (1 << len) <= n; i++)
			d[i][len] = min(d[i][len - 1], d[i + (1 << len - 1)][len - 1]);
	}
}
int RMQ(int L, int R) {
	int k = 0;
	while (1 << (k + 1) <= R - L + 1)
		k++;
	return min(d[L][k], d[R - (1 << k) + 1][k]);  //这里要记得+1，否则到不了右端点
}
int main() {
	vector<int> A(maxn);
	for (int i = 0; i <= 10000; i++)
		A[1000+i]=(i * 2);
	RMQ_init(A);
	printf("%d", RMQ(1001, 1022));
	return 0;
}