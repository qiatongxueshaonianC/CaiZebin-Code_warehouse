#include<bits/stdc++.h>
using namespace std; 
int main() {
	int N;
	scanf("%d",&N);
	vector<double> A(N);
	for(int i=0;i<N;i++)
		scanf("%lf",&A[i]);
	double ans=0;
//	sort(A.begin(),A.end()); //这里还不能排序 
	for(int i=0;i<A.size();i++){
		ans+=A[i]*(N-i)*(i+1);
		//	ans+=A[i]*((N-i)*(i+1));  //2020/1/26/18:19会溢出，i和N可以达到100000
	} 
	printf("%.2lf",ans);
	return 0;
}
/*
4
0.1 0.2 0.3 0.4

5
0.2 0.1 0.3 0.4 0.5

2
0.3 0.4
*/
