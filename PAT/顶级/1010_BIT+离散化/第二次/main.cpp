#include<bits/stdc++.h>
using namespace std; 
const int maxn=1e5+10;
typedef long long LL;
#define lowbit(x) x&(-x)
LL N,C[maxn],right_less[maxn];
vector<int> B;
vector<pair<double,int>> A;
void Add(int pos,LL num){
	for(int i=pos;i<maxn;i+=(lowbit(i))){
		C[i]+=num;
	}
}
LL getSum(int pos){
	LL sum=0;
	for(int i=pos;i>0;i--){
		sum+=C[i];
	} 
	return sum;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin>>N;
	A.resize(N);B.resize(N);
	for(int i=0;i<N;i++){
		cin>>A[i].first;
		A[i].second=i;
	}
	sort(A.begin(),A.end());
	int rank=1;
	B[A.begin()->second]=1;
	for(int i=1;i<N;i++){
		rank=A[i].first==A[i-1].first?rank:i+1;
		B[A[i].second]=rank;
	}
	for(int i=N-1;i>=0;i--){
		Add(B[i],1);
		right_less[i]=getSum(B[i]-1);
	}
	for(int i=0;i<N;i++){
		printf("%d%s",right_less[i],i==N-1?"":" ");
	}
	return 0;
}
/*
6
24 35 12 1 56 23
*/
