#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<ctime>
#include<iomanip>
using namespace std;
const int maxn = 110;
struct Node {
	int level;
	vector<int> child;
};
vector<Node> A;
int N,M;
void BFS(int s) {
	int ans[maxn] = { 0 },max_level=1;
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (A[u].child.size() == 0)
			ans[A[u].level]++;
		for (auto i : A[u].child) {
			A[i].level = A[u].level + 1;
			max_level = max(max_level, A[i].level);
		/*	if (A[i].child.size() == 0) {	//要放到外面，不然的话，对根节点要做特殊判断
				ans[A[i].level]++;
			}*/
			q.push(i);
		}
	}
	for (int i = 1; i <= max_level;i++) {
		cout << ans[i] << (i == max_level ? "\n" : " ");
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	while (cin >> N && N) {
		A.resize(N + 1);
		cin >> M;
		for (int i = 0; i < M; i++) {
			int id, k,u;
			cin >> id >> k;
			while (k--) {
				cin >> u;
				A[id].child.push_back(u);
			}
		}
		A[1].level = 1;
		BFS(1);
	}
	return 0;
}
/*
2 1
01 1 02
*/