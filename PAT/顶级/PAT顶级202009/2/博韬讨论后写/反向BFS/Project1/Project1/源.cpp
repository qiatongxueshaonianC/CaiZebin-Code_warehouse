#pragma warning(disable:4996)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
const int inf = 0x3fffffff;
const int Base = 3 * 1e5 + 10;
int A, B, N, d[maxn];
map<int, string> path;
int getHash(int i) {
	if (i < 0)
		return Base + i;
	return i;
}
bool judge(int u, int k) {
	if (d[getHash(u)] + 1 < d[getHash(u + k)]) {
		d[getHash(u + k)] = d[getHash(u)] + 1;
		return true;
	}
	return false;
}
void BFS(int s) {
	queue<int> q;
	q.push(s);
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u == A) {
			printf("%d\n", d[getHash(u)]);
				puts(path[u].c_str());
			return;
		}
		if (judge(u, 1)) {
				path[u+1] =path[u]+ "+1";
			q.push(u + 1);
		}
		if (judge(u, -1)) {
				path[u - 1] = path[u] + "-1";
			q.push(u - 1);
		}
		if (u%N == 0 && (abs(A - u / N) < abs(A - u))) {
			if (d[getHash(u)] + 1 < d[getHash(u / N)])
				d[getHash(u / N)] = d[getHash(u)] + 1;
				path[u / N] = '('+path[u]+')' + "/" + to_string(N);
			q.push(u / N);
		}
		if (abs(u - A) > abs(N*u - A)) { 	//逆运算，只支持+ - /
			if (d[getHash(u)] + 1 < d[getHash(u*N)])
				d[getHash(u*N)] = d[getHash(u)] + 1;
				path[u * N] = '(' + path[u] + ')' + "*" + to_string(N);
			q.push(N*u);
		}
	}
}
int main() {
	clock_t start, end;
	int k;
	scanf("%d", &k);
	start = clock();
	while (k--) {
		fill(d, d + maxn, inf);
		scanf("%d%d%d", &A, &B, &N);
		d[getHash(B)] = 0;
		path[B] = to_string(B);
		BFS(B);
	}
	end = clock();
	printf("%lf/(s)", 1.0*(end - start) / CLOCKS_PER_SEC);
	return 0;
}
/*
5
-10 10 7
-1000 1000 7




11
3 11 2
-5 -12 3
-2 1000 7
-100000 100000 7
12345 67894 4
12458 67895 3
6513 9845 2
100000 -100000 7
78956 8974 8
2131 645 3
7539 951 7

11
3 11 2
-5 -12 3
-2 1000 7
-100000 100000 7
12345 67894 4
12458 67895 3
6513 9845 2
65413 798 7
78956 8974 8
2131 645 3
7539 951 7



11
3 11 2
3
-5 -12 3
2
-2 1000 7
13
-100000 100000 7
100016
12345 67894 4
32
12458 67895 3
33
6513 9845 2
35
100000 -100000 7
100016
78956 8974 8
63027
2131 645 3
1182
7539 951 7
5896
33.741000/(s)


11
3 11 2
3
-5 -12 3
-2 1000 7
13
-100000 100000 7
36
12345 67894 4
1164
12458 67895 3
3396
6513 9845 2
1592
100000 -100000 7
78956 8974 8
7109
2131 645 3
191
7539 951 7
841
4.782000/(s)
*/