#include<bits/stdc++.h>
using namespace std; 
const int maxn=100010;
int main() {
	string s;
	getline(cin,s);
	int hash[maxn][2];
	hash[0][0]=s[0]=='P'?1:0;
	hash[s.size()-1][1]=*(--s.end())=='T'?1:0;
	for(int i=1,r=s.size()-2;i<s.size();i++,r--){
		hash[i][0]=s[i]=='P'?hash[i-1][0]+1:hash[i-1][0];
		hash[r][1]=s[r]=='T'?hash[r+1][1]+1:hash[r+1][1];
	}
	long long ans=0;
	for(int i=1;i+1<s.size();i++){
		if(s[i]=='A')
			ans+=hash[i][0]*hash[i][1];
	}
	printf("%d",ans%1000000007);
	return 0;
}
/*
APPAPT
*/
