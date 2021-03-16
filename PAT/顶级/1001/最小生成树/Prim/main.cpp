#include<bits/stdc++.h>
using namespace std; 
const int maxn=510;
int G[maxn][maxn],N,M;
int Prim(int occ){
	int d[maxn],vis[maxn]={false},st=1,cnt=0,cost=0;
	fill(d,d+maxn,INT_MAX);
	if(st==occ) st++;
	d[st]=0;
	for(int i=1;i<=N;i++){
		int u=-1,MIN=INT_MAX;
		for(int j=1;j<=N;j++){
			if(vis[j]==false&&d[j]<MIN){
				MIN=d[j];
				u=j;
			}
		}
		if(u==-1) break;
		vis[u]=true;
		cnt++;cost+=d[u];
		for(int k=1;k<=N;k++){
			if(k!=occ&&!vis[k]&&G[u][k]<d[k])
				d[k]=G[u][k];
		}
	} 
	return cnt==N-1?cost:INT_MAX;
}
void solve(){
	vector<pair<int,int>> ans(N);
	for(int i=1;i<=N;i++)
		ans[i-1]={Prim(i),i};
	sort(ans.begin(),ans.end(),[](const pair<int,int>& u,const pair<int,int>& v){
		return u.first!=v.first?u.first>v.first:u.second<v.second;
	});
	if(ans[0].first==0) 
		printf("0");
	else{
		printf("%d",ans[0].second);
		for(int i=1;i<ans.size();i++){
			if(ans[i].first==ans[0].first)
				printf(" %d",ans[i].second);
			else break;
		}	
	}
}
int main() {
	scanf("%d%d",&N,&M);
	fill(G[0],G[0]+maxn*maxn,INT_MAX);
	for(int i=0;i<M;i++){
		int a,b,cost,d;
		scanf("%d%d%d%d",&a,&b,&cost,&d);
		if(d==0)
			G[a][b]=G[b][a]=cost;
		else
			G[a][b]=G[b][a]=0;
	}
	solve();
	return 0;
}
/*
4 5
1 2 1 1
1 3 1 1
2 3 1 0
2 4 1 1
3 4 1 0

4 5
1 2 1 1
1 3 1 1
2 3 1 0
2 4 1 1
3 4 2 1
*/
