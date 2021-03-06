#include<bits/stdc++.h>
using namespace std; 
typedef long long LL;
int d[20];
LL dp[20][10][2][13],N; 
LL DFS(int pos,int pre,bool have13,LL mod,bool isLimit){
	if(pos==-1){
	/*	if(mod%13==0&&have13){
			system("pause");
			return 1;
		}
		return 0;*/
		return (mod%13==0&&have13)?1:0;
	}
	if(!isLimit&&dp[pos][pre][have13][mod]!=-1)	//2020/5/19/0:58发现 
		return dp[pos][pre][have13][mod];		//注意：mod这里不能超过13，否则会越界 
	LL ans=0;
	int up=isLimit?d[pos]:9;
	for(int i=0;i<=up;i++){
		ans+=DFS(pos-1,i,have13||(pre==1&&i==3),(mod*10+i)%13,isLimit&&i==up);
	}
	if(!isLimit)
		dp[pos][pre][have13][mod]=ans;
	return ans;
}
LL Solve(LL n){
	int len=0;
	do{
		d[len++]=n%10;
		n/=10;
	}while(n!=0);
	return DFS(len-1,0,false,0,true);	//减去全0 
}
int main() {
	std::ios::sync_with_stdio(false);
	while(cin>>N){
		memset(dp,-1,sizeof(dp));
		cout<<Solve(N)<<endl;
	}
	return 0;
}
/*
13
100
200
1000
*/
