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
#include<list>
#include<queue>
#include<stack>
#include<ctime>
#include<iomanip>
using namespace std;
typedef long long LL;
const int maxn = 310;
const LL inf = 0x3fffffffffffffff;
LL a[maxn], s[maxn],N;
struct Edge {
	int from, to, dis;
	Edge(int a, int b, LL c) :from(a), to(b), dis(c) {};
	Edge() {};
};
vector<Edge>edges;
vector<vector<int>>G(maxn);
LL d[maxn];
void InsertEdge(int u, int v, LL dis) {
	G[u].push_back(edges.size());
	edges.push_back(Edge(u, v, dis));
}
bool SPFA(int s) {
	int num_inq[maxn] = { 0 };
	num_inq[s]++;
	bool inq[maxn] = { false };//2020/8/28/23:33  记得初始化！！！！！！
	inq[s] = true;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		inq[u] = false;
		for (int i = 0; i < G[u].size(); i++) {
			Edge& e = edges[G[u][i]];
			if (d[u] + e.dis > d[e.to]) {
				d[e.to] = d[u] + e.dis;
				if (inq[e.to] == false) {
					inq[e.to] = true;
					q.push(e.to);
					if (++num_inq[e.to] >= N)
						return false;
				}
			}
		}
	}
	return true;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	InsertEdge(0, 2, 2 * a[1]);
	InsertEdge(2, 0, -(2 * a[1] + 1));
	InsertEdge(N - 2, N, 2 * a[N]);
	InsertEdge(N, N - 2, -(2 * a[N] + 1));
	for (int i = 2; i < N; i++) {
		InsertEdge(i - 2, i + 1, a[i] * 3);
		InsertEdge(i + 1, i - 2, -(a[i] * 3 + 2));
	}
	for (int i = 1; i <= N; i++) {
		InsertEdge(i - 1, i, 1);
	}
	SPFA(0);
	cout << d[1];
	for (int i = 2; i <= N; i++) {
		cout << " " << d[i]-d[i-1];
	}
	return 0;
}
/*
8
2 2 1 3 4 9 10 13
*/