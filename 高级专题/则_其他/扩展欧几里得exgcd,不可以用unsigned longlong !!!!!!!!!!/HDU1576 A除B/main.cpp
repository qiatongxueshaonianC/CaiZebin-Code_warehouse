#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<numeric>
#include<climits>
#include<cmath>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<stack>
#include<list>
#include<bitset>
#include<iomanip>
#define lowbit(x) x&(-x)
using namespace std;
typedef long long LL;
LL exgcd(LL a,LL b,LL& x,LL& y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	LL d=exgcd(b,a%b,y,x);
	y-=(a/b)*x;		//2020/6/6/23:38发现，这里要（a/b)*x,如果是（a*x/b)会溢出 
	return d;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--){
		LL n,B,x,y,d;
		scanf("%lld%lld",&n,&B);
		d=exgcd(B,-9973,x,y);
		x=x/d*n;
		y=y/d*n;
		while(x<0)
			x+=9973;
		cout<<x%9973<<endl;
	}
	return 0;
}
/*
2
1000 53
87 123456789
*/
