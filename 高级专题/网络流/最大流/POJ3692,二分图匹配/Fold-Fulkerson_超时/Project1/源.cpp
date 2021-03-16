//#pragma warning(disable:4996)
#define _CRT_SECURE_NO_WARNINGS
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
#include<bitset>
using namespace std;
const int maxn = 405;
struct Edge {
	int from, to, cap, flow;
	Edge(int a, int b, int c, int d) :from(a), to(b), cap(c), flow(d) {};
};
vector<vector<int> >G(maxn);
vector<Edge> edges;
int GL, B, M,k=1;
bool harsh[maxn][maxn];
void InsertEdge(int from, int to, int cap) {
	G[from].push_back(edges.size());
	edges.push_back(Edge(from, to, cap, 0));
	G[to].push_back(edges.size());
	edges.push_back(Edge(to, from, 0, 0));
}
bool SPFA(int st, int ed, int& flow) {
	int a[maxn] = { 0 }, p[maxn] = { 0 };
	a[st] = INT_MAX;
	queue<int> q;
	q.push(st);
	while (q.size()) {
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
	for (int u = p[ed]; u != st; u = edges[p[u]].from) {
		edges[p[u]].flow += a[ed];
		edges[p[u] ^ 1].flow += a[ed];
	}
	flow += a[ed];
	return true;
}
int Max_Flow(int st, int ed) {
	int flow = 0;
	while (SPFA(st, ed, flow));
	return flow;
}
int main() {
	while (~scanf("%d%d%d", &GL, &B, &M) && (GL+B+M)!=0) {
		fill(G.begin(),G.end(),vector<int>()); 
		edges.clear();
		memset(harsh, 0, sizeof(harsh));
		int u, v,n=GL+B;
		for (int i = 0; i < M; i++) {
			scanf("%d%d", &u, &v);
			v = GL + v;
			harsh[u][v] = harsh[v][u] = 1;
		}
		for (int i = 1; i <= GL; i++)
			InsertEdge(0, i, 1);
		for (int i = GL + 1; i <= n; i++)
			InsertEdge(i, n + 1, 1);
		for (int i = 1; i <= GL; i++) {
			for (int j = 1+ GL; j <= n; j++) {
				if (harsh[i][j] == false) {
					InsertEdge(i, j, 1);
				}
			}
		}
		printf("Case %d: %d\n", k++, n - Max_Flow(0, n + 1));
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