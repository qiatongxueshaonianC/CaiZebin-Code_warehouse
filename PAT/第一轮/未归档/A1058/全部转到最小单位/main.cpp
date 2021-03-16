#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
int main() {
	ll a,b,c,u,v,w;
	scanf("%lld.%lld.%lld",&a,&b,&c);
	scanf("%lld.%lld.%lld",&u,&v,&w);
	a=a*17*29+b*29+c;
	u=u*17*29+v*29+w;
	a+=u;
	u=a/(17*29);
	v=(a-u*17*29)/29;
	w=a%29;
	printf("%lld.%lld.%lld",u,v,w);
	return 0;
}
/*
3.2.1 10.16.27
*/
