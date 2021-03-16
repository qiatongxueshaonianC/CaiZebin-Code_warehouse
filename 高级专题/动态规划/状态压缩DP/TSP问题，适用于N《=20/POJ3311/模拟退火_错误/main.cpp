#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<numeric>
#include<cmath>
#include<climits>
#include<vector>
#include<iomanip>
#include<ctime>
using namespace std;
const int maxn = 50;
const int inf = 1e9 + 7;
vector<vector<int> >G;
vector<int> p, cur;
int N, sum;
int get_sumdis(vector<int> A) {
	int res = 0;
	for (int i = 0; i < A.size() - 1; i++)
		res += G[A[i]][A[i + 1]];
	res += G[A[A.size() - 1]][A[0]];
	return res;
}
void init() {
	N++;
	G.resize(N);
	fill(G.begin(), G.end(), vector<int>(N));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			cin >> G[i][j];
	}
	p.resize(N);
	for (int i = 0; i < N; i++)
		p[i] = i;
}
void Floyed() {
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				G[i][j] = min(G[i][j],G[i][k] + G[k][j]);
			}
		}
	}
}
void Monte_carlo() {
	cur = p;
	for (int i = 0; i < 2000; i++) {
		for (int j = 0; j < N; j++) {
			int k = rand() % N;
			swap(cur[j], cur[k]);
			int temp = get_sumdis(cur);
			if (temp < sum) {
				sum = temp;
				p = cur;
			}
		}
	}
}
void Solve() {
	srand((unsigned)time(NULL));
	init();
	Floyed();
	sum = get_sumdis(p);
	Monte_carlo();
	double T = 10, T_min = 1e-2;
	int count = 30;
	while (T > T_min) {
		cur = p;
		vector<int> new_p;
		int new_sum =inf;
		for (int i = 0; i < count; i++) {
			int u = (rand()*rand()) % N;
			int v = (rand()*rand()) % N;
			while (u == v) {
				u = (rand()*rand()) % N;
				v = (rand()*rand()) % N;
			}
			swap(cur[u], cur[v]);
			int temp = get_sumdis(cur);
			if (temp < new_sum) {
				new_sum = temp;
				new_p = cur;
			}
			swap(cur[u], cur[v]);
		}
		int dE = sum - new_sum;
		int rd = (rand()*rand()) % 10001 / 10000.0;
		if (dE > 0 || exp(-1.0*dE / T) > rd) {
			p = new_p;
			sum = new_sum;
		}
		T *= 0.99;
	}
	cout << sum << endl;
}
int main() {
	std::ios::sync_with_stdio(false);
	while (cin >> N && N) {
		Solve();
	}
	return 0;
}
/*
3
0 1 10 10
1 0 1 2
10 1 0 10
10 2 10 0
0
*/
