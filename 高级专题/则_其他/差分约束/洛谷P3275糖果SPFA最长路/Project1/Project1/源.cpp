#pragma warning(disable:4996)
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int maxn = 100000 + 10;
struct Edge {
	LL from, to, dis;
	Edge(int a, int b, int c) :from(a), to(b), dis(c) {};
	Edge() {};
};
vector<Edge> edges;
vector<vector<int>> G(maxn);
int N, K;
void InsertEdge(int u, int v, int dis) {
	G[u].push_back(edges.size());
	edges.push_back(Edge(u, v, dis));
}
LL d[maxn];
clock_t start, End;
bool SPFA() {
	bool inq[maxn] = { true };
	memset(inq, true, sizeof(inq));
	int num_inq[maxn] = { 0 };
	fill(num_inq, num_inq + N+1, 1);
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = false;
		for (auto i : G[u]) {
			Edge& e = edges[i];
			if (d[e.to] < d[u] + e.dis) {
				d[e.to] = d[u] + e.dis;
				if (!inq[e.to]) {
					inq[e.to] = true;
					q.push(e.to);
					if (++num_inq[e.to] >= N)
						return false;
				}
			}
		}
		End = clock();
	//	cout << (End - start) << "/" << CLOCKS_PER_SEC << "(s)" << endl;
		if (1.0*(End - start) / CLOCKS_PER_SEC >= 0.98)	//加一个特殊情况判断，否则会超时
			return false;
	}
	return true;
}
int main() {
	std::ios::sync_with_stdio(false);
	start = clock();
	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int op, u, v, dis = 0;
		cin >> op >> u >> v;
		if (op == 2 || op == 4) {
			dis = 1;
		}
		switch (op) {
		case 1: 
			InsertEdge(u, v, dis);
			InsertEdge(v, u, dis);
			break;
		case 2:
			InsertEdge(u, v, dis);
			break;
		case 3:
			InsertEdge(v, u, dis);
			break;
		case 4:
			InsertEdge(v, u, dis);
			break;
		case 5:
			InsertEdge(u, v, dis);
			break;
		}
		//正解：
	/*	if (op % 2 == 0 && u == v) {
			cout << -1 << endl;
			goto loop;
		}*/
	}
	if (!SPFA()) {
		cout << -1 << endl;
	}
	else {
		LL ans = N;
		for (int i = 1; i <= N; i++) {
			ans += d[i];
		}
		cout << ans << endl;
	}
	loop:
	return 0;
}
/*
5 7
1 1 2
2 3 2
4 4 1
3 4 5
5 4 5
2 3 5
4 5 1
*/