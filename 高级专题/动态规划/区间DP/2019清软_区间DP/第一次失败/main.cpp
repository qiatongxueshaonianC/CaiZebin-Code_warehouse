#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<bitset>
#define lowbit(x) x&(-x);
using namespace std;
const int maxn=1010;
string dp[maxn][maxn],ans[maxn][maxn];
int mark[maxn][maxn],num[maxn][maxn];
string s;
void print_ans(int i, int j){
	
//	printf("(");
	print_ans(i, mark[i][j]);
	print_ans(mark[i][j]+1, j);
	if(num[i][j]>1){  printf("%d(%s)",num[i][j],dp[i][j].c_str()); }
	if(i==j) return;
//	printf(")");
}
int main() {
	getline(cin,s);
	s=' '+s;
	int n=s.size();
	fill(num[0],num[0]+maxn*maxn,1);
	for(int i=1;i<=n;i++)
		dp[i][i]=ans[i][i]=s[i];
	for(int len=2;len<n;len++){
		for(int left=1;left+len-1<n;left++){
			int right=left+len-1;
			for(int k=left;k<right;k++){
				if(dp[left][k]==dp[k+1][right]){
					num[left][right]=num[left][k]+num[k+1][right];
					dp[left][right]=dp[left][k];
				//	string temp=to_string(num[left][right]);
				//	if(temp.size()+2+dp[left][right].size()<=dp[left][right].size()*num[left][right]);
					//	dp[left][right]=temp+'('+dp[left][right]+')';
				}else{
					if(dp[left][right]!=""&&dp[left][k].size()+dp[k+1][right].size()>dp[left][right].size())
				//	if(dp[left][right]!=""&&num[left][k]+num[k+1][right]>num[left][right])
						continue;
					dp[left][right]=dp[left][k]+dp[k+1][right];
				//	ans[left][right]=ans[left][k]+ans[k+1][right];
				}
			//	puts(dp[left][right].c_str());
			}
		}
	}
	printf("%s\n",dp[1][n-1].c_str());
	puts(ans[1][n-1].c_str());
	print_ans(1,n-1);
	return 0;
}
/*
AAAAAAAAAABABABACCD
HELLOHELLOWORLDHELLOHELLOWORLD
*/
