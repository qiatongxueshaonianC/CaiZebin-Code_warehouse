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
	for(auto i:G[now]){		//��ǰ�ڵ㲻ȥ 
		if(i==father)
			continue;
		ans+=DP(i,false,now);
	}
	if(now==1)	//ֻ�ж��ڷǸ��ڵ���˵��dp[now][father_go]�������壬���ڵ�������Ա�ʾΪ��dp[root][root_go?] 
		dp[now][0]=ans;
	//��ǰ�㲻ȥ���ӽڵ�����ĳ����ȥ�Ͳ�ȥ��ֵ��һ������ô��Ψһ
	//���ߣ����ӽڵ�ȥ�Ͳ�ȥ��ֵ��һ���󣬵��ǡ�ֵ�󡱵��Ǹ���ľ��߲�Ψһ����ǰҲ��Ψһ 
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
	if(father_go==false){	//��ǰ�ڵ�ȥ��ȥ����������˾ûȥ 
		int sum=1;
		for(auto i:G[now]){
			if(i==father)
				continue;
			sum+=DP(i,true,now);
		} 
		if(now==1)
			dp[now][1]=sum;
		ans=max(ans,sum);
		//Ψһ���ж� 
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
		cin>>s;mp[s]=cnt++;	//root���Ϊ1
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
