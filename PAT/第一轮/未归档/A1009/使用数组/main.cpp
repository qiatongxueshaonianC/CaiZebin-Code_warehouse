#include<bits/stdc++.h>
using namespace std; 
int main() {
	double A[2005]={0},B[2005]={0},v;
	int n,size=0,e;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%lf",&e,&v);
		A[e]=v;
	} 
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d%lf",&e,&v);
		for(int j=0;j<1001;j++)
			B[j+e]+=A[j]*v;
	} 
	for(int i=2000;i>=0;i--)
		if(B[i]!=0)
			size++;
	printf("%d",size);
	for(int i=2000;i>=0;i--)
		if(B[i]!=0)
			printf(" %d %.1lf",i,B[i]);
	return 0;
}
/*
2 1 2.4 0 3.2
2 2 1.5 1 0.5

2 1 2.4 0 3.2
1 1 0
*/
