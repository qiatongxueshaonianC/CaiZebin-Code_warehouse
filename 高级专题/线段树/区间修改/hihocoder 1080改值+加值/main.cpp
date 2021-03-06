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
int N,M,sum[maxn<<2],add[maxn<<2],st[maxn<<2];
void build(int rt,int L,int R){
	if(L==R)
		scanf("%d",&sum[rt]);
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
		sum[rt*2]=(len-(len/2))*st[rt];
		sum[rt*2+1]=len/2*st[rt];
		add[rt*2]=add[rt*2+1]=0;  //设为无效 ，只能设下两个节点无效；有一种情况：先改值了，后面又加值了 
		st[rt]=0;
	}
}
void pushDown_ad(int rt,int len){
	if(add[rt]){
		add[rt*2]+=add[rt];
		add[rt*2+1]+=add[rt];
		sum[rt*2]+=(len-(len/2))*add[rt];
		sum[rt*2+1]+=len/2*add[rt];
		add[rt]=0;
	}
}
void Set(int rt,int l,int r,int L,int R,int num){
	if(L<=l&&r<=R){
		add[rt]=0; //覆盖 
		st[rt]=num;
		sum[rt]=(r-l+1)*num;
	}
	else{
		if(st[rt])
			pushDown_st(rt,r-l+1);
		if(add[rt])
			pushDown_ad(rt,r-l+1);
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
		if(st[rt])   //两个都要判断跟新，注意先后顺序 
			pushDown_st(rt,r-l+1); 
		if(add[rt])
			pushDown_ad(rt,r-l+1);
		int Mid=(l+r)/2;
		if(L<=Mid)
			update(rt*2,l,Mid,L,R,num);
		if(R>Mid)
			update(rt*2+1,Mid+1,r,L,R,num);
		sum[rt]=sum[rt*2]+sum[rt*2+1];
	}
}
void update(int rt,int l,int r,int L,int R,int num,bool op){
	if(L<=l&&r<=R){
		if(op==0){
			add[rt]+=num;
			sum[rt]+=(r-l+1)*num;
		}
		else{
			add[rt]=0;	//设为无效 
			st[rt]=num;
			sum[rt]=(r-l+1)*num;
		}
		return;
	}
	else{
		if(st[rt])
			pushDown_st(rt,r-l+1);
		if(add[rt])
			pushDown_ad(rt,r-l+1);
		int Mid=(l+r)/2;
		if(L<=Mid)
			update(rt*2,l,Mid,L,R,num,op);
		if(R>Mid)
			update(rt*2+1,Mid+1,r,L,R,num,op);
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
	cin>>N>>M;
	N++;
	build(1,1,N);
	while(M--){
		int op,L,R,v;
		scanf("%d%d%d%d",&op,&L,&R,&v);
		L++;R++; //下标从0开始，要加一 
	//	update(1,1,N,L,R,v,op);
		if(op==0)
			update(1,1,N,L,R,v);
		else
			Set(1,1,N,L,R,v);
		printf("%d\n",query(1,1,N,1,N)); 
	}
	return 0;
}
/*
10 6
3195 2202 4613 3744 2892 4858 619 5079 9478 7366 8942 
0 1 6 886
1 0 2 9710
1 0 10 7980
0 4 9 -7594
0 2 8 1581
0 4 4 -1010
*/
