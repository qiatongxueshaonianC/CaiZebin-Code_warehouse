#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n,v,now=0,ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v);
		if(v>now) ans+=(v-now)*6;
		else if(v<now) ans+=(now-v)*4;
		now=v;
	}
	ans+=(n*5);
	printf("%d\n",ans);
	return 0;
}
/*
3 2 3 1
*/
