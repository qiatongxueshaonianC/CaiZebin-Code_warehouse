#include<bits/stdc++.h>
using namespace std;
int d[10],dp[10][2];
int DFS(int pos,int pre,bool is6,bool isLimit){
	if(pos==-1)
		return 1;
	if(!isLimit&&dp[pos][is6]!=-1)
		return dp[pos][is6];
	int up=isLimit?d[pos]:9;
	int ans=0;
	for(int i=0;i<=up;i++){
		if(i==4||(pre==6&&i==2))
			continue;
		ans+=DFS(pos-1,i,i==6,isLimit&&i==d[pos]);
	}
	if(!isLimit)
		dp[pos][is6]=ans;
	return ans;
}
int Solve(int k){
	int len=0;
	while(k!=0){
		d[len++]=k%10;
		k/=10;
	}
	return DFS(len-1,0,false,true);
}
int main(){
    int m,n;
    while(scanf("%d%d",&m,&n)==2&&m!=0&&n!=0){
    	fill(dp[0],dp[0]+10*2,-1);
    	printf("%d\n",Solve(n)-Solve(m-1));  //注意，这里是m-1 
	}
    return 0;
}
