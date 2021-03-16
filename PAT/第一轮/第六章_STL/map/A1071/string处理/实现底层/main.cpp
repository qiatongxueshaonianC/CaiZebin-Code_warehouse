#include<bits/stdc++.h>
using namespace std;
bool check(char& c){
	if('0'<=c&&c<='9') return true;
	if('a'<=c&&c<='z') return true;
	if('A'<=c&&c<='Z') {
		c=c+'a'-'A';
		return true;
	}
	return false;
} 
int main() {
	unordered_map<string,int> mp;
	pair<string,int> ans("",0);
	string s;
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		string word="";
		while(i<s.size()&&check(s[i])){
			word=word+s[i++];
		}
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
