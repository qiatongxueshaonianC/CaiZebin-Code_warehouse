#pragma warning(disable:4996)
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<iterator>
#define ALL(x) x.begin(),x.end()
using namespace std;
const int maxn=100000+5;
int N,T,O,Set[maxn<<4],sum[maxn<<2];
void build(int rt,int L,int R){
	if(L==R){
		sum[rt]=1;
		return;
	}
	int Mid=(L+R)/2;
	build(rt<<1,L,Mid);
	build(rt<<1|1,Mid+1,R);
	sum[rt]=sum[rt<<1]|sum[rt<<1|1];
}
void pushdown_set(int rt){
	Set[rt<<1]=Set[rt<<1|1]=Set[rt];
	sum[rt<<1]=sum[rt<<1|1]=(1<<(Set[rt]-1));
	Set[rt]=0;
}
void update(int rt,int l,int r,int L,int R,int v){
	if(L<=l&&r<=R){		//Lazy˼�룬������ͱ��һ�£����������¸����� 
		Set[rt]=v;
		sum[rt]=(1<<(v-1));
		return;
	}
	if(Set[rt])
		pushdown_set(rt);
	int Mid=(l+r)/2;
	if(L<=Mid)
		update(rt<<1,l,Mid,L,R,v);
	if(R>Mid)
		update(rt<<1|1,Mid+1,r,L,R,v);
	sum[rt]=sum[rt<<1]|sum[rt<<1|1];
}
int query(int rt,int l,int r,int L,int R){
	if(L<=l&&r<=R)
		return sum[rt];
	int Mid=(l+r)/2,temp=0;
	if(Set[rt])
		pushdown_set(rt);
	if(L<=Mid)
		temp=temp|query(rt<<1,l,Mid,L,R);
	if(R>Mid)
		temp=temp|query(rt<<1|1,Mid+1,r,L,R);
	return temp;
}
int Cal(int x){
	int num=0;
	while(x){
		num+=(x&1);
		x=x>>1;
	}
	return num;
}
int main() {
	cin>>N>>T>>O;
	build(1,1,N);
	char op;
	while(O--){
		scanf("%*c%c",&op);
		int L,R,v;
		if(op=='C'){
			scanf("%d%d%d",&L,&R,&v);
			if(L>R)
				swap(L,R);
			update(1,1,N,L,R,v);
		}else{
			scanf("%d%d",&L,&R);
			if(L>R)
				swap(L,R);
			printf("%d\n",Cal(query(1,1,N,L,R)));	
		}
	}
	return 0;
}
/*
2 2 5
P 1 2
C 1 1 2
P 1 2
C 2 2 2
P 1 2
*/
