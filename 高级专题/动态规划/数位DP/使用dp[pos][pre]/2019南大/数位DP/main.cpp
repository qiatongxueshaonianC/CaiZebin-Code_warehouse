#include<bits/stdc++.h>
using namespace std;
int d[20],dp[20][10];	//这里可以这么写，因为违法要求的根本进不了递归 ，能不断递归，走到最后的都满足条件 
int DFS(int pos,int pre,bool ALL0,bool isLimit){
	if(pos==-1)
		return 1;   
	if(!isLimit&&!ALL0&&dp[pos][pre]!=-1)
		return dp[pos][pre];
	int up=isLimit?d[pos]:9,ans=0;
	for(int i=0;i<=up;i++){
		if(ALL0||abs(i-pre)==1)
			ans+=DFS(pos-1,i,ALL0&&i==0,isLimit&&i==d[pos]);
	}
	if(!isLimit&&!ALL0)
		dp[pos][pre]=ans;
	return ans;
}
int Solve(long long k){
	int len=0;
	long long temp=k;
	while(k!=0){
		d[len++]=k%10;
		k/=10;
	}
	if(temp<10) temp=temp+1;
	else temp=10;
	return DFS(len-1,0,true,true)-temp; //0-9共10个数 
} 
int main(){
    long long m,n;
    while(scanf("%lld%lld",&m,&n)==2&&n>=m){
    	fill(dp[0],dp[0]+20*10,-1);
    	printf("%d\n",Solve(n)-Solve(m-1));  //注意，这里是m-1 
	}
    return 0;
}
/*
12345678 98765432
123456789456123 98765432109876512
*/
