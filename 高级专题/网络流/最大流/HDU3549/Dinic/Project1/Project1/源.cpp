#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<bitset>
using namespace std;
const int maxn = 2020;
struct Edge {
	int from, to, cap, flow;
	Edge(int a, int b, int c, int d) :from(a), to(b), cap(c), flow(d) {}
};
vector<vector<int> >G(maxn);
vector<Edge> edges;
int cur[maxn],d[maxn];
void InsertEdge(int u, int v, int cap) {
	G[u].push_back(edges.size());
	edges.push_back(Edge(u, v, cap, 0));
	G[v].push_back(edges.size());
	edges.push_back(Edge(v, u, 0, 0));
}
bool SPFA(int st, int ed) {
	int vis[maxn] = { 0 };
	memset(d, 0, sizeof(d));
	vis[st] = 1;
	d[st] = 0;
	queue<int> q;
	q.push(st);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < G[u].size(); i++) {
			Edge e = edges[G[u][i]];
			if (!vis[e.to] && e.cap > e.flow) {
				vis[e.to] = 1;
				d[e.to] = d[u] + 1;
				q.push(e.to);
			}
		}
	}
	return vis[ed];
}
int Dinic(int u,int ed,int a) {
	if (u == ed || a == 0) return a;
	int flow = 0, f;
	for (int& i = cur[u]; i < G[u].size(); i++) {
		Edge& e = edges[G[u][i]];
		if (d[u] + 1 == d[e.to] && (f = Dinic(e.to, ed, min(a, e.cap - e.flow))) > 0) {
			e.flow+=f;
			edges[G[u][i]^1].flow-=f;
			flow+=f;
			a-=f;
			if (a == 0)
				break;
		}
	}
	return flow;
}
int MaxFlow(int st, int ed) {
	int flow = 0;
	while (SPFA(st, ed)) {
		memset(cur, 0, sizeof(cur));
		flow += Dinic(st,ed, INT_MAX);
	}
	return flow;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		fill(G.begin(), G.end(), vector<int>());
		edges.clear();
		int n, m, u, v, c;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v, &c);
			InsertEdge(u, v, c);
		}
		printf("Case %d: %d\n", ii, MaxFlow(1, n));
	}
	return 0;
}/*
2
3 2
1 2 1
2 3 1
3 3
1 2 1
2 3 1
1 3 1
*/