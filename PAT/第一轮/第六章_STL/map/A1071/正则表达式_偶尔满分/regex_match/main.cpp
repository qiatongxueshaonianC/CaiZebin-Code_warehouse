#include<bits/stdc++.h>
using namespace std; 
int main() {
	unordered_map<string,int> mp;
	pair<string,int> ans("",0);
	string s;
	getline(cin,s);
	transform(s.begin(),s.end(),s.begin(),::tolower);
	regex r("[a-zA-Z0-9]+");
	for(sregex_iterator it(s.begin(),s.end(),r),end_it;it!=end_it;it++){
		if(mp.find(it->str())!=mp.end()) mp[it->str()]++;
		else mp[it->str()]=1;
	} 
	for(auto i:mp)
		if(i.second>ans.second) ans=i; 
	printf("%s %d\n",ans.first.c_str(),ans.second);
	return 0;
}
/*
Can1: "Can a can can a can?  It can!"
*/
