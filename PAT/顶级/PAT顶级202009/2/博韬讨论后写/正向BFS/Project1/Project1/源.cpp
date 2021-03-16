#pragma warning(disable:4996)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6;
const int inf = 0x3fffffff;
const int Base = 3*1e5+ 10;
int A,B,N,d[maxn];
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
		if (u == B) {
			printf("%d\n", d[getHash(u)]);
		//	puts(path[u].c_str());
			return;
		}
		if(judge(u,1)){
		//	path[u+1] =path[u]+ "+1";
			q.push(u + 1);
		}
		if(judge(u,-1)){
		//	path[u - 1] = path[u] + "-1";
			q.push(u - 1);
		}
		if (abs(u-B)>abs(N*u-B)) {	//逆运算，只支持+ - /
			if (d[getHash(u)] + 1 < d[getHash(u*N)]) 
				d[getHash(u*N)] = d[getHash(u)] + 1;
		//	path[u * N] = '(' + path[u] + ')' + "*" + to_string(N);
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
		d[getHash(A)] = 0;
		if (1ll * A*(1ll * B) < 0) {
			d[0] = abs(A);
			A = 0;
			d[B > 0 ? getHash(-1) : 1] = abs(A) - 1;		//防止走回头路
		}
		path[A] = to_string(B);
		BFS(A);
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
4
-2 1000 7
23
-100000 100000 7
100033
12345 67894 4
4631
12458 67895 3
10176
6513 9845 2
3182
100000 -100000 7
100033
78956 8974 8
69982
2131 645 3
1486
7539 951 7
6588
0.857000/(s)
*/