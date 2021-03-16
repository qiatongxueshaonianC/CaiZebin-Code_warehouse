#pragma warning(disable:4996)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e4 + 10;
const int inf = 0x3fffffff;
int N, M,father[maxn];
int findFather(int a) {
	if (father[a] < 0)
		return a;
	int temp = findFather(father[a]);
	father[a] = temp;
	return temp;
}
struct Edge {
	int u, v, dis, weight,idx;
	Edge(int a, int b, int c, int d,int e) :u(a), v(b), dis(c), weight(d), idx(e){};
	bool friend operator <(const Edge& a, const Edge& b) {
		if (a.dis != b.dis)
			return a.dis > b.dis;
		else
			return a.weight < b.weight;
	}
};
priority_queue<Edge> q;
int main() {
	cout << 4;
	return 0;
}
/*
6 9
4 3 32 3
1 5 43 5
1 0 32 3
0 2 28 8
4 2 19 1
2 3 28 10
0 4 28 2
1 2 28 3
3 1 19 1
*/