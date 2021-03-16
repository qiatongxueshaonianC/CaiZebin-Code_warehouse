#include<bits/stdc++.h>
using namespace std; 
const int MOD=1e9+7;
string s; 
typedef long long LL;
LL ans=0;
int main() {
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')
			continue;
		LL temp=s[i]-'0';
		ans+=temp;
		for(int j=i+1;j<s.size();j++){
			temp=temp*10+s[j]-'0';
			ans+=temp;
			if(ans>MOD)
				ans%=MOD;
		}
	}
	printf("%lld",ans);
	return 0;
}
/*
1021
1234567890123456789
*/
