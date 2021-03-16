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
int N,A[maxn],sum;
void init(int n) {
	vector<int> C(n + 1);
	for (int i = n - 1; i >= 0; i--) {
		int x = A[i], y = A[i];
		for (x; x > 0; x -= lowbit(x))
			sum += C[x];	//求的是逆序数，右边比它小的总和 
		for (y; y <= n; y += lowbit(y))
			C[y]++;
	}
}
void Solve() {
	for (int i = 0; i < N; i++) {
		vector<int> C(N + 1);
		int ans = 0;
		for (int j = i; j < N; j++) {
			int x = A[j], y = A[j],left_less_than=0,left_more_than=0;
			for (x; x > 0; x -= lowbit(x))  //求左边比它小
				left_less_than += C[x];
			for (y; y <= N; y += lowbit(y))	//更新 
				C[y]++;
			left_more_than = j - i - left_less_than;
			ans += (left_less_than - left_more_than);
			printf("%s%d", j == 0 ? "" : " ", sum + ans);
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	init(N);
	Solve();
	return 0;
}
/*
3
2 1 3
*/
