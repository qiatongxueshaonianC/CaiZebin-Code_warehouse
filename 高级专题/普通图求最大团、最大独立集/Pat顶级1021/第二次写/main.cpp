#include<bits/stdc++.h>
using namespace std; 
const int maxn=1010;
int N,M,Price[maxn],G[maxn][maxn],best,Min_Price=INT_MAX,Stack[maxn][maxn],dp[maxn];
vector<int> A,ans,temp;
int mp[maxn],rmp[maxn],cnt=1;
void DFS(int idx,int total,int cnt,int price){
	if(total==0){
		if(cnt>best||(cnt==best&&price<Min_Price)){
			Min_Price=price;
			ans=temp;
			best=cnt;
		}
		return; 
	}
	for(int i=0;i<total;i++){
		if(cnt+total-i<best){
			return;
		}
		int u=Stack[idx][i];
		if(cnt+dp[u]<best){
			return;
		}
		int sz=0;
		for(int j=i+1;j<total;j++){
			int& v=Stack[idx][j];
			if(G[A[u]][A[v]]){
				Stack[idx+1][sz++]=v;
			}
		}
		temp.push_back(A[u]);
		DFS(idx+1,sz,cnt+1,price+Price[A[u]]);
		temp.pop_back();
	}
}
void Max_clique(){
	best=0;
	for(int i=N;i>0;i--){
		int sz=0;
		for(int j=i+1;j<=N;j++){
			if(G[A[i]][A[j]]){
				Stack[1][sz++]=j;
			}
		}
		temp.push_back(A[i]);
		DFS(1,sz,1,Price[A[i]]);
		temp.pop_back();
		dp[i]=best;
	}
}
int trans(int x){
	if(mp[x]==0){
		mp[x]=cnt++;	
		rmp[mp[x]]=x;
	}
	return mp[x];
}
int main() {
	std::ios::sync_with_stdio(false);
	fill(G[0],G[0]+maxn*maxn,1);
	cin>>M>>N;
	A.resize(N);
	for(int i=0;i<M;i++){
		int u,v;
		cin>>u>>v;
	//	u=trans(u);v=trans(v);
		G[u][v]=G[v][u]=0;
	}
	for(int i=1;i<=N;i++){
		int v;
		cin>>A[i]>>v;
	//	A[i]=trans(A[i]);
		Price[A[i]]=v;
	}
	Max_clique();
	sort(ans.begin(),ans.end());
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++){
		cout<<setw(3)<<setfill('0')<<ans[i]<<(i==ans.size()-1?"\n":" ");
	}
	cout<<Min_Price;
	return 0;
}
/*
16 20
001 002
003 004
004 005
005 006
006 007
007 008
008 003
009 010
009 011
009 012
009 013
010 014
011 015
012 016
012 017
013 018
020 99
019 99
018 4
017 2
016 3
015 6
014 5
013 1
012 1
011 1
010 1
009 10
008 1
007 2
006 5
005 3
004 4
003 6
002 1
001 2
*/
