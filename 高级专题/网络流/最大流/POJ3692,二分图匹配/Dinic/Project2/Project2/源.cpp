#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<climits>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#define lowbit(x) x&(-x)
using namespace std;
const int maxn = 1010;
struct Edge {
	int from, to, cap, flow;
	Edge(int a, int b, int c, int d) :from(a), to(b), cap(c), flow(d) {};
};
vector<vector<int> >G(maxn);
vector<Edge> edges;
int GL, BY, M,cur[maxn],d[maxn];
void InsertEdge(int u, int v, int F) {
	G[u].push_back(edges.size());
	edges.push_back(Edge(u, v, F, 0));
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
			if (!vis[e.to] && e.cap - e.flow > 0) {
				d[e.to] = d[e.from] + 1;
				vis[e.to] = true;
				q.push(e.to);
			}
		}
	}
	return vis[ed];
}
int Dinic(int u, int ed, int a) {
	if (u == ed || a == 0)
		return a;
	int Flow = 0, f;
	for (int& i = cur[u]; i < G[u].size(); i++) {
		Edge& e = edges[G[u][i]];
		if (d[e.to] == d[u] + 1 && (f = Dinic(e.to, ed, min(a, e.cap - e.flow))) > 0) {
			Flow += f;
			e.flow += f;
			edges[G[u][i] ^ 1].flow -= f;  //反向边的流量变成负数  2020/4/7/21：23发现
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
	int k = 1;
	while (scanf("%d%d%d", &GL, &BY, &M) && (GL + BY + M)) {
		edges.clear();
		fill(G.begin(), G.end(), vector<int>());
		int N = GL + BY;
		bool harsh[maxn][maxn] = { false };
		for (int i = 0; i < M; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			v += GL;
			harsh[u][v] = true;
		}
		for (int i = 1; i <= GL; i++)
			InsertEdge(0, i, 1);
		for (int i = GL + 1; i <= N; i++)
			InsertEdge(i, N + 1, 1);
		for (int i = 1; i <= GL; i++) {
			for (int j = GL + 1; j <= N; j++) {
				if (harsh[i][j] == false)
					InsertEdge(i, j, 1);
			}
		}
		printf("Case %d: %d\n", k++, N - MaxFlow(0, N + 1));
	}
	return 0;
}
/*
2 3 3
1 1
1 2
2 3
2 3 5
1 1
1 2
2 1
2 2
2 3
0 0 0
*/