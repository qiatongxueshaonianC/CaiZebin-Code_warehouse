#include<iostream>
#include<cstring>
#include<string>
#include<sstream>
#include<cmath>
#include<climits>
#include<ctime>
#include<fstream>
#include<iomanip>
using namespace std;
const int inf=0x3fffffff;
const int maxn=1e4+10;
int N,A[maxn],dp[maxn][10];		//dp[i][j]表示当前正在处理第i位，并且第i位值为j的情况 
#define f(i,j) (i-j)*(i-j)
#define min(a,b) a>b?b:a
void Solve(){
	for(int i=0;i<10;i++){
		dp[0][i]=abs(i-A[0]);
	}
	for(int i=1;i<N;i++){
		for(int j=0;j<10;j++){
			dp[i][j]=inf;
			for(int k=0;k<10;k++){
				dp[i][j]=min(dp[i][j],dp[i-1][k]+abs(j-A[i])+f(j,k));
			}
		}
	}
	int ans=inf;
	for(int i=0;i<10;i++){
		ans=min(ans,dp[N-1][i]);
	}
	cout<<ans<<endl;
}
int main(){
	std::ios::sync_with_stdio(false);
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>A[i];
	} 
	Solve();
	return 0;
} 
/*
6
1 4 2 8 5 7
*/
