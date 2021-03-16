#include<bits/stdc++.h>
using namespace std;
int n,m,st,ed;
vector<int> G[10005],temp;
//set<pair<int,int>> ans;
bool vis[10005];
void DFS(int s,int lev,set<pair<int,int>> &ans){
	if(s==ed){
		if(temp.size()!=3) return;
		int u=*++temp.begin(),v=*--temp.end();
		if(u*st>0) ans.insert({abs(u),abs(v)});
		else ans.insert({abs(v),abs(u)});
		return;
	}
	temp.push_back(s);
	vis[abs(s)]=true;
	if(lev+1<=3){
		for(auto i:G[abs(s)]){
			if(temp.size()==1&&st*i<0||temp.size()==3&&temp[2]*ed<0) continue;
			if(vis[abs(i)]==false) DFS(i,lev+1,ans);
		}
	}
	temp.pop_back();
	vis[abs(s)]=false;
}
int main() {
	scanf("%d%d",&n,&m);
	int u,v;
	for(int i=0;i<m;i++){
		scanf("%d%d",&u,&v);
		G[abs(u)].push_back(v);
		G[abs(v)].push_back(u);
	}
	scanf("%d",&m);
	while(m--){
		set<pair<int,int>> ans;
		scanf("%d%d",&st,&ed);
		DFS(st,0,ans);
		printf("%d\n",ans.size());
		for(auto i:ans)
			printf("%04d %04d\n",i.first,i.second);  //注意，今天在这里连续错了两次 
	}
	return 0;
}
/*
10 18
-2001 1001
-2002 -2001
1004 1001
-2004 -2001
-2003 1005
1005 -2001
1001 -2003
1002 1001
1002 -2004
-2004 1001
1003 -2002
-2003 1003
1004 -2002
-2001 -2003
1001 1003
1003 -2001
1002 -2001
-2002 -2003
5
1001 -2001
-2003 1001
1005 -2001
-2002 -2004
1111 -2003
*/
