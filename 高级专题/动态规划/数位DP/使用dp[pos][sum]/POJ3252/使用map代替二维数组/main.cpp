#include<iostream> 
#include<cstring>
#include<cstdio>
#include<map>
using namespace std; 
int d[100];
map<pair<int,int>,int> dp;  //相当于dp[100][100]这样的二维数组 
int DFS(int pos,int pre,bool ALL0,bool isLimit){
	if(pos==-1)
		return pre>=0?1:0;
	map<pair<int,int>,int>::iterator it=dp.find(make_pair(pos,pre));
	if(!ALL0&&!isLimit&&it!=dp.end())
		return it->second;
	int up=isLimit?d[pos]:1;
	int ans=0;
	for(int i=0;i<=up;i++){
		if(i==0){
			if(ALL0)  //全是前导零 
				ans+=DFS(pos-1,pre,ALL0&&i==0,isLimit&&i==d[pos]);
			else
				ans+=DFS(pos-1,pre+1,ALL0&&i==0,isLimit&&i==d[pos]);
		}else
			ans+=DFS(pos-1,pre-1,ALL0&&i==0,isLimit&&i==d[pos]);
	}
	if(!ALL0&&!isLimit)
		dp.insert(make_pair(make_pair(pos,pre),ans));
	return ans;
}
int Solve(int k){
	int len=0;
	while(k!=0){
		d[len++]=k%2;
		k/=2;
	}
	return DFS(len-1,0,true,true);
}
int main() {
	long long n,m;
	scanf("%lld%lld",&m,&n);
	printf("%d\n",Solve(n)-Solve(m-1));
	return 0;
}
/*
2 12
*/ 
