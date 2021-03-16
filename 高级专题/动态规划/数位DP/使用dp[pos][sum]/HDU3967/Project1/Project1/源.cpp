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
#include<list>
#include<queue>
#include<bitset>
using namespace std;
typedef long long LL;
LL M, N, K;  //�Ժ��������ֵģ�ֱ��ȫ���滻��LL
LL d[20];
LL dp[20][20][20][20];  //2020/4/20/02:21���ڵ������ˣ�sumL,sumR,dp����ȫ��ҪLL̫�����ˣ����˺ü���Сʱ
LL DFS(LL pos, LL cut, LL sumL, LL sumR, bool ALL0, bool isLimit) {
	if (pos == -1) {
		return (sumL + sumR) % K == 0 ? 1 : 0;
	}
	if (!ALL0 && !isLimit&&dp[pos][cut][sumL%K][sumR%K] != -1) //��%K�Ļ����ڴ�ᳬ��
		return dp[pos][cut][sumL%K][sumR%K];
	LL up = isLimit ? d[pos] : 9;
	LL ans = 0;
	for (LL i = 0; i <= up; i++) {
		if (pos < cut) {  //�����Ұ�ߵĺ� 
			ans += DFS(pos - 1, cut, sumL, sumR * 10 + i, ALL0 && (i == 0), isLimit&&i == d[pos]);
		}
		else {    //�������ߵĺ� 
			if (ALL0&&pos == cut && i == 0)
				continue;
			ans += DFS(pos - 1, cut, sumL * 10 + i, sumR, ALL0 && (i == 0), isLimit&&i == d[pos]);
		}
	}
	if (!ALL0 && !isLimit)
		dp[pos][cut][sumL%K][sumR%K] = ans;
	return ans;
}
LL Solve(LL k) {
	memset(dp, -1, sizeof(dp));
	memset(d, 0, sizeof(d));
	LL len = 0;
	do {
		d[len++] = k % 10;
		k /= 10;
	} while (k != 0);
	LL ans = 0;
	for (LL i = 1; i <= len - 1; i++)
		ans += DFS(len - 1, i, 0, 0, true, true);
	return ans;
}
int main() {
	while (~scanf("%lld%lld%lld", &M, &N, &K)) {
		printf("%lld\n", Solve(N) - Solve(M - 1));
	}
	return 0;
}
/*
333 333 3
10 100 2
31 123456789 4
219135798
*/