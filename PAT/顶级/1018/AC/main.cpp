#pragma GCC optimize(2)
#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL mod=1e9+7;
const int maxn=1e5+5;
string s;
LL sum[maxn],ans[10][maxn];
void solve(){
	int len=s.length();
	for(LL i=1;i<=9;++i){
		ans[i][1]=i;
		for(int j=2;j<=len;++j) ans[i][j]=10ll*ans[i][j-1]%mod+i;
	}
	for(int i=0;i<len;++i){
		if(s[i]!='0') ++sum[i];
		if(i) sum[i]+=sum[i-1];
	}
	LL res=0;
	for(int i=0;i<len;++i){
		res+=ans[s[i]-'0'][len-i]*sum[i]%mod;
		res%=mod;
	}
	cout<<res;
}
int main(){
//	freopen("Sakura.txt","r",stdin);
	cin>>s;
	solve();
	return 0;
}

/*
1021
1234567890123456789
*/
