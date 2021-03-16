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
	int ans = Base;		//Base��������ʾ���˼�յ�Ƶģ������ڵ�ǰ�ڵ�ŵƵĻ���ans��Base��ʼ����ʾ��ǰ��ŵ�
	for (auto i : G[now]) {	//�ŵ�
		if (i == father)
			continue;
		ans += DP(i, true, now);
	}
	if (father >= 0 && Place == false)	//�����ǰ�㲻�Ǹ������Ҹ��׽ڵ�û�ŵƣ���ônow->father�����ֵ�ֻ��һյ��
		ans++;

	int sum =inf;	
	if (father < 0 || Place == true) {	//���Բ��ŵ�������Ϊ�����߸��׽ڵ����
		sum = 0;				//��ǰ�㲻�ţ����Դ�0��ʼ
		for (auto i : G[now]) {
			if (i == father)
				continue;
			sum += DP(i, false, now);
		}
		if (father >= 0)	//������Ǹ�����ǰ�ֲ��ţ�����now->father�����ֵ�ֻ��һյ�ƣ�ֻ����->�Ͽ���
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
			if (vis[i][0] == false) {	//��û���ʹ���һ���µ���
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
