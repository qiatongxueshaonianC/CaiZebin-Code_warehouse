#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n,p,ans=0;
	long long temp;
	scanf("%d%d",&n,&p);
	vector<long long> A(n);
	for(int i=0;i<n;i++)
		scanf("%lld",&A[i]);
	sort(A.begin(),A.end());
	for(int i=0;i<n;i++){
		temp=A[i]*p;
		if(n-i<=ans)
			break; 
		int j=upper_bound(A.begin()+i,A.end(),temp)-A.begin();
		ans=ans>j-i?ans:j-i;
	}
	printf("%d",ans);
	return 0;
}
/*
10 8
2 3 20 4 5 1 6 7 8 9
*/
