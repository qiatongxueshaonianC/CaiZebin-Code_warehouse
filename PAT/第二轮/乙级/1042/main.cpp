#include<bits/stdc++.h>
using namespace std; 
int main() {
	map<char,int> hash;
	pair<char,int> ans{' ',0};
	string s;
	getline(cin,s);
	transform(s.begin(),s.end(),s.begin(),::tolower);
	for(auto i:s){
		if(isalpha(i))
			hash[i]++;
	} 
	for(pair<char,int> i:hash)
		ans=i.second>ans.second?i:ans;
	printf("%c %d",ans.first,ans.second);
	return 0;
}
/*
This is a simple TEST.  There ARE numbers and other symbols 1&2&3...........
*/
