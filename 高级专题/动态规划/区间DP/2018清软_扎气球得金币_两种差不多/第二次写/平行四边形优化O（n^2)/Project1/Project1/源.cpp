#pragma warning(disable:4996)
#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e3 + 5;
int N, s[maxn][maxn], dp[maxn][maxn];
vector<int> A;
int main() {
	scanf("%d", &N);
	A.resize(N + 2);
	A[0] = A[N + 1] = 1;
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
	}
	for (int i = 1; i <= N; i++) {
		s[i][i] = i;
	}
/*	1.����len��ֵ�Ǵ�1��N����1��N-1���ڲ�����ƽ���ı����Ż���ʱ��ֱ�Ӵ�1��N�����״�
		�ڱ����У���len��1~N-1ʱ������j=i+len����Ҳ��״̬ת�Ʒ����в�����������dp[2][2]�޷�ֱ��
		ȷ��������Ҫôlen��1ȡ��N��j=i+len-1,Ҫô��취ȷ��dp[2][2]���ֱ߽��ֵ

	2.Ҫʹ��ƽ���ı����Ż����������len��1ȡ��N-1�Ĳ����׳���
	��������j=i+len-1�ᵼ�������kֵ���0�����µ�һ��״̬ת�Ʒ�����
	A[i - 1] * A[k] * A[j + 1];�������ֵ����ȷ��������Ҫ��j=i+len�ı�﷽ʽ����Ӧ����Ҫ
	��һ��ʼ��һЩ��ʼ����ȷ���߽��dp[i][i]ֵ��*/
	for (int i = 1; i <= N; i++) {
		dp[i][i] = A[i - 1] * A[i] * A[i + 1];//�߽������������ʼ��
	}
	for (int len = 1; len < N; len++) {
		for (int i = 1; i + len <= N ; i++) {
			int j = i + len;
			for (int k = s[i][j - 1]; k <= s[i + 1][j]; k++) {
				int tp = dp[i][k - 1] + dp[k + 1][j] + A[i - 1] * A[k] * A[j + 1];
				if (tp > dp[i][j]) {
					dp[i][j] = tp;
					s[i][j] = k;
				}
			}
		}
	}
	cout << dp[1][N];
	return 0;
}
/*
4
3 1 5 8
*/