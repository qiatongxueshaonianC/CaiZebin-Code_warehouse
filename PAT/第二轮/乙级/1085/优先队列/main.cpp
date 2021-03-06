#include<bits/stdc++.h>
using namespace std; 
struct cmp{
	bool operator ()(const pair<string,pair<double,int>> u,const pair<string,pair<double,int>> v){
		if(u.second.first!=v.second.first)
			return u.second.first<v.second.first;
		else if(u.second.second!=v.second.second)
			return u.second>v.second;
		else return u.first>v.first;
	}
};
int main() {
	map<string,pair<double,int>> mp; 
	priority_queue<pair<string,pair<double,int>>,vector<pair<string,pair<double,int>>>,cmp> ans;
	int n,score;
	scanf("%d",&n);
	char id[10],school[10];
	while(n--){
		scanf("%s%d%s",&id,&score,&school);
		transform(school,school+10,school,::tolower);
		if(id[0]=='B')
			mp[school].first+=1.0*score/1.5;
		else if(id[0]=='A')
			mp[school].first+=1.0*score;
		else
			mp[school].first+=1.5*score;
		mp[school].second++;
	}
	for(auto& i:mp){
		i.second.first=floor(i.second.first);//2020/1/28/23:40???? 
		ans.push(i);
	}
	printf("%d\n",ans.size());
	int rank=1;
	double pre=0;
	while(!ans.empty()){
		auto i=ans.top();ans.pop();
		rank=i.second.first<pre?mp.size()-ans.size():rank;
		printf("%d %s %.0lf %d\n",rank,i.first.c_str(),i.second.first,i.second.second);
		pre=i.second.first;
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
*/
