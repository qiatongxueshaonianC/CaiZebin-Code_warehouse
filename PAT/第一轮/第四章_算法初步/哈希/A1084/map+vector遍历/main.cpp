#include<bits/stdc++.h>
#include<list>
#include<algorithm>
using namespace std; 
int main() {
	string s;
	getline(cin,s);
	transform(s.begin(),s.end(),s.begin(),::toupper);
	vector<char> A;
	unordered_map<char,bool> mp;
	for(char i:s)
		if(mp.find(i)==mp.end()){
			A.push_back(i);
			mp[i]=1;
		}
	getline(cin,s);
	transform(s.begin(),s.end(),s.begin(),::toupper);
	for(auto i:s){
		auto it=mp.find(i);
		if(it!=mp.end())
			mp.erase(it);
	}
	for(auto i:A)
		if(mp[i]==true)
			printf("%c",i);
	return 0;
}
/*
7_This_is_a_test
_hs_s_a_es
*/
