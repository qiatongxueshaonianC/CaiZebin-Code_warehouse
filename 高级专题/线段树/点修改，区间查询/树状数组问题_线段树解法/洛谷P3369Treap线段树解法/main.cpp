#include<bits/stdc++.h>
#define lowbit(x) x&(-x)
using namespace std; 
const int base=1e7+1;
const int maxn=base*2;
int sum[maxn<<2],N,op,v;
void update(int rt,int L,int R,int pos,int num){
	if(L==R&&L==pos)
		sum[rt]+=num;
	else{
		int Mid=(L+R)/2;
		if(pos<=Mid)
			update(rt*2,L,Mid,pos,num);
		else
			update(rt*2+1,Mid+1,R,pos,num);
		sum[rt]=sum[rt<<1]+sum[rt<<1|1];
	}
}
int query(int rt,int l,int r,int L,int R){
	if(L>R)
		return 0;
	if(L<=l&&r<=R)
		return sum[rt];
	int Mid=(l+r)/2,temp=0;
	if(L<=Mid)
		temp+=query(rt*2,l,Mid,L,R);
	if(R>Mid)
		temp+=query(rt<<1|1,Mid+1,r,L,R);
	return temp;
}
int findKthElement(int K){
	int L=1,R=maxn,Mid;
	while(L<R){
		Mid=(L+R)/2;
		if(query(1,1,maxn,1,Mid)>=K)
			R=Mid;
		else
			L=Mid+1;
	}
	return L;
}
int findVthElement(int V){
	int L=1,R=maxn,Mid;
	while(L<R){
		Mid=(L+R)/2;
		if(query(1,1,maxn,1,Mid)>V)
			R=Mid;
		else
			L=Mid+1;
	}
	return L;
}
int main() {
	cin>>N;
	while(N--){
		scanf("%d%d",&op,&v);
		v+=base;
		if(op==1)
			update(1,1,maxn,v,1);
		else if(op==2)
			update(1,1,maxn,v,-1);
		else if(op==3)
			printf("%d\n",query(1,1,maxn,1,v-1)+1);		//求的是“数”的排名 
		else if(op==4)
			printf("%d\n",findKthElement(v-base)-base);  //求的是数 
		else if(op==5)
			printf("%d\n",findKthElement(query(1,1,maxn,1,v-1))-base);
		else
			printf("%d\n",findVthElement(query(1,1,maxn,1,v))-base); 
	}
	return 0;
}
/*
10
1 106465
4 1
1 317721
1 460929
1 644985
1 84185
1 89851
6 81968
1 492737
5 493598
*/
