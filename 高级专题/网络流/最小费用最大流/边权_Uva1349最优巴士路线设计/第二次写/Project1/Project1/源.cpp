#pragma warning(disable:4996)
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 210;
const int inf = 0x3fffffff;
struct Edge {
	int from, to, flow, dis;
	Edge(int a, int b, int c, int d) :from(a), to(b), flow(c), dis(d) {};
};
int N, s, t;
vector<Edge> edges;
vector<vector<int>> G(maxn);
void InsertEdge(int u, int v, int flow, int dis) {
	G[u].push_back(edges.size());
	edges.push_back(Edge(u, v, flow, dis));
	G[v].push_back(edges.size());
	edges.push_back(Edge(v, u, 0, -dis));
}
bool SPFA(LL& Flow, LL& cost) {
	int MinF = inf, pre[maxn], d[maxn];
	fill(d, d + maxn, inf);
	d[s] = 0;
	queue<int> q;
	q.push(s);
	bool inq[maxn] = { false };
	inq[s] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = false;
		for (int i = 0; i < G[u].size(); i++) {
			int& idx = G[u][i];
			Edge& e = edges[idx];
			if (e.flow > 0 && d[e.to] > d[e.from] + e.dis) {
				d[e.to] = d[e.from] + e.dis;
				MinF = min(MinF, e.flow);
				pre[e.to] = idx;
				if (!inq[e.to]) {
					inq[e.to] = true;
					q.push(e.to);
				}
			}
		}
	}
	if (d[t] == inf)
		return false;
	Flow += MinF;
	cost += MinF * 1ll * d[t];
	for (int i = t; i != s; i = edges[pre[i]].from) {
		edges[pre[i]].flow -= MinF;
		edges[pre[i] ^ 1].flow += MinF;
	}
	return true;
}
pair<LL, LL> Maxflow_Mincost() {
	LL Flow = 0, cost = 0;
	while (SPFA(Flow, cost)) {};
	return make_pair(cost, Flow);
}
void clear() {
	edges.clear();
	fill(G.begin(), G.end(), vector<int>());
}
void Solve() {
	clear();
	s = 0;
	t = 2 * N + 1;
	for (int i = 1; i <= N; i++) {			//拆开的点之间并没有连接，i可以连到v,即i->v+N，v也可到i:v->i+N 
		int v, dis;
		InsertEdge(s, i, 1, 0);
		InsertEdge(i + N, t, 1, 0);
		while (cin >> v && v) {
			cin >> dis;
			InsertEdge(i, v + N, 1, dis);	//针对边权，走过这条边
		}
	}
	auto ans = Maxflow_Mincost();
	if (ans.second != N)
		cout << "N" << endl;
	else
		cout << ans.first << endl;
}
int main() {
	std::ios::sync_with_stdio(false);
	while (cin >> N && N) {
		Solve();
	}
	return 0;
}
/*
3
2 2 3 1 0
1 1 3 2 0
1 3 2 7 0
8
2 3 3 1 0
3 3 1 1 4 4 0
1 2 2 7 0
5 4 6 7 0
4 4 3 9 0
7 4 8 5 0
6 2 5 8 8 1 0
6 6 7 2 0
3
2 1 0
3 1 0
2 1 0
0
*/
