#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<climits>
#include<cmath>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
#include<list>
#define lowbit(x) x&(-x)
using namespace std; 
const int maxn=1e5+10;
int A[maxn],N,c[maxn];
long long l[maxn],r[maxn];
void Add(int x,int v){
	while(x<maxn){
		c[x]+=v;
		x+=lowbit(x);
	} 
} 
int getsum(int x){
	int sum=0;
	while(x>0){
		sum+=c[x];
		x-=lowbit(x);
	}
	return sum;
}
long long Solve(){
	memset(l,0,sizeof(l));
	memset(r,0,sizeof(r));
	memset(c,0,sizeof(c));
	for(int i=1;i<=N;i++){
		Add(A[i],1);
		l[i]=getsum(A[i]-1);
	}
	memset(c,0,sizeof(c));
	for(int i=N;i>=1;i--){
		Add(A[i],1);
		r[i]=getsum(A[i]-1);
	}
	long long ans=0;
	for(int i=2;i<N;i++)
		ans+=(i-1-l[i])*r[i];
	return ans; 
}
int main() {
	scanf("%d",&N);
	for(int i=1;i<=N;i++)
		scanf("%d",&A[i]);
	printf("%lld",Solve());
	return 0;
}
/*
22
1 2 3 4 5 16 6 7 8 9 10 19 11 12 14 15 17 18 21 22 20 13
*/
