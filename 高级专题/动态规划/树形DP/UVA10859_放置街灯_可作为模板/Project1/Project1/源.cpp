#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int Base = 2000;
const int inf = 0x3fffffff;
int N,M,dp[maxn][2];
vector<vector<int> > G(maxn);
bool vis[maxn][2];
void init() {
	fill(G.begin(), G.end(), vector<int>());
	fill(&dp[0][0], &dp[0][0] + maxn*2, 0);
	memset(vis, false, sizeof(vis));
}
int DP(int now, bool Place, int father) {
	if (vis[now][Place])
		return dp[now][Place];
	vis[now][Place] = true;
	int ans = Base;		//Base是用来表示放了几盏灯的，所以在当前节点放灯的话，ans从Base开始，表示当前点放灯
	for (auto i : G[now]) {	//放灯
		if (i == father)
			continue;
		ans += DP(i, true, now);
	}
	if (father >= 0 && Place == false)	//如果当前点不是根，并且父亲节点没放灯，那么now->father这条街道只有一盏灯
		ans++;

	int sum =inf;	
	if (father < 0 || Place == true) {	//可以不放的条件：为根或者父亲节点放了
		sum = 0;				//当前点不放，所以从0开始
		for (auto i : G[now]) {
			if (i == father)
				continue;
			sum += DP(i, false, now);
		}
		if (father >= 0)	//如果不是根，当前又不放，所以now->father这条街道只有一盏灯，只从下->上考了
			sum++;
	}
	ans = min(ans, sum);
	dp[now][Place]=ans;
	return ans;
}
int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 1; ii <= t; ii++) {
		init();
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			G[u].push_back(v);
			G[v].push_back(u);
		}
		int ans = 0;
		for (int i = 0; i < N; i++) {
			if (vis[i][0] == false) {	//还没访问过，一棵新的树
				ans+=DP(i, 0, -1);
			}
		}
		printf("%d %d %d\n", ans/Base, M- ans % Base, ans%Base);
	}
	return 0;
}
/*
2
4 3
0 1
1 2
2 3
5 4
0 1
0 2
0 3
0 4
*/
