#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
    m=m%n;
	vector<int> A(n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	for(int i=n-m;i<n;i++)
		printf("%d ",A[i]);
	for(int i=0;i<n-m;i++)
		printf("%d%s",A[i],i==n-m-1?"":" ");
	return 0;
}
/*
6 6
1 2 3 4 5 6
*/
