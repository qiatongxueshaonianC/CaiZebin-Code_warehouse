#include<bits/stdc++.h>
using namespace std; 
bool cmp(int a,int b){
	return a>b;
}
int main() {
	int n,i=0;
	scanf("%d",&n);
	int A[n];
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	sort(A,A+n,cmp);
	while(i<n&&A[i]>i+1) 
		i++;
	printf("%d\n",i);
	return 0;
}
/*
2
10 10

10
6 7 6 9 3 10 8 2 7 8

10
10 9 8 8 7 7 5 5 3 2

10
10 10 10 10 1 1 4 4 3 2
*/
