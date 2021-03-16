#include<bits/stdc++.h>
using namespace std;
const int maxn = 1000;
int N, M, Price[maxn], Sum[maxn], A[maxn], ans_price;
int G[maxn][maxn];
vector<int> temp, ans;
bool ok(int idx) {
	for (auto i : temp)
		if (G[idx][i]==1)
			return false;
	return true;
}
void DFS(int idx, int price) {
	if ((temp.size() + N  - idx) < ans.size())
		return;
	if ((temp.size() + N  - idx) == ans.size() && (price + Sum[idx]) > ans_price)
		return;
	if (idx == N) {
		if (temp.size() > ans.size()) {
			ans = temp;
			ans_price = price;
		}
		else if (temp.size() == ans.size() && price < ans_price) {
			ans = temp;
			ans_price = price;
		}
		return;
	}
	if (ok(A[idx])) { //选第idx个 
		temp.push_back(A[idx]);
		DFS(idx + 1, price + Price[A[idx]]);
		temp.pop_back();
	}
	DFS(idx + 1, price); 	//不选； 
}
void Solve() {
	for (int i = 0; i < M; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		G[u][v]=G[v][u]=1;
	}
	for (int i = 0; i < N; i++) {
		int v;
		scanf("%d%d", &A[i], &v);
		Price[A[i]] = v;
	}
	Sum[N - 1] = Price[A[N - 1]];
	for (int i = N - 2; i >= 0; i--)
		Sum[i] = Sum[i + 1] + Price[A[i]];
	DFS(0, 0);
	printf("%d\n", ans.size());
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		printf("%03d%s", ans[i], i == ans.size() - 1 ? "\n" : " ");
	printf("%d\n", ans_price);
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
