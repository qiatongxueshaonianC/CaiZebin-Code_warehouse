#include<bits/stdc++.h>
using namespace std; 
#define lowbit(x) x&(-x)
const int maxn=1e5+10;
typedef long long LL;
int N,C[maxn];
LL left_less[maxn],right_less[maxn];
vector<int> A;
void Add(int pos,int num){
	for(int i=pos;i<maxn;i+=lowbit(i)){
		C[i]+=num;
	}
}
LL getSum(int idx){
	LL sum=0;
	for(int i=idx;i>0;i-=lowbit(i)){
		sum+=C[i];
	}
	return sum;
}
int main() {
	scanf("%d",&N);
	memset(C,0,sizeof(C));
	A.resize(N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
		Add(A[i],1);
		left_less[i]=getSum(A[i]-1);
	}
	memset(C,0,sizeof(C));
	for(int i=A.size()-1;i>=0;i--){
		Add(A[i],1);
		right_less[i]=getSum(A[i]-1);
	}
	LL ans=0;
	for(int i=0;i<N;i++){
		ans+=(i-left_less[i])*right_less[i];
	}
	printf("%lld",ans);
	return 0;
}
/*
5
5 1 4 3 2
22
1 2 3 4 5 16 6 7 8 9 10 19 11 12 14 15 17 18 21 22 20 13
*/
