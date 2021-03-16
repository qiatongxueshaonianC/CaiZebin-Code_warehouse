#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
typedef long long ll;
ll dp[maxn][3];
//	dp[i][j]=dp[i-1][j-1]+dp[i-1][j]
int main(){
	std::ios::sync_with_stdio(false);
	dp[0][0]=dp[0][1]=1;dp[0][2]=0;
	string s;
	cin>>s;
	for(int i=1;i<s.size();i++){
		for(int j=0;j<=2;j++){
			if(i+1==j){dp[i][j]=1;continue;}  //全删 
			if(j==0){dp[i][j]=1;continue;}		//不删 
			dp[i][j]=dp[i-1][j-1]+dp[i-1][j];	//删i和不删i两种情况；
			for(int pos=i-1;pos>=0&&(i-pos)<=j;pos--){	//保证pos、pos+1···能够在j的覆盖范围之内 
				if(s[pos]==s[i]){ //pos位开始（包含pos位）到i-1位全部删除，剩下的就是pos-1位之前的了
									//还剩下：j-（i-pos)个位置可以删除 
					dp[i][j]-=(pos==0)?1:dp[pos-1][j-(i-pos)];
					break;
				} 
			} 
		}
	}
	cout<<dp[s.size()-1][2]+dp[s.size()-1][1]+1;
	return 0;
}
/*
ababcc
*/
