#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<sstream>
#include<cmath>
#include<climits>
#include<numeric>
#include<iterator>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<bitset>
#define lowbit(x) x&(-x)
using namespace std;
const int maxn = 1e5 + 10;
vector<int> stk;
int C[maxn];
int Stoi(string s) {
	int k;
	stringstream A(s);
	string b; A >> b;
	A >> k;
	return k;
}
void Add(int idx, int v) {
	for (int i = idx; i <= maxn; i += lowbit(i)) {
		C[i] += v;
	}
}
int getSum(int idx) {
	int sum = 0;
	for (int i = idx; i > 0; i -= lowbit(i)) {
		sum += C[i];
	}
	return sum;
}
int GetKthElement(int K) {
	int l = 1, r = maxn, mid;
	while (l < r) {
		mid = (l + r) / 2;
		if (getSum(mid) >= K)
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}
void Solve(string s) {
	if ((s[1] == 'o' || s[1] == 'e') && stk.empty())
		puts("Invalid");
	else {
		if (s[1] == 'u') {
			int k = Stoi(s);
			stk.push_back(k);
			Add(k, 1);
		}
		else if (s[1] == 'o') {
			Add(stk.back(), -1);
			printf("%d\n", stk.back());
			stk.pop_back();
		}
		else if (s[1] == 'e') {
			int pos = GetKthElement(int((stk.size() + 1) / 2));
			printf("%d\n", pos);
		}
	}
}
int main() {
	string s;
	int n;
	scanf("%d%*c", &n);
	while (n--) {
		getline(cin, s);
		Solve(s);
	}
	return 0;
}
/*
17
Pop
PeekMedian
Push 3
PeekMedian
Push 2
PeekMedian
Push 1
PeekMedian
Pop
Pop
Push 5
Push 4
PeekMedian
Pop
Pop
Pop
Pop
*/