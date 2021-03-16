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
using namespace std; 
const int maxn=200010;
int Max[maxn<<2],N,M;
void build(int rt,int L,int R){
	if(L==R)	//到达叶子节点
		scanf("%d",&Max[rt]);
	else{
		int Mid=(L+R)/2;
		build(rt*2,L,Mid);
		build(rt*2+1,Mid+1,R);
		Max[rt]=max(Max[rt*2],Max[rt*2+1]);
	} 
}
void Set(int rt,int L,int R,int pos,int num){
	if(L==R&&L==pos)
		Max[rt]=num;
	else{
		int Mid=(L+R)/2;
		if(pos<=Mid)
			Set(rt*2,L,Mid,pos,num);
		else
			Set(rt*2+1,Mid+1,R,pos,num);
		Max[rt]=max(Max[rt*2],Max[rt*2+1]);
	}
}
int query(int rt,int l,int r,int L,int R){
	if(L>R)
		return 0;
	if(L<=l&&r<=R)
		return Max[rt];
	int Mid=(l+r)/2,temp=-INT_MAX;
	if(L<=Mid)
		temp=max(temp,query(rt*2,l,Mid,L,R));
	if(R>Mid)
		temp=max(temp,query(rt*2+1,Mid+1,r,L,R));
	return temp;
}
int main() {
	while(scanf("%d%d",&N,&M)!=EOF){
		memset(Max,0,sizeof(Max));
		build(1,1,N);
		getchar();
		char c;
		for(int i=0;i<M;i++){
			int L,R;
			scanf("%c %d %d%*c",&c,&L,&R);
			if(c=='Q')
				printf("%d\n",query(1,1,N,L,R));
			else
				Set(1,1,N,L,R);
		}
	}
	return 0;
}
/*
5 6
1 2 3 4 5
Q 1 5
U 3 6
Q 3 4
U 2 9
Q 1 5
Q 4 5
*/
