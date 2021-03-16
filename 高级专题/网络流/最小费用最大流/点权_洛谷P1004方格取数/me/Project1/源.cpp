#pragma warning(disable:4996)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 11*11*2;
const int inf = 0x3fffffff;
struct Edge {
	int u, v, flow, dis;
	Edge(int a, int b, int c, int d) :u(a), v(b), flow(c), dis(d) {};
};
int N, s, t, g[maxn][maxn];
vector<Edge> edges;
vector<vector<int>> G(maxn);
int hashin(int x, int y) {
	return x * N + y;
}
int hashout(int x, int y) {
	return N * N + N * x + y;
}
void InsertEdge(int u, int v, int flow, int dis) {
	G[u].push_back(edges.size());
	edges.push_back(Edge(u, v, flow, dis));
	G[v].push_back(edges.size());
	edges.push_back(Edge(v, u, 0, -dis));
}
bool SPFA(int& Flow, int& cost) {
	int Minflow = inf, pre[maxn], d[maxn];
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
			Edge& e = edges[G[u][i]];
			if (e.flow > 0 && d[e.v] > d[e.u] + e.dis) {
				d[e.v] = d[e.u] + e.dis;
				Minflow = min(Minflow, e.flow);
				pre[e.v] = G[u][i];
				if (!inq[e.v]) {
					q.push(e.v);
					inq[e.v] = true;
				}
			}
		}
	}
	if (d[t] == inf)
		return false;
	for (int i = t; i != s; i = edges[pre[i]].u) {
		edges[pre[i]].flow -= Minflow;
		edges[pre[i] ^ 1].flow += Minflow;
	}
	Flow += Minflow;
	cost += Minflow * d[t];
	return true;
}
pair<int, int> Maxflow_Mincost() {
	int flow = 0, cost = 0, Minf = inf;
	while (SPFA(flow,cost)) {}
	return make_pair(flow, cost);
}
int main() {
	scanf("%d", &N);
	int x, y, v;
	s = 0;
	t = hashout(N, N) + 1;				//刚开始图建错了！！！！！！
	InsertEdge(s, hashin(1, 1), 2, 0);
	InsertEdge(hashout(N, N), t, 2, 0);
	while (~scanf("%d%d%d", &x, &y, &v) && x&&y&&v) {
		g[x][y] = v;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int from = hashin(i, j);
			int to = hashout(i, j);
			InsertEdge(from, to, 1, -g[i][j]);
			InsertEdge(from, to, 1, 0);
			if (i != N)
				InsertEdge(hashout(i, j), hashin(i + 1, j), 2, 0);
			if (j != N)
				InsertEdge(hashout(i, j), hashin(i, j + 1), 2, 0);
		}
	}
	auto ans = Maxflow_Mincost();
	printf("%d\n", -ans.second);
	return 0;
}
/*
8
2 3 13
2 6  6
3 5  7
4 4 14
5 2 21
5 6  4
6 3 15
7 2 14
0 0  0

3
1 1 10
1 3 5
2 2 6
2 3 4
3 1 8
3 2 2
0 0 0

*/