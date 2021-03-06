#include <iostream>
#include<stdio.h>
#include<cstring>
#include<string>
#include<sstream>
#include<algorithm>
#include<cmath>
#include<climits>
#include<numeric>
#include<map>
#include<set>
#include<queue>
#include<stack>
#include<list>
#include<ctime>
#include<fstream>
#include<iomanip>
using namespace std; 
#define lson rt<<1
#define rson rt<<1|1 
const int maxn=100000+10;
struct Node{
	int data;
	int l,r;
	int Mid(){
		return (l+r)>>1;
	}
}A[maxn<<2];
int L,T,O,sum[maxn<<2],Set[maxn<<2],ans;
void pushUp(int rt){
	sum[rt]=sum[rt<<1]|sum[rt<<1|1];
}
void build(int rt,int l,int r){
	A[rt].l=l;A[rt].r=r;
	if(l==r){
		sum[rt]=1;			//初始时设为第一种颜色 
		return;
	}
	build(lson,l,A[rt].Mid());
	build(rson,A[rt].Mid()+1,r);
	pushUp(rt);
}
void push_down(int rt){
	Set[lson]=Set[rson]=Set[rt];
	sum[lson]=sum[rson]=(1<<(Set[rt]-1));
	Set[rt]=0;
}
void update(int rt,int L,int R,int num){	//把L到R设为第num种颜色 
	if(L<=A[rt].l&&A[rt].r<=R){
//		sum[rt]=sum[rt]|(1<<(num-1)); 	//错了 
		sum[rt]=1<<(num-1);	//注意，这里只能是设值，不是或 
		Set[rt]=num;
		return;
	}
	if(Set[rt]){
		push_down(rt);
	}
	if(L<=A[rt].Mid())
		update(lson,L,R,num);
	if(A[rt].Mid()<R)
		update(rson,L,R,num);
	pushUp(rt);
}
void query(int rt,int L,int R){
	if(L<=A[rt].l&&A[rt].r<=R){
		ans|=sum[rt];
		return;
	}
	if(Set[rt]){
		push_down(rt);
	}
	if(L<=A[rt].Mid()){
		query(lson,L,R);
	}
	if(A[rt].Mid()<R){
		query(rson,L,R);
	}
	pushUp(rt);
}
void cal(int ans){
	int num=0;
	while(ans){
		if(ans&1){
			num++;
		}
		ans=ans>>1;
	}
	cout<<num<<endl;
}
int main() {
	std::ios::sync_with_stdio(false);cin.tie(0);cout.tie(0); 
	cin>>L>>T>>O;cin.ignore();
	build(1,1,L);
	while(O--){
		char c;
		int L,R,num;
		cin>>c>>L>>R;
		if(L>R){
			swap(L,R);
		} 
		if(c=='C'){
			cin>>num;cin.ignore();
			update(1,L,R,num);
		}
		else{
			cin.ignore();
			ans=0;
			query(1,L,R);
			cal(ans);
		}
	}
	return 0;
}
/*
2 2 4
C 1 1 2
P 1 2
C 2 2 2
P 1 2
*/
