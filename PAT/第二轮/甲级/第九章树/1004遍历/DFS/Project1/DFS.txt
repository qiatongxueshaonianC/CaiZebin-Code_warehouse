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
#include<stack>
#include<list>
#include<ctime>
#include<iomanip>
using namespace std;
const int maxn = 110;
vector<vector<int>> G;
int N,M,ans[maxn],Max_level;
void DFS(int id, int level) {
	if (G[id].size() == 0) {
		ans[level]++;
		Max_level = max(Max_level, level);
		return;
	}
	for (auto i : G[id]) {
		DFS(i, level + 1);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	while (cin >> N && N) {
		G.resize(N + 1);
		memset(ans, 0, sizeof(ans));
		cin >> M;
		for (int i = 0; i < M; i++) {
			int id, k,u;
			cin >> id >> k;
			while (k--) {
				cin >> u;
				G[id].push_back(u);
			}
		}
		DFS(1, 1);
		for (int i = 1; i <= Max_level; i++) {
			cout << ans[i] << (i == Max_level ? "\n" : " ");
		}
	}
	return 0;
}
/*
2 1
01 1 02
*/