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
#define lowbit(x) x&(-x);
using namespace std;
const int maxn = 100010;
int Max[maxn * 4];
int N, M, ans, idx = 1;;
map<int, set<int> >A;   //用来记录位置，表示某一个数它出现的位置有哪些
void build(int rt, int L, int R) {
	int Mid = (L + R) / 2;
	if (L == R) {//到达叶子节点
		scanf("%d", &Max[rt]);
		if (A.find(Max[rt]) == A.end()) {
			set<int> st;
			st.insert(idx++);
			A.insert(make_pair(Max[rt], st));
		}
		else {
			A[Max[rt]].insert(idx++);
		}
	}
	else {
		build(rt * 2, L, Mid);
		build(rt * 2+1, Mid + 1, R);
		Max[rt] = max(Max[rt * 2], Max[rt * 2 + 1]);
	}
}
void update(int rt, int L, int R, int pos, int num) {
	int Mid = (L + R) / 2;
	if (L == R && R == pos)
		Max[rt] = num;
	else {
		if (pos <= Mid)
			update(2 * rt, L, Mid, pos, num);
		else
			update(2 * rt + 1, Mid + 1, R, pos, num);
		Max[rt] = max(Max[rt * 2], Max[rt * 2 + 1]);
	}
}
void query(int rt, int l, int r, int L, int R) {
	int Mid = (l + r) / 2;
	if (L <= l && r <= R)
		ans = max(ans, Max[rt]);
	else {
		if (L <= Mid)
			query(rt * 2, l, Mid, L, R);
		if (R > Mid)
			query(rt * 2 + 1, Mid + 1,r, L, R);
	}
}
int main() {
	cin >> N >> M; 
	build(1, 1, N);
	int L=1, R=N-M+1;
	for (int k = 1; k <= M; k++) {
		ans = -INT_MAX;
		query(1, 1, N, L, R);
		printf("%d%s", ans, k == M ? "" : " ");
		R++;
		L = *lower_bound(A[ans].begin(),A[ans].end(),L)+1;
	}
	return 0;
}
/*
5 3
3 1 2 5 4

10 6
10 7 9 20 17 10 7 9 20 17
*/