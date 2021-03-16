#include<bits/stdc++.h>
using namespace std;
int n,m,st,ed;
vector<int> G[10005],temp;
set<pair<int,int>> is_friend;
int main() {
	scanf("%d%d",&n,&m);
	string u,v;
	for(int i=0;i<m;i++){
		cin>>u>>v;
		int int_u=abs(stoi(u));
			int int_v=abs(stoi(v));
		if(u.size()==v.size()){
			G[int_u].push_back(int_v);
			G[int_v].push_back(int_u);
		}
		is_friend.insert({int_u,int_v});
		is_friend.insert({int_v,int_u});
	}
	scanf("%d",&m);
	while(m--){
		set<pair<int,int>> ans;
		scanf("%d%d",&st,&ed);
		st=abs(st),ed=abs(ed);
		for(auto i:G[st]){
			for(auto j:G[ed]){
				if(i==ed||j==st)
					continue;
				if(is_friend.find(make_pair(i,j))!=is_friend.end()){
					ans.insert({i,j});
				}
			}
		} 
		printf("%d\n",ans.size());
		for(auto i:ans)
			printf("%04d %04d\n",i.first,i.second);  //ע�⣬���������������������� 
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
