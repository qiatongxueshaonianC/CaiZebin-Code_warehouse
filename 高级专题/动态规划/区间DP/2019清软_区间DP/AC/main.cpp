#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<bitset>
#define lowbit(x) x&(-x);
using namespace std;
const int maxn = 1010;
string s;
int dp[maxn][maxn];
string mark[maxn][maxn];
bool vis[maxn][maxn];
bool repets(int l, int r, int L, int R) {
	if ((R - L + 1) % (r - l + 1) != 0)	return false;
	for (int i = l, j = L; j <= R; i++, j++) {
		if (i > r)	i = l;
		if (s[i] != s[j])
			return false;
	}
	return true;
}
pair<int, string> DP(int i, int j) {
	if (j == i)
		dp[i][j] = 1, mark[i][j] = s[i],vis[i][j]=true;
	if(vis[i][j])
		return {dp[i][j],mark[i][j]};
	int res = j - i + 1;
	for (int k = i; k < j; k++) {
		auto temp1 = DP(i, k);
		auto temp2 = DP(k + 1, j);
		if (res >= temp1.first + temp2.first) {
			res = temp1.first + temp2.first;
			mark[i][j] = temp1.second + temp2.second;
		}
		if (repets(i, k, k + 1, j)) {
			int temp = dp[i][k] + 2 + (int)to_string((j - i + 1) / (k - i + 1)).size();
			if (res > temp) {
				res = temp;
				mark[i][j] = to_string((j - i + 1) / (k - i + 1)) + '(' + mark[i][k] + ')';
			}
		}
	}
	vis[i][j]=true;
	dp[i][j] = res;
	return { res,mark[i][j] };
}
int main() {
	std::ios::sync_with_stdio(false);
	while (cin >> s) {
		memset(vis,false,sizeof(vis));
		auto ans = DP(0, s.size() - 1);
		cout << ans.first << '~' << ans.second << endl;
	}
	return 0;
}
/*
AAAAAAAAAABABABACCD
10(A)3(BA)CCD
HELLOHELLOWORLDHELLOHELLOWORLD
2(2(HELLO)WORLD)
*/
