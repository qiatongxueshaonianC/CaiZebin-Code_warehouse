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
const int maxn = 1e5+ 10;
int N, K,d[maxn][30];
vector<int> A;
vector<pair<int, int> > mp;
void RMQ_init() {
	for (int i = 0; i < A.size(); i++)
		d[i][0] = A[i];
	for (int len = 1; (1 << len) <= A.size(); len++) {
		for (int i = 0; i + (1 << len) <= A.size(); i++) {
			d[i][len] = max(d[i][len - 1], d[i + (1 <<( len - 1))][len - 1]);
		}
	}
}
int RMQ(int L, int R) {
	int k = 0;
	while ((1 << (k + 1)) <= R - L + 1)
		k++;
	return max(d[L][k], d[R - (1 << k)+1][k]);
}
int Find(vector<pair<int,int> > B, int pos, int val) {
	int idx = pos;
	for(; idx < B.size(); idx++) {
		if (B[idx].first == val)
			break;
	}
	return idx;
}
void Solve() {
	int L=0, R;
	bool flag = false;
	for (int i = 0; i < K; i++) {
		R = N - K + i;
		int val = RMQ(L, R);
		printf("%d ",val );
		L =Find(mp,L,val)+1; //2020/4/18/0：45发现，这里还要加一
	}
}
int main() {
	cin >> N >> K;
	A.resize(N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
		mp.push_back(make_pair(A[i], i));
	}
	RMQ_init();
	Solve();
	return 0;
}
/*
5 3
3 1 2 5 4

10 6
10 7 9 20 17 10 7 9 20 17
*/