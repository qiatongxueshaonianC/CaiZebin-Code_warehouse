#pragma warning(disable:4996)
#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<list> 
#define lowbit(x) x&(-x)
using namespace std;
#pragma GCC optimize(2)
//��Ŀ���⣺h*w�ľ��Σ�N�β�ѯ��ÿ�δ��ϵ��£�������ռ��һ��ռ䣬��ÿһ��ճ����λ�� 
vector<int> Max;
int N, w, h, v;
int query(int rt, int l, int r, int v) {
	if (l > h)
		return -1;
	if (l == r) {
		if (Max[rt] < v)
			return -1;
		Max[rt] -= v;
		return l;
	}
	int Mid = (l + r) / 2, ans;
	if (Max[rt * 2] >= v)
		ans = query(rt * 2, l, Mid, v);
	else
		ans = query(rt * 2 + 1, Mid + 1, r,v);
	Max[rt] = max(Max[rt * 2], Max[rt * 2 + 1]);
	return ans;
}
int main() {
	while (cin >> h >> w >> N) {	//Nһ���ǹ��õ� 
		Max.resize((N+1)<<2);
		fill(Max.begin(), Max.end(), w);  //���ꣻ 
		for(int ii=0;ii<N;ii++){
			scanf("%d", &v);
			printf("%d\n", query(1, 1, N, v));		//���һ��������v��λ�� 
		}
	}
	return 0;
}
/*
3 5 5
2
4
3
3
3
*/
