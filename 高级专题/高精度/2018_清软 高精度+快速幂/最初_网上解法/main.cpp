#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
#include<numeric>
#include<vector>
#include<map>
#include<set>
#include<queue>
using namespace std;
const int maxn=2020;
int ans[maxn],n;
void mul(int (&a)[maxn],int b[]){
	int temp_ans[maxn]={0},len=maxn/2;
	for(int t=1;t<len;t++){
		for(int j=1;j<len;j++){
			temp_ans[t+j-1]+=a[t]*b[j];
			temp_ans[t+j]+=temp_ans[t+j-1]/10;
			temp_ans[t+j-1]%=10;
		}
	}
	for(temp_ans[0]=maxn-1;temp_ans[temp_ans[0]]==0;temp_ans[0]--);
	swap(a,temp_ans);
}
void Solve(int (&ans)[maxn],int b){
	int base[maxn]={0};
	ans[1]=1;
	base[1]=2;
	while(b>0){
		if(b&1){
			mul(ans,base);
		}
		mul(base,base);
		b=b>>1;
	}
}
void output(int a[],int b){
//	printf("%d\n",a[0]);   
	printf("%d\n",(int)(b*log(2)/log(10))+1);
	for(int i=500;i>0;i--)
		printf("%d",a[i]);
}
int main() {
	scanf("%d",&n);
	Solve(ans,n);
	output(ans,n);
	return 0;
}
/*
1000
3100000
*/
