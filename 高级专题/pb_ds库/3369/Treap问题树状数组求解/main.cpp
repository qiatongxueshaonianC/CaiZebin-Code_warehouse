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
#include<fstream>
#include<ctime>
#define lowbit(x) x&(-x)
using namespace std; 
const int base=10000001;
const int maxn=2*base+5;
int N,op,v,C[maxn];
void add(int idx,int num){
	while(idx<=maxn){
		C[idx]+=num;
		idx+=lowbit(idx);
	}
}
int getSum(int idx){
	int ans=0;
	for(int i=idx;i>0;i-=lowbit(i))
		ans+=C[i];
	return ans;
}
int findKthElement(int K){
	int L=1,R=maxn,mid;
	while(L<R){
		mid=(L+R)/2;
		if(getSum(mid)>=K)  //找第一个大于等于 
			R=mid;
		else
			L=mid+1;
	}
	return L;
}
int findVthElement(int K){
	int L=1,R=maxn,mid;
	while(L<R){
		mid=(L+R)/2;
		if(getSum(mid)>K)  //找第一个大于 
			R=mid;
		else
			L=mid+1;
	}
	return L; 
}
int main() {
//	clock_t start,finish;
	cin>>N;
//	start=clock();
	while(N--){
		scanf("%d%d",&op,&v);
		v+=base;
		if(op==1)
			add(v,1);
		else if(op==2)
			add(v,-1);
		else if(op==3)
			printf("%d\n",getSum(v-1)+1);
		else if(op==4)
			printf("%d\n",findKthElement(v-base)-base);
		else if(op==5)
			printf("%d\n",findKthElement(getSum(v-1))-base);
		else if(op==6)
			printf("%d\n",findVthElement(getSum(v))-base);
	}
//	finish=clock();
//	cout<<finish-start<<"/"<<CLOCKS_PER_SEC<<"(s)"<<endl;
	return 0;
}
/*
12
1 -10000000
1 106465
4 1
3 106465
1 317721
1 460929
1 644985
1 84185
1 89851
6 81968
1 492737
5 493598
*/
