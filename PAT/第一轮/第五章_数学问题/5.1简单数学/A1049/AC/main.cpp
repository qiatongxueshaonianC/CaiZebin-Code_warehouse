#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n,ans=0,a=1;
	int left,right,now;
	scanf("%d",&n);
	while(n/a!=0){
		left=n/(a*10);
		now=n/a%10;
		right=n%a;
		if(now==0) ans+=left*a;
		else if(now==1) ans+=left*a+right+1;  //因为从0开始
		else ans+=(left+1)*a; 
		a*=10;
	} 
	printf("%d\n",ans);
	return 0;
}
/*
12
*/

