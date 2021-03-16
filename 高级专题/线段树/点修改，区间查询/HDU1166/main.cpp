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
const int maxn=100000+5;
int T,N,sum[maxn<<2]; 
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
void update(int rt,int L,int R,int pos,int num){
	if(L==R&&L==pos)
		sum[rt]+=num;
	else{
		int Mid=(L+R)/2;
		if(pos<=Mid)
			update(rt*2,L,Mid,pos,num);
		else
			update(rt*2+1,Mid+1,R,pos,num);
		sum[rt]=sum[rt*2]+sum[rt*2+1];
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
		temp+=query(rt*2+1,Mid+1,r,L,R);
	return temp;
}
int main() {
	cin>>T;
	for(int ii=1;ii<=T;ii++){
		cin>>N;
		printf("Case %d:\n",ii);
		build(1,1,N);
		string op;
		while(cin>>op&&op[0]!='E'){
			int L,R;
			scanf("%d%d",&L,&R);
			if(op[0]=='Q')
				printf("%d\n",query(1,1,N,L,R));
			else if(op[0]=='S')
				update(1,1,N,L,-R);
			else
				update(1,1,N,L,R);
		}
	}
	return 0;
}
/*
1
10
1 2 3 4 5 6 7 8 9 10
Query 1 3
Add 3 6
Query 2 7
Sub 10 2
Add 6 3
Query 3 10
End 
*/
