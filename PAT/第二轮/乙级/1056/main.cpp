#include<bits/stdc++.h>
using namespace std;
int main() {
	int n,ans=0;
	scanf("%d",&n);
	vector<int> A(n);
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]); 
	for(int i=0;i<A.size();i++){
		for(int j=i+1;j<A.size();j++){
			ans+=(A[i]+A[j])*11;
		}
	}
	printf("%d",ans);
	return 0;
}
/*
3 2 8 5
*/
