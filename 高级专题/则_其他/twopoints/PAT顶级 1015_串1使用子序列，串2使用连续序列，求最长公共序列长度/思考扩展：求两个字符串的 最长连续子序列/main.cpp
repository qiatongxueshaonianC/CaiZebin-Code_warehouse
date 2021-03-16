#include<bits/stdc++.h>
using namespace std;
const int maxn=1010;
string s1,s2;
int dp[maxn][maxn];
int main(){
	cin>>s1>>s2;
	s1.insert(0," ");
	s2.insert(0," ");
	int ans=0;
	for(int i=1;i<s1.size();i++){
		for(int j=1;j<s2.size();j++){
			if(s1[i]==s2[j])
				dp[i][j]=max(dp[i][j],dp[i-1][j-1]+1),ans=max(ans,dp[i][j]);
			else
				dp[i][j]=0;
		}
	}
	cout<<ans<<endl;
	
	//解法2复杂度：O(nlogn) 此处没考虑字符串内部的比较，使用字符串哈希可以进一步优化 
	if(s1.size()>s2.size())
		swap(s1,s2);
	ans=0;
	int L=0,R=s1.size();
	string ans_string;
	while(L<R){		
		int Mid=(L+R)/2;
		bool flag=false;
		for(int i=0;i+Mid<=s1.size();i++){
			string temp=s1.substr(i,Mid);
			cout<<temp<<endl;
			if(s2.find(s1.substr(i,Mid))!=string::npos){
				ans_string=s1.substr(i,Mid);
				ans=max(ans,Mid);
				flag=true;
				break;
			}
		}
		if(flag)
			L=Mid+1;
		else
			R=Mid;
	}
	cout<<ans_string<<' '<<ans<<endl;
}

/*
ABCDEFG
BCDEFGHI
iononmrogdg
goodmorning
*/
