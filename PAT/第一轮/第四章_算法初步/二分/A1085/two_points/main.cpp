#include<bits/stdc++.h>
using namespace std; 
typedef long long ll;
int main() {
	int N,p;
	scanf("%d%d",&N,&p);
	ll A[N];
	for(int i=0;i<N;i++)
		scanf("%lld",&A[i]);
	sort(A,A+N);
	int i=0,j=0,ans=0;
	while(j!=N){
		while(j!=N&&A[i]*p>=A[j])
			j++;
		ans=max(ans,j-i);
		i++;
	}
	printf("%d\n",ans);
	return 0;
}
/*
10 8
2 3 20 4 5 1 6 7 8 9
*/
