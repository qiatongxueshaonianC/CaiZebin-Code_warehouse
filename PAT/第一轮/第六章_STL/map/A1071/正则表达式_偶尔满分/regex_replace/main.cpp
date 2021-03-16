#include<bits/stdc++.h>
using namespace std; 
int main() {
	string s;
	getline(cin,s);
	transform(s.begin(),s.end(),s.begin(),::tolower);
	regex r("[^a-zA-Z0-9]");
	s=regex_replace(s,r," ");
	unordered_map<string,int> mp;
	pair<string,int> ans("",0);
	stringstream str(s);
	while(str>>s){
		if(mp.find(s)!=mp.end()) mp[s]++;
		else mp[s]=1;
	/*	if(mp[s]>ans.second) {   //这么写时间复杂度高 
			ans.first=s;
			ans.second=mp[s];
		}*/ 
	}
	for(auto i:mp)
		if(i.second>ans.second) ans=i; 
	printf("%s %d\n",ans.first.c_str(),ans.second);
	return 0;
}
/*
Can1: "Can a can can a can?  It can!"
*/
