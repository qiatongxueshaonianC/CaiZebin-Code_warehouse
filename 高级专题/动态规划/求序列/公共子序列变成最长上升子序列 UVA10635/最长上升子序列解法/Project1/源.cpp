/*���԰����������������ת��Ϊ����������У�ǰ���������еĸ�������������ͬ������*/
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
#include<iterator>
#include<bitset>
#define lowbit(x) x&(-x)
using namespace std;
int N, p, q;
vector<int> A, B,dp,l;
map<int, int> mp;
int main() {
	std::ios::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int ii = 1; ii <= t; ii++) {
		mp.clear();
		cin >> N >> p >> q;
		A.resize(p + 1);
		B.resize(q + 1);
		for (int i = 0; i <= p; i++)
			cin >> A[i],mp[A[i]]=mp.size()+1;
		for (int i = 0; i <= q; i++) {
			cin >> B[i];
			if (mp.find(B[i]) != mp.end())
				B[i] = mp[B[i]];
			else
				B[i] = -1;
		}
		dp.resize(B.size()); l.resize(B.size());
		fill(dp.begin(), dp.end(), INT_MAX);
	//	int ans = 0;
		for (int i = 0; i < B.size(); i++) {
			l[i]= lower_bound(dp.begin(), dp.end(), B[i]) - dp.begin();		//ֻ��һ�ε�
		//	l[i] =upper_bound(dp.begin(), dp.end(), B[i]) - dp.begin();		//�����ظ���
			dp[l[i]] = B[i];
		//	ans = max(ans, l[i]);
		}
		printf("Case %d: %d\n", ii,*max_element(l.begin(),l.end()) + 1);
	}
	return 0;
}
/*
1
3 6 7
1 7 5 4 8 3 9
1 4 3 5 6 2 8 9

3
3 6 7
1 2 3 4 5 6 7
1 2 3 4 5 5 6 7
*/