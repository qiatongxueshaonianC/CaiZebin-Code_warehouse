/*
ID:aqx
PROG:�̵�ש
LANG:c++
*/
//��i�У�ö�ٵ��˵�j�У���ǰ״̬��state������һ�е�Ӱ����nex
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
	//������λ���Ѿ�����һ����ռ��,ֱ������
	if (((1<<j)&state)>0)
		dfs(i,j+1,state,nex);
	//������λ���ǿյģ����Է�һ��1*2��
	if (((1<<j)&state)==0)
		dfs(i,j+1,state,nex|(1<<j));
	//������λ���Լ���һ��λ�ö��ǿյģ����Է�һ��2*1��
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
