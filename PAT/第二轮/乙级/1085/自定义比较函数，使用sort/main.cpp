#include<bits/stdc++.h>
using namespace std; 
vector<pair<string,pair<double,int>>> ans;
bool cmp(int a,int b){
	auto u=ans[a],v=ans[b];
	if(u.second.first!=v.second.first)
		return u.second.first>v.second.first;
	else if(u.second.second!=v.second.second)
		return u.second<v.second;
	else return u.first<v.first;
}
int main() {
	map<string,pair<double,int>> mp; 
	int n,score;
	scanf("%d",&n);
	char id[10],school[10];
	while(n--){
		scanf("%s%d%s",&id,&score,&school);
		transform(school,school+10,school,::tolower);
		if(id[0]=='B')
			mp[school].first+=1.0*score/1.5;
		else if(id[0]=='A')
			mp[school].first+=score;
		else
			mp[school].first+=1.5*score;
		mp[school].second++;
	}
	for(auto& i:mp){
		i.second.first=floor(i.second.first);
		ans.push_back(i);	
	}
	int vis[ans.size()];
	iota(vis,vis+ans.size(),0);
	sort(vis,vis+ans.size(),cmp);
	printf("%d\n",ans.size());
	printf("1 %s %.0lf %d\n",ans[vis[0]].first.c_str(),ans[vis[0]].second.first,ans[vis[0]].second.second);
	int rank=1;
	for(int k=1;k<ans.size();k++){
		int i=vis[k];
		rank=ans[i].second.first<ans[vis[k-1]].second.first?k+1:rank;
		printf("%d %s %.0lf %d\n",rank,ans[i].first.c_str(),ans[i].second.first,ans[i].second.second);
	}
	return 0;
}
/*
10
A57908 85 Au
B57908 54 LanX
A37487 60 au
T28374 67 CMU
T32486 24 hypu
A66734 92 cmu
B76378 71 AU
A47780 45 lanx
A72809 100 pku
A03274 45 hypu

5
1 cmu 192 2
1 au 192 3
3 pku 100 1
4 hypu 81 2
4 lanx 81 2
*/
