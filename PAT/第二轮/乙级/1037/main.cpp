#include<bits/stdc++.h>
using namespace std; 
int main() {
	int a[3],b[3],need,have,ans;
	scanf("%d.%d.%d",&a[0],&a[1],&a[2]);
	scanf("%d.%d.%d",&b[0],&b[1],&b[2]); 
	need=a[0]*17*29+a[1]*29+a[2];
	have=b[0]*17*29+b[1]*29+b[2];
	ans=abs(have-need);
	printf("%s%d.%d.%d",have>=need?"":"-",ans/(17*29),(ans%(17*29))/29,ans%29);
	return 0;
}
/*
10.16.27 14.1.28

14.1.28 10.16.27
*/
