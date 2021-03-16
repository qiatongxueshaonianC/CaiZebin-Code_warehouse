#include<iostream>
#include<cstdio> 
#include<vector>
#include<ctime>
//dp[i][j]=min(dp[i-1][k]);for k=0~9;
using namespace std;
typedef long long LL;
const int maxn=1e7+10;
int A[maxn],B[maxn],N,dp[maxn][10];
void Solve(){
	for(int i=0;i<N;i++){
	//	scanf("%d",&A[i]);	
		A[i]=(rand()*rand())%10;
	}
/*	int hash1[10][10],hash2[10][10];
	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			hash1[i][j]=i<j?j-i:i-j;
			hash2[i][j]=(i-j)*(i-j);
		}
	}*/
	for(int j=0;j<=9;j++)
		dp[0][j]=abs(j-A[j]);
	for(int i=1;i<N;i++){
		for(int j=0;j<=9;j++){
			dp[i][j]=INT_MAX;
			for(int k=0;k<=9;k++){
			//	dp[i][j]=min(dp[i][j],dp[i-1][k]+hash1[j][A[i]]+hash2[j][k]);
				dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(j-A[i])+(j-k)*(j-k));
			}
		}
	}
	int ans=INT_MAX;
	for(int i=0;i<=9;i++)
		ans=min(ans,dp[N-1][i]);
	printf("%d\n",ans);
}
int main() {
	clock_t start,finish;
	scanf("%d",&N);
	start=clock();
	Solve(); 
	finish=clock();
	cout<<finish-start<<"/"<<CLOCKS_PER_SEC<<"(s)"<<endl;
	return 0;
}
/*
6
1 4 2 8 5 7
*/
