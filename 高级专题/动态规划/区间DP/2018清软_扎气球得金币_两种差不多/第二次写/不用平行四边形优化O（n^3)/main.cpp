//2020/8/19���֣�����������ֻ����ȡlen��N��j=len-1 
//ԭ����Ϊdp[i][i]��û�취ֱ�ӵõ��ģ�dp[i][i]Ҳ��Ҫһ�μ�����ܵõ����Ժ���
//д�ɣ�1<=len<=N   j=i+len-1�ȽϺ� 

#include<bits/stdc++.h>
using namespace std; 
const int maxn=1e3+5;
int N,dp[maxn][maxn];
vector<int> A;
int main() {
	scanf("%d",&N);
	A.resize(N+2);
	A[0]=A[N+1]=1;
	for(int i=1;i<=N;i++){
		scanf("%d",&A[i]);
	}
/*	for(int i=1;i<=N;i++)
		dp[i][i]=A[i]; */		//��� 
	for(int len=1;len<=N;len++){		//2020/8/19���֣�����������ֻ����ȡlen��N��j=len-1 
		for(int i=1;i+len<=N+1;i++){
			int j=i+len-1;
			for(int k=i;k<=j;k++){
			//	dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+A[k-1]*A[k]*A[k+1]);//2020/8/9/01��50����
			//	����ע�⣬�Ƕԡ�i~j������������������ԣ�������A[i-1]��A[j]+1
				dp[i][j]=max(dp[i][j],dp[i][k-1]+dp[k+1][j]+A[i-1]*A[k]*A[j+1]); 
			}
		}
	}
	cout<<dp[1][N];
	return 0;
}
/*
4
3 1 5 8
*/
