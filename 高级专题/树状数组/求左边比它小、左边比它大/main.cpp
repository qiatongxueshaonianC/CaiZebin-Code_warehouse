#include<sstream>
#include<iostream>
#include<vector>
#define lowbit(x) x&(-x)
using namespace std;
const int maxn = 1e6 + 10;
int C[maxn], harsh[maxn];
void Add(int idx, int v) {
	for (int i = idx; i <= maxn; i += lowbit(i)) {
		C[i] += v;
	}
}
int getSum(int idx) {
	int sum = 0;
	for (int i = idx; i > 0; i -= lowbit(i))
		sum += C[i];
	return sum;
}
int main() {
	int n, x;
	cin >> n;
	vector<int> l(n + 1), r(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> x;
		Add(x, 1);
		l[i] = getSum(x - 1);
		r[i] = i-1 - l[i];
		printf("%d  %d--%d\n", l[i], r[i], getSum(n) - getSum(x));
	}
	return 0;
}
/*
5
2 5 1 3 4

*/
