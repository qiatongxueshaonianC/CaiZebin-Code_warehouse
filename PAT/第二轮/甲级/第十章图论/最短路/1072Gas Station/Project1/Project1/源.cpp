#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<climits>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<ctime>
#include<iomanip>
#include<fstream>
using namespace std;
const int maxn = 1e3 + 20;
const int inf = 0x3fffffff;
struct Edge {
	int from, to, dis;
	Edge(int a, int b, int c) :from(a), to(b), dis(c) {};
	Edge() {};
};
vector<Edge> edges;
vector<vector<int>>G(maxn);
int N, K, M, D;
int d[maxn];
vector<pair<pair<int, int>, int> >ans;
int trans(string s) {
	if (s[0] == 'G')
		return stoi(s.substr(1))+N;
	return stoi(s);
}
void insertEdge(int from, int to, int dis) {
	G[from].push_back(edges.size());
	edges.push_back(Edge(from, to, dis));
	G[to].push_back(edges.size());
	edges.push_back(Edge(to, from, dis));
}
void Build() {
	//scanf("%d%d%d%d", &N, &K, &M, &D);
	cin >> N >> K >> M >> D;
	for (int i = 0; i < M; i++) {
		string s1, s2;
		int dis;
		cin >> s1 >> s2 >> dis;
		int u = trans(s1);
		int v = trans(s2);
		insertEdge(u, v, dis);
	}
}
bool SPFA(int s) {
	fill(d, d + maxn, inf);
	d[s] = 0;
	bool inq[maxn] = { false };
	queue<int> q;
	q.push(s);
	inq[s] = true;
	int num_inq[maxn] = { 0 };
	num_inq[s] = 1;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = false;
		for (int i = 0; i < G[u].size(); i++) {
			Edge& e = edges[G[u][i]];
			if (d[e.to] > d[u] + e.dis) {
				d[e.to] = d[u] + e.dis;
				if (!inq[e.to]&&e.to!=s) {
					q.push(e.to);
					inq[e.to] = true;
					if (++num_inq[e.to] >= N + K)
						return false;
				}
			}
		}
	}
	return true;
}
void Solve() {
	for (int i = 1; i <= K; i++) {
		SPFA(i + N);
		pair<pair<int, int>, int> now=make_pair(make_pair(inf,0),i);
		bool flag = true;
		for (int i = 1; i <= N; i++) {
			if (d[i] > D) {
				flag = false;
				break;
			}
			now.first.first = min(now.first.first, d[i]);
			now.first.second += d[i];
		}
		if (!flag)
			continue;
		ans.push_back(now);
	}
	if (ans.size() == 0)
		cout << "No Solution";
	else {
		sort(ans.begin(), ans.end(), [](const pair<pair<int, int>, int>& a, const pair<pair<int, int>, int>&b) {
			if (a.first.first != b.first.first)
				return a.first.first > b.first.first;
			else if (a.first.second != b.first.second)
				return a.first.second < b.first.second;
			else
				return a.second < b.second;
		});
		cout << 'G' << ans[0].second << endl;
	//	printf("G%d\n", ans[0].second);
	//	cout << setiosflags(ios::fixed);
		cout << fixed<<setprecision(1) << 1.0*ans[0].first.first << ' ' << setprecision(1) << 1.0*ans[0].first.second / N;
	}
}
int main() {
	std::ios::sync_with_stdio(false);	//??????8????
	Build();
	Solve();
	return 0;
}
/*
4 3 11 5
1 2 2
1 4 2
1 G1 4
1 G2 3
2 3 2
2 G2 1
3 4 2
3 G3 2
4 G1 3
G2 G1 1
G3 G2 2
*/
