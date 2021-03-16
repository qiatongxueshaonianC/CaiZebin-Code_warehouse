#pragma warning(disable:4996)
#include<bits/stdc++.h>
using namespace std;
int A, B, N,K,best=INT_MAX;
bool flag = false;
clock_t start, end;
void DFS(int num,int step) {
	if (flag)
		return;
	if (num == B) {
		best = min(best, step);
		return;
	}
	if (step >= best)
		return;
	DFS(num + 1, step + 1);
	DFS(num*N, step + 1);
	DFS(num - 1, step + 1);
		
}
int main() {
	start = clock();
	cin >> K;
	while (K--) {
		flag = false;
		scanf("%d%d%d", &A, &B, &N);
		DFS(A,0);
		printf("%d\n", best);
	}
	return 0;
}
/*
3
3 11 2
-5 -12 3
-2 1000 7

*/