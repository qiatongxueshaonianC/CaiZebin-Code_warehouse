#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<climits>
#include<numeric>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<bitset>
#define lowbit(x) x&(-x)
using namespace std;
const int maxn = 1010;
struct Edge {
	int from, to, flow, cap;
	Edge(int a, int b, int c, int d) :from(a), to(b), cap(c), flow(d) {};
};
vector<vector<int> > G(maxn);
vector<Edge> edges;
int cur[maxn],d[maxn];
void InsertEdge(int u, int v, int f) {
	G[u].push_back(edges.size());
	edges.push_back(Edge(u, v, f, 0));
	G[v].push_back(edges.size());
	edges.push_back(Edge(v, u, 0, 0));
}
bool SPFA(int st, int ed) {
	memset(d, 0, sizeof(d));
	bool vis[maxn] = { false };
	queue<int> q;
	q.push(st);
	vis[st] = true;
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < G[u].size(); i++) {
			Edge e = edges[G[u][i]];
			if (!vis[e.to] && e.cap > e.flow) {
				d[e.to] = d[e.from] + 1;
				vis[e.to] = true;
				q.push(e.to);
			}
		}
	}
	return vis[ed];
}
int Dinic(int st, int ed, int a) {
	if (st == ed || a == 0)
		return a;
	int Flow = 0, f;
	for (int& i = cur[st]; i < G[st].size(); i++) {
		Edge& e = edges[G[st][i]];
		if (d[e.to] == d[st] + 1 && (f = Dinic(e.to, ed, min(a, e.cap - e.flow))) > 0) {
			Flow += f;
			e.flow += f;
			edges[G[st][i] ^ 1].flow -= f;
			a -= f;
			if (a == 0)
				break;
		}
	}
	return Flow;
}
int MaxFlow(int st, int ed) {
	int Flow = 0;
	while (SPFA(st, ed)) {
		memset(cur, 0, sizeof(cur));
		Flow += Dinic(st, ed, INT_MAX);
	}
	return Flow;
}
int main() {
	int T;
	cin >> T;
	for (int ii = 1; ii <= T; ii++) {
		edges.clear();
		fill(G.begin(), G.end(), vector<int>());
		int n, m;
		scanf("%d%d", &n, &m);
	//	cin >> n >> m;    用cin输入，耗时421ms，用scanf耗时124ms
		for (int i = 0; i < m; i++) {
			int u, v, c;
			scanf("%d%d%d", &u, &v, &c);
		//	cin >> u >> v >> c;
			InsertEdge(u, v, c);
		}
		printf("Case %d: %d\n", ii, MaxFlow(1, n));
	}
	return 0;
}
/*
2
3 2
1 2 1
2 3 1
3 3
1 2 1
2 3 1
1 3 1
*/