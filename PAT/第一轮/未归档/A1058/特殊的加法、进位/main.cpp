#include<bits/stdc++.h>
const int inf=0x3fffffff;
using namespace std; 
int main() {
	int a[3],u[3],ans[3],c=0,d[]={inf,17,29};
	scanf("%d.%d.%d",&a[0],&a[1],&a[2]);
	scanf("%d.%d.%d",&u[0],&u[1],&u[2]);
	for(int i=2;i>=0;i--){
		ans[i]=(a[i]+u[i]+c)%d[i];
		c=(a[i]+u[i]+c)/d[i];
	}
	printf("%d.%d.%d",ans[0],ans[1],ans[2]);
	return 0;
}
/*
3.2.1 10.16.27
*/
