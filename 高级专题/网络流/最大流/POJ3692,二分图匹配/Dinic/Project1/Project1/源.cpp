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
#include<bitset>
using namespace std;
const int maxn = 420;
const int inf = 0x3fffffff;
struct Edge {
	int from, to, cap, flow;
	Edge(int a,int b,int c,int d):from(a),to(b),cap(c),flow(d){}
};
vector<vector<int> >G(maxn);
vector<Edge> edges;
int GL, BY, M,k=1,N,d[maxn],cur[maxn];
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
			Edge& e = edges[G[u][i]];
			if (!vis[e.to] && e.cap > e.flow) {
				vis[e.to] = 1;
				d[e.to] = d[u] + 1;
				q.push(e.to);
			}
		}
	}
	return vis[ed];
}
int Dinic(int st, int ed, int a) {
	if (st == ed || a == 0) return a;
	int flow = 0, f;
	for (int i = cur[st]; i < G[st].size(); i++) {
		Edge& e = edges[G[st][i]];
		if (d[e.to] == d[st] + 1 && (f = Dinic(e.to, ed, min(a, e.cap - e.flow))) > 0) {
			flow += f;
			a -= f;
			e.flow += f;
			edges[G[st][i] ^ 1].flow -= f;
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
		flow += Dinic(st, ed, INT_MAX);
	}
	return flow;
}
int main() {
	while (~scanf("%d%d%d", &GL, &BY, &M) && (GL + BY + M)) {
		fill(G.begin(), G.end(), vector<int>());
		edges.clear();
		int harsh[maxn][maxn] = { false },u,v,N=GL+BY;
		for (int i = 0; i < M; i++) {
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
					InsertEdge(i, j, inf);	//2020/6/7/15:14���޸ģ���������Ϊ�����Ҳ����
			}
		}
		printf("Case %d: %d\n", k++, N-MaxFlow(0, N + 1));
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