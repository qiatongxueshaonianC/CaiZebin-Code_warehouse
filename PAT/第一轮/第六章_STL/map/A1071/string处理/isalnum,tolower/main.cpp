#include<bits/stdc++.h>
using namespace std;
int main() {
	unordered_map<string,int> mp;
	pair<string,int> ans("",0);
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		string word="";
		while(i<s.size()&&isalnum(s[i]))
			word+=tolower(s[i++]);   //不知道为什么这里只能用+= 
		if(word!=""){
			if(mp.find(word)!=mp.end()) mp[word]++;
			else mp[word]=1;
		}
	}
	for(auto i:mp)
		if(i.second>ans.second) ans=i;
	printf("%s %d\n",ans.first.c_str(),ans.second);
	return 0;
}
/*
Can1: "Can a can can a can?  It can!"
*/
