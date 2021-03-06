#pragma warning(disable:4996)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1010;
const int inf = 0x3fffffff;
struct Node {
	int id,S, D;
	Node(int a, int b,int c) :id(a),S(b), D(c) {};
	Node() {};
};
vector<vector<Node>> G(maxn);
int N, M, K,indegree[maxn],idx[maxn],lowidx[maxn],dfs_num,num_cmp,components[maxn];
vector<set<int>> A(maxn);
vector<vector<int>> ans(maxn);
vector<int> temp;
int sumS[maxn], sumD[maxn];
bool flag = true,harsh[maxn][maxn];
stack<int> stk;
void Tarjan(int u) {
	idx[u] = lowidx[u] = ++dfs_num;
	stk.push(u);
	for (auto i : G[u]) {
		int& v = i.id;
		if (idx[v] == 0) {
			Tarjan(v);
			lowidx[u] = min(lowidx[u],lowidx[v]);
		}
		else if (components[v] == 0) {
			lowidx[u] = min(lowidx[u], idx[v]);
		}
	}
	if (lowidx[u] == idx[u]) {
		int t;
		++num_cmp;
		set<int>& st = A[num_cmp];
		do {
			t = stk.top(); stk.pop();
			components[t] = num_cmp;
			st.insert(t);
		} while (t != u);
		if (st.size() > 1)
			flag = false;
	}
}
void DFS(int u,int sums,int sumd) {
	temp.push_back(u);
	if (sums < sumS[u]||(sums == sumS[u] && sumd > sumD[u])) {
		sumS[u] = sums;
		sumD[u] = sumd;
		ans[u] = temp;
	}
	for (auto i : G[u]) {
		int& v = i.id;
		if(A[components[v]].size()==1)
			DFS(v, sums + i.S, sumd + i.D);
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
		if (u == v) {
			flag = false;
			harsh[u][v] = true;
			continue;
		}
		indegree[v]++;
	}
	int temp_indegree[maxn];
	memcpy(temp_indegree, indegree, sizeof(indegree));
	for (int i = 0; i < N; i++) {
		if (idx[i] == 0) {
			Tarjan(i);
		}
	}
	memcpy(indegree, temp_indegree, sizeof(temp_indegree));
	for (int i = 0; i < N; i++) {
		if (indegree[i] == 0) {
			DFS(i, 0, 0);
		}
	}
	if (!flag) {
		puts("Impossible.");
		scanf("%d", &K);
		while (K--) {
			int u; scanf("%d", &u);
			if (A[components[u]].size() > 1||harsh[u][u])
				puts("Error.");
			else
				printf("You may take test %d directly.\n", u);
		}
	}
	else {
		puts("Okay.");
		scanf("%d", &K);
		while (K--) {
			int u; scanf("%d", &u);
			if (ans[u].size() == 1) {
				printf("You may take test %d directly.\n", u);
			}
			else {
				printf("%d", ans[u][0]);
				for (int i = 1; i < ans[u].size(); i++) {
					printf("->%d", ans[u][i]);
				}
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