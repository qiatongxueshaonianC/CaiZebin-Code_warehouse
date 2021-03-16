#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
int main() {
	int n; 
	ll a,b,c,add;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld%lld%lld",&a,&b,&c);
		add=a+b;
		if(a>0&&b>0&&add<0) 
			printf("Case #%d: true\n",i);
		else if(a<0&&b<0&&add>=0)   //ÕâÀïÊÇadd>=0; 
			printf("Case #%d: false\n",i);
		else printf("Case #%d: %s\n",i,add>c?"true":"false");
	}
	return 0;
}
/*
3
1 2 3
2 3 4
9223372036854775807 -9223372036854775808 0
*/
