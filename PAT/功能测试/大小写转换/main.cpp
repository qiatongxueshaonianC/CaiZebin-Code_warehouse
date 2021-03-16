#include<bits/stdc++.h>
using namespace std; 
char Tolower(char s){
	return ((!isupper(s))||(!isalpha(s)))?s:s-'A'+'a';
}
int main() {
	printf("%s\n",isupper(':')?"yes":"No");
	string s;
	getline(cin,s);
	cout<<s<<endl; 
	transform(s.begin(),s.end(),s.begin(),Tolower);
	cout<<s<<endl;
	regex r("[^a-zA-Z0-9]");
	s=regex_replace(s,r," ");
	cout<<s<<endl;
	unordered_map<string,int> mp;
	pair<string,int> ans("",0);
	stringstream str(s);
	while(str>>s){
		if(mp.find(s)!=mp.end()) mp[s]++;
		else mp[s]=1;
		if(mp[s]>ans.second) {
			ans.first=s;
			ans.second=mp[s];
		}
	}
	printf("%s %d\n",ans.first.c_str(),ans.second);
	return 0;
}
/*
Can1: "Can a can can a can?  It can!"
*/
