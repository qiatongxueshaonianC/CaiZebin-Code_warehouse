#include<bits/stdc++.h>
using namespace std; 
int main() {
	int N;
	scanf("%d",&N);
	vector<double> A(N);
	for(int i=0;i<N;i++)
		scanf("%lf",&A[i]);
	double ans=accumulate(A.begin(),A.end(),0.0);	 
	for(int len=2;len<=A.size();len++){
		for(int j=0;j+len<=A.size();j++)
			ans=accumulate(A.begin()+j,A.begin()+j+len,ans);
	}
	printf("%.2lf",ans);
	return 0;
}
/*
4
0.1 0.2 0.3 0.4
*/
