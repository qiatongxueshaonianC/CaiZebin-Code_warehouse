#include<bits/stdc++.h>
using namespace std;
const int maxn=18;
int N,idx=1,P[maxn],dp[1<<maxn],Cover[1<<maxn]; 
vector<vector<int> > A;
void init(){
	memset(Cover,0,sizeof(Cover));
	memset(dp,0,sizeof(dp));
	memset(P,0,sizeof(P));
}
void Solve(){
	for(int S=1;S<(1<<N);S++){	//枚举不同子集合并后的覆盖情况 
		for(int i=0;i<N;i++){
			if(S&(1<<i)){
				Cover[S]|=P[i];	//注意,Cover[]这里都是对集合S的操作；Cover[S]不是Cover[i] 
			}
		}
	}
	int ALL=(1<<N)-1;
	for(int S=0;S<(1<<N);S++){
	/*	for(int S0=0;S0<S;S0++){	//这么求S的子集S0是错的，例如S=101，S0有：000，001，010（不符合条件)
			if(Cover[S0]==ALL){
				dp[S]=max(dp[S],dp[S^S0]+1);
			}
		}*/
		//枚举S的子集的正确做法：
		for(int S0=S;S0;S0=(S0-1)&S){
			if(Cover[S0]==ALL){
				dp[S]=max(dp[S],dp[S^S0]+1);	//注意，dp是对S的操作，即都是dp[S] 
			}
		}
	}
	printf("Case %d: %d\n",idx++,dp[ALL]);
}
int main(){
	while(~scanf("%d",&N)&&N){
		init();
		A.resize(N);
		for(int i=0;i<N;i++){
			int m;scanf("%d",&m);
			A[i].resize(m);
			P[i]=(1<<i);
			for(int j=0;j<m;j++){
				scanf("%d",&A[i][j]);
				P[i]|=(1<<A[i][j]);
			}
		}
		Solve();
	}
	return 0;
}
/*
3
2 1 2
2 0 2
2 0 1
4
1 1
1 0
1 3
1 2
0
*/

