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
#pragma GCC optimize(2)
const int maxn = 802;
const int maxt = (maxn << 2);
struct node {
	int Min, Max, rty;
};
struct row {
	int rtx;
	node y[maxt];
};
row x[maxt];
int N, A[maxn][maxn], T, ans1, ans2;
void pushupy(int rtx, int rty) {
	x[rtx].y[rty].Max = max(x[rtx].y[rty << 1].Max, x[rtx].y[rty << 1 | 1].Max);
	x[rtx].y[rty].Min = min(x[rtx].y[rty << 1].Min, x[rtx].y[rty << 1 | 1].Min);
}
void buildy(int rtx, int rty, int L, int R, int posx) {
	if (L == R) {
		if (posx)
			x[rtx].y[rty].Max = x[rtx].y[rty].Min = A[posx][L];
		else {
			x[rtx].y[rty].Min = min(x[rtx << 1].y[rty].Min, x[rtx << 1 | 1].y[rty].Min);
			x[rtx].y[rty].Max = max(x[rtx << 1].y[rty].Max, x[rtx << 1 | 1].y[rty].Max);
		} 
		return;
	}
	int Mid = (L + R) / 2;
	buildy(rtx, rty << 1, L, Mid, posx);
	buildy(rtx, rty << 1 | 1, Mid + 1, R, posx);
	pushupy(rtx, rty);
}
void buildx(int rt, int L, int R) {
	if (L == R) {
		buildy(rt, 1, 1, N, L);
		return;
	}
	int Mid = (L + R)/2;
	buildx(rt << 1, L, Mid);
	buildx(rt << 1 | 1, Mid + 1, R);
	buildy(rt, 1, 1, N, 0);
}
void updatey(int rtx, int rty, int L, int R, int posx, int posy, int val) {
	if (L == R) {
		if (posx)
			x[rtx].y[rty].Max = x[rtx].y[rty].Min = val;
		else {
			x[rtx].y[rty].Max = max(x[rtx << 1].y[rty].Max, x[rtx << 1 | 1].y[rty].Max);
			x[rtx].y[rty].Min = min(x[rtx << 1].y[rty].Min, x[rtx << 1 | 1].y[rty].Min);
		}
		return;
	}
	int Mid = (L + R) / 2;
	if (posy <= Mid)
		updatey(rtx, rty << 1, L, Mid, posx, posy, val);
	else 
		updatey(rtx, rty << 1 | 1, Mid + 1, R, posx, posy, val);
	pushupy(rtx, rty);
}
void updatex(int rt, int L, int R, int posx, int posy, int val) {
	if (L == R) {
		updatey(rt, 1, 1, N, L, posy, val);
		return;
	}
	int Mid = (L + R) / 2;
	if(posx<=Mid)
		updatex(rt << 1, L, Mid, posx, posy, val);
	else
		updatex(rt << 1 | 1, Mid + 1, R, posx, posy, val);
	updatey(rt, 1, 1, N, 0, posy, val);
}
void queryy(int rtx, int rty, int l, int r, int L, int R) {
	if (L <= l && r <= R) {
		ans1 = min(x[rtx].y[rty].Min, ans1);
		ans2 = max(x[rtx].y[rty].Max, ans2);
		return;
	}
	int Mid = (l + r) / 2;
	if (L <= Mid)
		queryy(rtx, rty << 1, l, Mid, L, R);
	if (R > Mid)
		queryy(rtx, rty << 1 | 1, Mid + 1, r, L, R);
}
void queryx(int rt, int l, int r, int x1, int y1, int x2, int y2) {
	if (x1 <= l && r <= x2) {
		queryy(rt, 1, 1, N, y1, y2);
		return;
	}
	int Mid = (l + r) / 2;
	if (x1 <= Mid)
		queryx(rt << 1, l, Mid, x1, y1, x2, y2);
	if (x2 > Mid)
		queryx(rt << 1 | 1, Mid + 1, r, x1, y1, x2, y2);
}
int main() {
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		printf("Case #%d:\n", ii);
		scanf("%d", &N);
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++)
				scanf("%d", &A[i][j]);
		}
		buildx(1, 1, N);
		int Q;
		scanf("%d", &Q);
		while (Q--) {
			int x, y, L;
			scanf("%d%d%d", &x, &y, &L);
			int x1 = max(1, x - L / 2);
			int x2 = min(N, x + L / 2);
			int y1 = max(1, y - L / 2);
			int y2 = min(N, y + L / 2);
			ans1 = INT_MAX; ans2 = -INT_MAX;
			queryx(1, 1, N, x1, y1, x2, y2);
			int ans = (ans2 + ans1) / 2;
			printf("%d\n", ans);
			updatex(1, 1, N, x, y, ans);
		}
	}
	return 0;
}
/*
1
3
1 2 3
4 5 6
7 8 9
5
2 2 1
3 2 3
1 1 3
1 2 3
2 2 3
*/
