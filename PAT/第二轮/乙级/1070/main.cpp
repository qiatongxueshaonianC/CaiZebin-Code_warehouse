#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n;
	scanf("%d",&n);
	vector<int> A(n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	sort(A.begin(),A.end());
	double ans=A[0];
	for(int i=1;i<A.size();i++)
		ans=(ans+A[i])/2.0;
	printf("%d",(int)floor(ans));
	return 0;
}
/*
8
10 15 12 3 4 13 1 15
*/
