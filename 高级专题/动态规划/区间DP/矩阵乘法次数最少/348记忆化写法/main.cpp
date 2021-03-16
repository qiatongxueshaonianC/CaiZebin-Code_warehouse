#include<bits/stdc++.h>
using namespace std;
const int maxn=30;
int dp[maxn][maxn],p[maxn],q[maxn],mark[maxn][maxn]; 
int f(int i,int j){
	int& ans=dp[i][j];
	if(ans<INT_MAX) return ans;
	for(int k=i;k<j;k++){
		int t=f(i,k)+f(k+1,j)+p[i]*q[k]*q[j];
		if(ans>t){   //这里决定了dp要初始化成一个“大值” 
			ans=t;
			mark[i][j]=k;
		}
	}
	return ans;
}
void print_ans(int i, int j){
	if(i == j){  printf("A%d",i+1); return; }
	printf("(");
	print_ans(i, mark[i][j]);
	printf(" x ");
	print_ans(mark[i][j]+1, j);
	printf(")");
}
int main(){
	int n,idx=1;
	while(scanf("%d",&n)==1&&n){
		fill(dp[0],dp[0]+maxn*maxn,INT_MAX);
		memset(mark,0,sizeof(mark));
		for(int i=0;i<n;i++){
			scanf("%d%d",&p[i],&q[i]);
			dp[i][i]=0;
		}
		int ans=f(0,n-1);
		printf("Case %d: ",idx++);
		print_ans(0,n-1);
		puts("");
	}
	return 0;
}
/*
3
1 5
5 20
20 1
3
5 10
10 20
20 35
6
30 35
35 15
15 5
5 10
10 20
20 25
0
*/


