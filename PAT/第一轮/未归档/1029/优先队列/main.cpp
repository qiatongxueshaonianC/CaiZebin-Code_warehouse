#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll,vector<ll>,greater<ll> > ans; 
int main(){
	ll n,m,v,num=0;
	scanf("%lld",&n);
	for(int i=0;i<n;i++){
		scanf("%lld",&v);
		ans.push(v);
	}
	scanf("%lld",&m);
	for(int i=0;i<m;i++){
		scanf("%lld",&v);
		ans.push(v);
	}
	num=(n+m)%2==1?(n+m)/2+1:(n+m)/2;
	while(--num){
		ans.pop();
	}
	printf("%d\n",ans.top());
    return 0;
}
/*
4 11 12 13 14
5 9 10 15 16 17
*/
