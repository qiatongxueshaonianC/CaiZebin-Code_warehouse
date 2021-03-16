#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
typedef long long ll;
int main() {
	ll a,b;
	scanf("%lld%lld",&a,&b);
	a=__gcd(a,b);        //有两个下划线！！！！ 
	puts(to_string(a).c_str());
	return 0;
}
