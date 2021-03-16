#pragma warning(disable:4996)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int inf = 0x3fffffff;
struct Node {
	int id, S, D;
	Node(int a, int b, int c) :id(a), S(b), D(c) {};
};
vector<vector<Node>> G(maxn);
int N, M, K,indegree[maxn],sumS[maxn],sumD[maxn];
vector<vector<int>> Path(maxn);
vector<int> temp;
bool harsh[maxn];
int TopoSort(int indegree[]) {
	int num = 0;
	queue<int> q;
	for (int i = 0; i < N; i++) {
		if (indegree[i] == 0)
			q.push(i), num++,harsh[i]=true;
	}
	while (!q.empty()) {
		int u = q.front(); q.pop();
		for (auto i : G[u]) {
			int& v = i.id;
			if (--indegree[v] == 0) {
				q.push(v);
				num++;
				harsh[v] = 1;
			}
		}
	}
	return num== N ? 1 : 0;
}
void DFS(int u,int sums,int sumd) {
	temp.push_back(u);
	if (sums < sumS[u] || (sums == sumS[u] && sumd > sumD[u])) {
		Path[u] = temp;
		sumS[u] = sums;
		sumD[u] = sumd;
	}
	for (auto i : G[u]) {
		int& v = i.id;
		if (harsh[v]) {
			DFS(v, sums + i.S, sumd + i.D);
		}
	}
	temp.pop_back();
}
int main() {
	fill(sumS, sumS + maxn, inf);
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		int u, v, s, d;
		scanf("%d%d%d%d", &u, &v, &s, &d);
		G[u].push_back(Node(v, s, d));
		indegree[v]++;
	}
	int tp[maxn];
	memcpy(tp, indegree, sizeof(indegree));
	bool flag = TopoSort(tp);
	for (int i = 0; i < N; i++) {
		if (indegree[i] == 0)
			DFS(i,0,0);
	}
	printf("%s\n", flag ? "Okay" : "Impossible");
	int k; scanf("%d", &k);
	while (k--) {
		int u;
		scanf("%d", &u);
		if (harsh[u] == false)
			puts("error.");
		else {
			if(Path[u].size()==1)
				printf("You may take test %d directly.\n", u);
			else {
				printf("%d", Path[u][0]);
				for (int i = 1; i < Path[u].size(); i++)
					printf("->%d", Path[u][i]);
				puts("");
			}
		}
	}
	return 0;
}
/*
8 15
0 1 50 50
1 2 20 20
3 4 90 90
3 7 90 80
4 5 20 20
7 5 10 10
5 6 10 10
0 4 80 60
3 1 50 45
1 4 30 20
1 5 50 20
2 4 10 10
7 2 10 30
2 5 30 20
2 6 40 60
8
0 1 2 3 4 5 6 7

4 5
0 1 1 10
1 2 2 10
3 0 4 10
3 2 5 10
2 0 3 10
2
3 1

4 4
0 1 1 10
1 2 2 10
3 0 4 10
3 2 5 10
2
3 1
*/