#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
vector<ll> A;   //2019/11/25/20:36发现错误，使用int会溢出：10^9*10^5; 
int main() {
	int N,p,ans=0;
	scanf("%d%d",&N,&p);
	A.resize(N);
	for(int i=0;i<N;i++)
		scanf("%lld",&A[i]);
	sort(A.begin(),A.end());
	for(int i=0;i<N;i++){
		auto it=upper_bound(A.begin(),A.end(),p*A[i]);
		int right=it-A.begin();
		ans=max(ans,right-i);
		if(it==A.end())
			break;
	}
	printf("%d\n",ans);
	return 0;
}
/*
10 8
2 3 20 4 5 1 6 7 8 9

11 8
2 3 4 5 1 6 7 8 9 20 19
*/
