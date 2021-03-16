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
#include<fstream>
#include<ctime>
#include<iterator>
using namespace std;
const int maxn = 1000;
int M, N, dp[maxn], A[maxn], Price[maxn], ans_price, G[maxn][maxn], Stack[maxn][maxn], best, mx;
vector<int> temp, ans;
void DFS(int step, int total, int cnt) {
	if (total == 0) {
		if (best < cnt) {
			best = cnt;
			ans = temp;
			//	ans_price=price;
		}
		return;
	}
	for (int i = 0; i < total; i++) {
		if (cnt + total - i <= best)
			return;
		int u = Stack[step][i];
		if (cnt + dp[u] <= best)
			return;
		int sz = 0;
		for (int j = i + 1; j < total; j++) {
			int v = Stack[step][j];
			if (G[u][v])
				Stack[step + 1][sz++] = Stack[step][j];
		}
		temp.push_back(u);
		DFS(step + 1, sz, cnt + 1);
		temp.pop_back();
	}
}
int Max_clique() {
	memset(G, 0, sizeof(G));
	G[0][1] = G[1][0] = 1;
	G[0][2] = G[2][0] = 1;
	G[0][3] = G[3][0] = 1;
	G[0][4] = G[4][0] = 1;
	G[2][1] = G[1][2] = 1;
	G[3][1] = G[1][3] = 1;
//	G[2][3] = G[3][2] = 1;
	N = 5;
	int i, j;
	best = 0;
	for (int i = N - 1; i >= 0; i--) {
		int sz = 0;
		for (int j = i + 1; j < N; j++) {
			if (G[i][j])
				Stack[1][sz++] = j;
		}
		temp.push_back(i);
		DFS(1, sz, 1);
		temp.pop_back();
		dp[i] = best;
	}
	return best;
}
void Solve() {
	Max_clique();
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
		printf("%03d%s", ans[i], i == ans.size() - 1 ? "\n" : " ");
	printf("%d", ans_price);
}
int main() {
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
