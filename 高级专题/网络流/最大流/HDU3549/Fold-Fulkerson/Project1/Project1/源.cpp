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
#include<list>
#include<queue>
using namespace std;
const int maxn = 2020;
struct Edge {
	int from, to, cap, flow;
	Edge(int a, int b, int c, int d) :from(a), to(b), cap(c), flow(d) {};
};
vector<vector<int> >G(maxn);
vector<Edge> edges;
void InsertEdge(int u, int v, int cap) {
	G[u].push_back(edges.size());
	edges.push_back(Edge(u, v, cap, 0));
	G[v].push_back(edges.size());
	edges.push_back(Edge(v, u, 0, 0));
}
bool SPFA(int st, int ed, int& Flow) {
	int a[maxn] = { 0 }, p[maxn] = { 0 };
	a[st] = INT_MAX;
	queue<int> q;
	q.push(st);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (int i = 0; i < G[u].size(); i++) {
			Edge e = edges[G[u][i]];
			if (!a[e.to] && e.cap > e.flow) {
				a[e.to] = min(a[u], e.cap - e.flow);
				p[e.to] = G[u][i];
				q.push(e.to);
			}
		}
		if (a[ed] != 0)
			break;
	}
	if (a[ed] == 0)
		return false;
	for (int u = ed; u != st; u = edges[p[u]].from) {
		edges[p[u]].flow += a[ed];
		edges[p[u] ^ 1].flow -= a[ed]; //2020/3/12/14:00发现，反向边的流量变成负数，是-=
	}
	Flow += a[ed];
	return true;
}
int Max_Flow(int st, int ed) {
	int flow = 0;
	while (SPFA(st, ed, flow));
	return flow;
}
int main() {
	int T;
	scanf("%d", &T);
	for (int ii = 1; ii <= T; ii++) {
		fill(G.begin(), G.end(), vector<int>());
		edges.clear();
		int n, m,u,v,c;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d", &u, &v,&c);
			InsertEdge(u, v, c);
		}
		printf("Case %d: %d\n",ii, Max_Flow(1, n));
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