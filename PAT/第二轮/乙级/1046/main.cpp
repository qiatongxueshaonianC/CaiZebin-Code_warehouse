#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n,a,b,c,d,ans[2]={0};
	scanf("%d",&n);
	while(n--){
		scanf("%d%d%d%d",&a,&b,&c,&d);
		if(b==a+c&&b!=d)
			ans[1]++;
		else if(d==a+c&&b!=d)
			ans[0]++;
	} 
	printf("%d %d",ans[0],ans[1]);
	return 0;
}
/*
5
8 10 9 12
5 10 5 10
3 8 5 12
12 18 1 13
4 16 12 15
*/
