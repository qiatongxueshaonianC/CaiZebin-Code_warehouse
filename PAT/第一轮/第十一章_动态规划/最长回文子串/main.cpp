#include<bits/stdc++.h>
using namespace std; 
string s;
bool dp[1010][1010];
int main() {
	getline(cin,s);
	int ans=1;
	for(int i=0;i<s.size();i++){
		dp[i][i]=1;
		if(i<s.size()-1){
			if(s[i]==s[i+1]){
				dp[i][i+1]=1;
				ans=2;
			}
		}
	}
	for(int L=3;L<=s.size();L++){
		for(int i=0;i+L-1<s.size();i++){
			int j=i+L-1;
			if(s[i]==s[j]&&dp[i+1][j-1]==1){
				dp[i][j]=1;
				ans=L;
			}
		}
	}
	printf("%d\n",ans);	
	return 0;
}
/*
Is PAT&TAP symmetric?
*/
