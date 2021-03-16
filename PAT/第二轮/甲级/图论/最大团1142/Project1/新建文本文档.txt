#pragma warning(disable:4996)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 210;
int N, M, G[maxn][maxn];
bitset<210> Hash;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		G[u][v] = G[v][u] = 1;
	}
	int K;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int m;
		cin >> m;
		vector<int> A(m);
		Hash.reset();
		for (int i = 0; i < m; i++)
			cin >> A[i], Hash[A[i]] = 1;
		bool isClique = true, isMax = true;
		for (int i = 0; i < m; i++) {
			if (isClique == false)
				break;
			for (int j = i + 1; j < m; j++) {
				if (G[A[i]][A[j]] == 0) {
					isClique = false;
					cout << "Not a Clique" << endl;
					break;
				}
			}
		}
		if (isClique == false)
			continue;
		for (int i = 1; i <= N; i++) {
			if (isMax == false)
				break;
			if (Hash[i] == 0) {
				for (int j = 0; j < m; j++) {
					if (G[i][A[j]] == 0) 
						break;
					if (j == m - 1) {
						isMax = false;
						cout << "Not Maximal" << endl;
					}
				}
			}
		}
		if (isMax)
			cout << "Yes" << endl;
	}
	return 0;
}
/*
8 10
5 6
7 8
6 4
3 6
4 5
2 3
8 2
2 7
5 3
3 4
6
4 5 4 3 6
3 2 8 7
2 2 3
1 1
3 4 3 6
3 3 2 1
*/