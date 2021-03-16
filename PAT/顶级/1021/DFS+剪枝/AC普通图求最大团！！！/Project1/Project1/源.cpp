#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int M, N, dp[maxn], A[maxn], Price[maxn], ans_price, G[maxn][maxn], Stack[maxn][maxn], best, mx;
vector<int> temp, ans;
void DFS(int step, int total, int cnt, int price) {
	if (total == 0) {
		if (best < cnt || (best == cnt && price < ans_price)) {
			best = cnt;
			ans = temp;
			ans_price = price;
		}
		return;
	}
	for (int i = 0; i < total; i++) {
		if (cnt + total - i < best)
			return;
		int u = Stack[step][i];
		if (cnt + dp[u] < best)
			return;
		int sz = 0;
		for (int j = i + 1; j < total; j++) {
			int v = Stack[step][j];
			if (!G[A[u]][A[v]])
				Stack[step + 1][sz++] = Stack[step][j];
		}
		temp.push_back(A[u]);
		DFS(step + 1, sz, cnt + 1, price + Price[A[u]]);
		temp.pop_back();
	}
}
int Max_clique() {
	int i, j;
	best = 0;
	for (int i = N - 1; i >= 0; i--) {
		int sz = 0;
		for (int j = i + 1; j < N; j++) {
			if (!G[A[i]][A[j]])
				Stack[1][sz++] = j;
		}
		temp.push_back(A[i]);
		DFS(1, sz, 1, Price[A[i]]);
		temp.pop_back();
		dp[i] = best;
	}
	return best;
}
void Solve() {
	//	fill(G[0],G[0]+maxn*maxn,1);
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u][v] = G[v][u] = 1;
	}
	for (int i = 0; i < N; i++) {
		int v;
		scanf("%d%d", &A[i], &v);
		Price[A[i]] = v;
	}
	Max_clique();
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%03d%s", ans[i], i == ans.size() - 1 ? "\n" : " ");
	printf("%d", ans_price);
}
int main() {
	cin >> M >> N;
	Solve();
	return 0;
}
/*
16 20
001 002
003 004
004 005
005 006
006 007
007 008
008 003
009 010
009 011
009 012
009 013
010 014
011 015
012 016
012 017
013 018
020 99
019 99
018 4
017 2
016 3
015 6
014 5
013 1
012 1
011 1
010 1
009 10
008 1
007 2
006 5
005 3
004 4
003 6
002 1
001 2
*/