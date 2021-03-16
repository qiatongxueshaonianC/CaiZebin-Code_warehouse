#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int main() {
	ll a,b,c;
	scanf("%lld%lld",&a,&b);
	c=__gcd(a,b);
	printf("%d\n",c);
	printf("%d\n",a/c*b);
	return 0;
}
/*
1000000007
2
*/
