#include<bits/stdc++.h>
using namespace std; 
const int maxn=1e4+10;
int N,Sum,dp[maxn][110],mark[maxn][110];
vector<int> A;
bool vis[maxn];
void print_ans(int n,int S){
	for(int i=N;i>=1;i--){
		if(!vis[i]&&S>=A[i]&&dp[n][S]==dp[n-1][S-A[i]]+A[i]){
			vis[i]=true;
			printf("%d%s",A[i],S-A[i]==0?"\n":" ");
			print_ans(n-1,S-A[i]);
			break;
		}
	}
}
int main() {
	scanf("%d%d",&N,&Sum);
	A.resize(N+1);
	for(int i=1;i<=N;i++)
		scanf("%d",&A[i]);
	sort(A.begin()+1,A.end(),greater<int>());
	for(int i=1;i<=N;i++){
		for(int v=A[i];v<=Sum;v++){
			dp[i][v]=dp[i-1][v];
			if(v>=A[i])
				dp[i][v]=max(dp[i-1][v],dp[i-1][v-A[i]]+A[i]);
		}
	}
/*	int sum=Sum,n=N;
	while(n>0&&sum>0){
			if(dp[n][sum]==dp[n-1][sum-A[n]]+A[n]){  //Ҫ�ӡ���������״̬��ʼ�����ж�
			//��������жϣ��޷�֪��ĳ����Ʒ�Ƿ��ڰ����� ,��Ϊ�м̳�ǰ��Ĺ�ϵ 
				sum-=A[n];
				printf("%d%s",A[n],sum>0?" ":"\n");   //��Ϊ�ǵ�����������Գ�ʼҪ�������� 
			}
			n--;			
		}*/
	if(dp[N][Sum]!=Sum)
		puts("No Solution");
	else
		print_ans(N,Sum);
	return 0;
}
/*
8 9
5 9 8 7 2 3 4 1
1 2 3 4 5 7 8 9

14 9
5 4 8 7 2 3 4 1 1 1 1 1 1 1

4 8
7 2 4 3

100 82
58 23 69 86 11 5 44 84 35 68 67 49 45 100 60 99 91 70 86 98 51 61 39 
71 38 86 1 79 28 87 55 3 61 83 77 97 78 33 41 99 51 47 75 3 93 38 9 66 
89 95 51 87 59 70 6 68 31 49 99 32 88 9 62 77 84 7 37 2 69 91 32 95 61 
62 77 14 97 7 29 22 37 1 77 25 45 91 92 73 61 43 26 59 1 54 94 78 26 71 68 13
*/
