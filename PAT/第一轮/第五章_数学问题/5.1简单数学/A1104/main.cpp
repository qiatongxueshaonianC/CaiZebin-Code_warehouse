#include<bits/stdc++.h>
using namespace std;
vector<double> A; 
int main() {
	int n;
	scanf("%d",&n);
	A.resize(n);
	for(int i=0;i<n;i++)
		scanf("%lf",&A[i]);
	double ans=A[0]*A.size();
	for(int i=1;i<A.size();i++)
		ans+=A[i]*(A.size()-i)*(i+1);   //???ֵ? 
	printf("%.2lf\n",ans);
	return 0;
}
/*
4
0.1 0.2 0.3 0.4
*/
