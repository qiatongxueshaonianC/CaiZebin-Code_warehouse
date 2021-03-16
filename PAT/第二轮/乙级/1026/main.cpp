#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	ll c1,c2;
	scanf("%lld%lld",&c1,&c2);
	c1=(round)((c2-c1)/100.0);
//	c1=round((c2-c1)/100.0);
//	c1=ceil((c2-c1+50)/100);
	printf("%02d:%02d:%02d",c1/3600,(c1%3600)/60,c1%60);
}
/*
123 4577973
*/
