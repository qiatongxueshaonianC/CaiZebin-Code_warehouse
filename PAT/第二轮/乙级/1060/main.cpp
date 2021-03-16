#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n,A[100010],idx; 
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&A[i]);
	sort(A+1,A+n+1,[](const int& a,const int& b){
		return a>b;
	});
	for(idx=1;A[idx]>idx;idx++);
	printf("%d",--idx);
	return 0;
}
/*
10
6 7 6 9 3 10 8 2 7 8
*/
