#include<bits/stdc++.h>
using namespace std; 
int main() {
	int n,sum1,sum2;
	scanf("%d",&n);
	vector<int> A(n),S1,S2;
	for(int i=0;i<n;i++)
		scanf("%d",&A[i]);
	sort(A.begin(),A.end());
	int len=A.size()/2-1;
	for(int i=0;i<=len;i++)
		S1.push_back(A[i]);
	sum1=accumulate(S1.begin(),S1.end(),0);
	for(++len;len<A.size();len++)
		S2.push_back(A[len]);
	sum2=accumulate(S2.begin(),S2.end(),0);
	printf("%d %d\n",S2.size()-S1.size(),sum2-sum1);
	return 0;
}
/*
10
23 8 10 99 46 2333 46 1 666 555

13
110 79 218 69 3721 100 29 135 2 6 13 5188 85
*/
