#include<bits/stdc++.h>
using namespace std; 
unordered_map<int,string> mp={{0,"ling"},{1,"yi"},{2,"er"},{3,"san"},{4,"si"},{5,"wu"},
								{6,"liu"},{7,"qi"},{8,"ba"},{9,"jiu"}};
int main() {
	string s;
	getline(cin,s);
	int ans=0;
	for(auto i:s){
		ans+=i-'0';
	}
	s=to_string(ans);
	for(int i=0;i<s.size();i++)
		printf("%s%s",mp[s[i]-'0'].c_str(),i==s.size()-1?"":" ");
	return 0;
}
/*
1234567890987654321123456789
*/
