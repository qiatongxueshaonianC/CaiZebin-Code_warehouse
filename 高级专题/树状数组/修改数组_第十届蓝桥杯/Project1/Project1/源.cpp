#pragma warning(disable:4996)
#include<iostream>
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
#include<list>
#include<bitset> 
#include<ctime>
#define lowbit(x) x&(-x)
using namespace std;
const int maxn = 10000010;
int A[maxn], N,ans[maxn],C[maxn];
bool vis[2*maxn];
void Add(int idx, int v) {
	for (int i = idx; i <= maxn; i += lowbit(i)) {
		C[i] += v;
	}
}
int getSum(int idx) {
	int sum = 0;
	for (int i = idx; i > 0; i -= lowbit(i))
		sum += C[i];  //2020/4/20/22��00������C[i]!!!!!����д��C[x]��
	return sum;
}
int findKthElement(int V) {
	int L = V, R = maxn,mid,len;
	while (L < R) {
		mid = (L + R) / 2;
		len = mid - V + 1;
		int sum = getSum(mid) - getSum(V-1);
		if (sum< len)   //˵���м���λ�û�û��ʹ�ù�
			R = mid;
		else
			L = mid + 1;  //˵����V-mid��һ�ε����Ѿ�ȫ����ʹ����
	}
	return L;
}
int main() {
	scanf("%d", &N);
	A[0] = 2;
	clock_t start, finish;
	start = clock();
	for (int i = 1; i <= N; i++)
		A[i] = (A[i - 1] +2) % 10007 + 1;
/*	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}*/
	for (int i = 0; i < N; i++) {
		if (!vis[A[i]]) {
			vis[A[i]] = true;
			ans[i] = A[i];
			Add(A[i], 1);
		}
		else {
			int pos=findKthElement(A[i]+1);
			vis[pos] = true;
			ans[i] = pos;
			Add(pos, 1);
		}
	}
	for (int i = 0; i < N; i++)
		printf("%d%s", ans[i], i == N-1? "" : " ");
	finish = clock();
	cout <<endl<< finish - start << "/" << CLOCKS_PER_SEC << "(s)" << endl;
	return 0;
}
/*
10
1 106465
4 1
1 317721
1 460929
1 644985
1 84185
1 89851
6 81968
1 492737
5 493598
*/