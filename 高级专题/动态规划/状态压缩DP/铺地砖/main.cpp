/*
ID:aqx
PROG:铺地砖
LANG:c++
*/
//第i列，枚举到了第j行，当前状态是state，对下一列的影响是nex
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <iostream>
const int MOD=1e9+7;
using namespace std;
 
int N, M;
long long dp[100005][34];
 
void dfs(int i,int j,int state,int nex)
{
	if (j==N)
	{
		dp[i+1][nex]=(dp[i+1][nex]+dp[i][state])%MOD;
		return;
	}
	//如果这个位置已经被上一列所占用,直接跳过
	if (((1<<j)&state)>0)
		dfs(i,j+1,state,nex);
	//如果这个位置是空的，尝试放一个1*2的
	if (((1<<j)&state)==0)
		dfs(i,j+1,state,nex|(1<<j));
	//如果这个位置以及下一个位置都是空的，尝试放一个2*1的
	if (j+1<N && ((1<<j)&state)==0 && ((1<<(j+1))&state)==0)
		dfs(i,j+2,state,nex);
	return;
}
 
int main()
{
	while (cin>>N>>M)
	{
		memset(dp,0,sizeof(dp));
		if (N==0 && M==0) break;
		dp[1][0]=1; 
		for (int i=1;i<=M;i++)
		{
			for (int j=0;j<(1<<N);j++)
			if (dp[i][j])
			{
				dfs(i,0,j,0);
				if(i==1&&j==0)
					break;
			}
		}
		cout<<dp[M+1][0]<<endl;
	}
}
/*
2 2 
5 1
3 3
5 5
*/ 
