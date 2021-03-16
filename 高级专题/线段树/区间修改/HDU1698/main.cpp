#include <iostream>
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
#define lowbit(x) x&(-x)
using namespace std; 
const int maxn=100010;
int T,N,Q,sum[maxn<<2],add[maxn<<2],st[maxn<<2];
void build(int rt,int L,int R){
	if(L==R)
		sum[rt]=1;
	else{
		int Mid=(L+R)/2;
		build(rt*2,L,Mid);
		build(rt*2+1,Mid+1,R);
		sum[rt]=sum[rt*2]+sum[rt*2+1];
	}
}
void pushDown_st(int rt,int len){
	if(st[rt]){
		st[rt*2]=st[rt*2+1]=st[rt];
		sum[rt*2]=(len+(len/2))*st[rt];
		sum[rt*2+1]=len/2*st[rt];
		add[rt*2]=add[rt*2+1]=0;  //设为无效 ，只能设下两个节点无效；有一种情况：先改值了，后面又加值了 
	}
}
void pushDown_ad(int rt,int len){
	if(add[rt]){
		add[rt*2]=add[rt*2+1]=add[rt];
		sum[rt*2]+=(len+(len/2))*add[rt];
		sum[rt*2+1]+=len/2*add[rt];
	}
}
void Set(int rt,int l,int r,int L,int R,int num){
	if(L<=l&&r<=R){
		st[rt]=num;
		add[rt]=0; //覆盖 
		sum[rt]=(r-l+1)*num;
	}
	else{
		if(st[rt])
			pushDown(rt,r-l+1);
		int Mid=(l+r)/2;
		if(L<=Mid)
			Set(rt*2,l,Mid,L,R,num);
		if(R>Mid)
			Set(rt*2+1,Mid+1,r,L,R,num);
		sum[rt]=sum[rt*2]+sum[rt*2+1];
	}
}
void update(int rt,int l,int r,int L,int R,int num){
	if(L<=l&&r<=R){
		add[rt]+=num;
		sum[rt]+=(r-l+1)*num;
	}
	else{
		if(add[rt])
			pushDown(rt,r-l+1);
		int Mid=(l+r)/2;
		if(L<=Mid)
			Set(rt*2,l,Mid,L,R,num);
		if(R>Mid)
			Set(rt*2+1,Mid+1,r,L,R,num);
		sum[rt]=sum[rt*2]+sum[rt*2+1];
	}
}
int query(int rt,int l,int r,int L,int R){
	if(L<=l&&r<=R)
		return sum[rt];
	int Mid=(l+r)/2,temp=0;
	if(st[rt])
		pushDown_st(rt,r-l+1);  //这里要分辨是set类型的还是updat类型的 
	if(add[rt])
		pushDown_ad(rt,r-l+1);	//一定要先判断改值再判断加值 
	if(L<=Mid)
		temp+=query(rt*2,l,Mid,L,R);
	if(R>Mid)
		temp+=query(rt*2+1,Mid+1,r,L,R);
	return temp;
}
int main() {
	cin>>T;
	for(int ii=1;ii<=T;ii++){
		scanf("%d%d",&N,&Q);
		build(1,1,N);
		int L,R,v;
		while(Q--){
			scanf("%d%d%d",&L,&R,&v);
			Set(1,1,N,L,R,v);
		}
		printf("Case %d: The total value of the hook is %d.\n",ii,sum[1]);
	}
	return 0;
}
/*
1
10
2
1 5 2
5 9 3
*/
