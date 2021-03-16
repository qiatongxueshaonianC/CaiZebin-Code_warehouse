#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll,vector<ll>,greater<ll>>q;
int main() {
	int n;
	cin>>n;
	ll x,y,ans=0;
	for(int i=0;i<n;i++){
		scanf("%lld",&x);
		q.push(x);
	}
	while(q.size()>1){
		x=q.top();q.pop();
		y=q.top();q.pop();
		q.push(x+y);
		ans+=x+y;
	}
	printf("%lld\n",ans);
	return 0;
}
/*
8
5 29 7 8 14 23 3 11
*/
