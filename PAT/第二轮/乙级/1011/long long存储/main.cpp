#include<bits/stdc++.h>
using namespace std; 
int main() {
	long long n,a,b,c;
	scanf("%lld",&n);
	for(int k=1;k<=n;k++){
		scanf("%lld%lld%lld",&a,&b,&c);
		printf("Case #%d: %s\n",k,a+b>c?"true":"false");
	}
	return 0;
}
/*
4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647
*/
