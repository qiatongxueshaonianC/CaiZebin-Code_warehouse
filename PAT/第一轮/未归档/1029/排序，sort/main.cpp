#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> ans; 
int main(){
	ll n,m,v,num=0;
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&v);
		ans.push_back(v);
	}
	scanf("%lld",&m);
	for(int i=0;i<m;i++){
		scanf("%lld",&v);
		ans.push_back(v);
	}
	sort(ans.begin(),ans.end());
	printf("%d\n",(n+m)%2==1?ans[(n+m)/2]:ans[(n+m)/2-1]);
    return 0;
}
/*
4 11 12 13 14
5 9 10 15 16 17
*/
