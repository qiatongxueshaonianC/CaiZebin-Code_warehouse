#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
#include<map>
using namespace std; 
const int maxn=210;
vector<vector<int> >G(maxn);
map<string,int> mp;
int N,dp[maxn][2];
bool vis[maxn][2],unique[maxn][2]; 
void init(){
	mp.clear();
	fill(G.begin(),G.end(),vector<int>());
	memset(vis,false,sizeof(vis));
	memset(unique,true,sizeof(unique));
}
int DP(int now,bool father_go,int father){
	if(vis[now][father_go])
		return dp[now][father_go];
	vis[now][father_go]=true;
	int ans=0;
	for(auto i:G[now]){		//当前节点不去 
		if(i==father)
			continue;
		ans+=DP(i,false,now);
	}
	if(now==1)	//只有对于非根节点来说，dp[now][father_go]才有意义，根节点自身可以表示为：dp[root][root_go?] 
		dp[now][0]=ans;
	//当前点不去，子节点中若某个点去和不去的值都一样，那么不唯一
	//或者，在子节点去和不去的值不一样大，但是“值大”的那个点的决策不唯一，则当前也不唯一 
	for(auto i:G[now]){
		if(i==father)
			continue;
		if(dp[i][0]==dp[i][1]){
			unique[now][0]=false;
			break;
		}
		if(dp[i][0]>dp[i][1]&&unique[i][0]==false){
			unique[now][0]=false;
			break;
		}
		if(dp[i][0]<dp[i][1]&&unique[i][1]==false){
			unique[now][0]=false;
			break;
		}	 
	} 
	if(father_go==false){	//当前节点去：去的条件：上司没去 
		int sum=1;
		for(auto i:G[now]){
			if(i==father)
				continue;
			sum+=DP(i,true,now);
		} 
		if(now==1)
			dp[now][1]=sum;
		ans=max(ans,sum);
		//唯一性判断 
		for(auto i:G[now]){
			if(i==father)
				continue;
			if(unique[i][0]!=1){
				unique[now][1]=false;
				break;
			}
		}
	}
	if(now!=1)
		dp[now][father_go]=ans;
	return ans; 
}
int main() {
	std::ios::sync_with_stdio(false);
	while(cin>>N&&N){
		string s;
		int cnt=1;
		init(); 
		cin>>s;mp[s]=cnt++;	//root标号为1
		for(int i=0;i<N-1;i++){
			string s1,s2;
			cin>>s1>>s2;
			if(mp.find(s1)==mp.end()){
				mp[s1]=cnt++;
			}
			if(mp.find(s2)==mp.end())
				mp[s2]=cnt++;
			int u=mp[s1],v=mp[s2];
			G[u].push_back(v);
			G[v].push_back(u);
		} 
		int ans=DP(1,0,-1);
		if(dp[1][0]==dp[1][1])
			printf("%d No\n",ans);
		else if(dp[1][0]>dp[1][1])
			printf("%d %s\n",ans,unique[1][0]?"Yes":"No");
		else 
			printf("%d %s\n",ans,unique[1][1]?"Yes":"No");
	}
	return 0;
}
/*
6
Jason
Jack Jason
Joe Jack
Jill Jason
John Jack
Jim Jill
2
Ming
Cho Ming
0
*/
