#include <iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<bitset>
#define lowbit(x) x&(-x)
using namespace std; 
const int maxn=1e5+10;
int A[maxn],N;
vector<pair<double,int> >mp;
long long c[maxn],r[maxn];
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
void Solve(){
	memset(r,0,sizeof(r));
	memset(c,0,sizeof(c));
	for(int i=N;i>=1;i--){
		Add(A[i],1);
		r[i]=getsum(A[i]-1);
	}
	printf("%d",r[1]);
	for(int i=2;i<=N;i++)
		printf(" %d",r[i]);
}
int main() {
	cin>>N;
	double t;
	for(int i=1;i<=N;i++){
		scanf("%lf",&t);
		mp.push_back(make_pair(t,i));
	}
	sort(mp.begin(),mp.end());
	int rank=1;
	t=mp[0].first;
	for(int i=0;i<mp.size();i++){  //??ɢ?? 
		rank=(i==0||mp[i].first==mp[i-1].first)?rank:i+1;
		A[mp[i].second]=rank;
	}
	Solve();
	return 0;
}
/*
6
24 35 12 1 56 23
*/
